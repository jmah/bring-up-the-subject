//
//  BUTSTableView.m
//  Bring up the Subject
//
//  Created by Jonathon Mah on 2008-07-03.
//  Copyright 2008 Playhaus. All rights reserved.
//

#import "BUTSTableView.h"


@implementation BUTSTableView


- (BOOL)BUTS_isAlterableTableView;
{
	// Test if we're the main table view in a more hacky way, because the window structure may not be hooked up yet
	return [[self delegate] isKindOfClass:[TableViewManager class]];
	// return self == [[self.window.delegate tableManager] tableView]
}


- (CGFloat)rowHeight;
{
	CGFloat height = [super rowHeight];
	if ([self BUTS_isAlterableTableView])
		return height * 2.0f;
	else if ([[self delegate] isKindOfClass:[ThreadDisplay class]])
		// Thread display table view seems to take its height from the main table view, so it should be halved to bring it back to normal
		return height / 2.0f;
	else
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
		CGFloat rowHeight = [self rowHeight];
		
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
