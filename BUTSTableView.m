//
//  BUTSTableView.m
//  Bring up the Subject
//
//  Created by Jonathon Mah on 2008-07-03.
//  Copyright 2008 Playhaus. All rights reserved.
//

#import "BUTSTableView.h"


@implementation BUTSTableView


static BOOL returnDoubleRowHeight = NO;


- (BOOL)BUTS_isAlterableTableView;
{
	// Test if we're the main table view in a more hacky way, because the window structure may not be hooked up yet
	return [[self delegate] isKindOfClass:[TableViewManager class]];
	// return self == [[self.window.delegate tableManager] tableView]
}


- (NSRect)rectOfRow:(NSInteger)rowIndex;
{
	NSRect rect = [super rectOfRow:rowIndex];
	if ([self BUTS_isAlterableTableView])
	{
		rect.origin.y += rowIndex * (rect.size.height - self.intercellSpacing.height);
		rect.size.height *= 2.0f;
		rect.size.height -= self.intercellSpacing.height;
	}
	return rect;
}


- (NSInteger)rowAtPoint:(NSPoint)point;
{
	if ([self BUTS_isAlterableTableView])
	{
		returnDoubleRowHeight = YES;
		NSInteger row = [super rowAtPoint:point];
		returnDoubleRowHeight = NO;
		return row;
	}
	else
		return [super rowAtPoint:point];
}


- (CGFloat)rowHeight;
{
	CGFloat height = [super rowHeight];
	if ([self BUTS_isAlterableTableView])
		if (returnDoubleRowHeight)
			height *= 2.0f;
	return height;
}


- (NSRect)frameOfCellAtColumn:(NSInteger)columnIndex row:(NSInteger)rowIndex;
{
	NSRect rect = [super frameOfCellAtColumn:columnIndex row:rowIndex];
	if ([self BUTS_isAlterableTableView])
	{
		// Drop most cells
		rect.size.height /= 2.0f;
		rect.origin.y += rect.size.height;
		
		CGFloat intercellWidth = self.intercellSpacing.width;
		
		NSTableColumn *subjectColumn = [self tableColumnWithIdentifier:@"2"];
		NSUInteger subjectColumnIndex = [[self tableColumns] indexOfObject:subjectColumn];
		if (columnIndex < subjectColumnIndex)
			// Vertically center cells before subject
			rect.origin.y -= rect.size.height / 2.0f;
		else if (columnIndex == subjectColumnIndex)
		{
			rect.origin.y -= rect.size.height;
			rect.size.width = self.bounds.size.width - rect.origin.x - intercellWidth;
		}
	}
	return rect;
}


- (void)drawRect:(NSRect)rect;
{
	[super drawRect:rect];
	
	// Draw grid ourselves, because [self setGridStyle:] doesn't work for me (works for a combination with vertical, but not horizontal)
	if ([self BUTS_isAlterableTableView])
	{
		returnDoubleRowHeight = YES;
		CGFloat rowHeight = [self rowHeight];
		returnDoubleRowHeight = NO;
		
		CGFloat intercellHeight = self.intercellSpacing.height;
		
		NSUInteger minRow = NSMinY(rect) / (rowHeight + intercellHeight);
		NSUInteger maxRow = NSMaxY(rect) / (rowHeight + intercellHeight);
		
		NSRect gridLine = NSMakeRect(NSMinX([self bounds]), 0.0f,
									 NSWidth([self bounds]), intercellHeight);
		
		[[self gridColor] set];
		for (NSUInteger i = minRow; i <= maxRow; i++)
		{
			gridLine.origin.y = i * (rowHeight + intercellHeight) + rowHeight;
			NSRectFill(gridLine);
		}
	}
}


- (void)awakeFromNib;
{
	[super awakeFromNib];
	if (([self BUTS_isAlterableTableView]))
		// Decrease the minimum width of the subject column
		[[self tableColumnWithIdentifier:@"2"] setMinWidth:12.0f];
}


@end
