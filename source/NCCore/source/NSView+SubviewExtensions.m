//
//  NSView+SubviewExtensions.m
//  NCCore
//
//  Created by Simon Strandgaard on 25/04/10.
//  Copyright 2010 opcoders.com. All rights reserved.
//

#import "NSView+SubviewExtensions.h"


@implementation NSView (SubviewExtensions)

-(void)addResizedSubview:(NSView*)aView {
	NSRect vframe = [aView frame];
	[aView setAutoresizingMask:NSViewWidthSizable | NSViewHeightSizable];

	NSView* tmp_superview = [[[NSView alloc] initWithFrame:vframe] autorelease];
	[tmp_superview addSubview:aView];
	[tmp_superview setAutoresizesSubviews:YES];
	[tmp_superview setFrame:[self frame]];
	
	[aView removeFromSuperview];
    [self addSubview:aView];
}

-(void)replaceSubviewsWithView:(NSView*)aView {
	for(NSView* subview in [self subviews]) {
		if(subview == aView) {
			// the view is already installed, no need to do anything
			return;
		}
	    [subview removeFromSuperview];
	}
	[self addSubview: aView];
	[aView setFrame: [self bounds]];
	
}


@end
