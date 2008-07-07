//
//  BUTSBundle.m
//  Bring up the Subject
//
//  Created by Jonathon Mah on 2008-07-03.
//  Copyright 2008 Playhaus. All rights reserved.
//

#import "BUTSBundle.h"
#import "BUTSTableView.h"


@implementation BUTSBundle


+ (void)initialize;
{
	[BUTSTableView poseAsClass:[ASExtendedTableView class]];
}


@end
