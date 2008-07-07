//
//  BUTSTableViewManager.m
//  Bring up the Subject
//
//  Created by Jonathon Mah on 2008-07-03.
//  Copyright 2008 Playhaus. All rights reserved.
//

#import "BUTSTableViewManager.h"


@implementation BUTSTableViewManager


- (id)tableView:(NSTableView *)tableView objectValueForTableColumn:(NSTableColumn *)tableColumn row:(NSInteger)rowIndex;
{
	id value = [super tableView:tableView objectValueForTableColumn:tableColumn row:rowIndex];
	if ([value isKindOfClass:[NSAttributedString class]] && [[tableColumn identifier] isEqual:@"2"])
	{
		// Subject
		NSMutableAttributedString *boldString = [[value mutableCopy] autorelease];
		NSFont *font = [value attribute:NSFontAttributeName atIndex:0 effectiveRange:NULL];
		NSFont *boldFont = [[NSFontManager sharedFontManager] convertFont:font toHaveTrait:NSBoldFontMask];
		[boldString addAttribute:NSFontAttributeName value:boldFont range:NSMakeRange(0, [boldString length])];
		
		//value = boldString;
	}
	return value;
}


@end
