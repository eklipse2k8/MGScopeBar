//
//  MGRecessedPopUpButtonCell.m
//  MGScopeBar
//
//  Copyright (c) 2008 Matt Gemmell
//  All rights reserved.
//  
//  Redistribution and use in source and binary forms, with or without 
//  modification, are permitted provided that the following conditions are met:
//  
//    Redistributions of source code must retain the above copyright notice, 
//    this list of conditions and the following disclaimer.
//
//    Redistributions in binary form must reproduce the above copyright notice, 
//    this list of conditions and the following disclaimer in the documentation 
//    and/or other materials provided with the distribution.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
//  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
//  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
//  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR 
//  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
//  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
//  OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
//  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
//  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
//  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//  

#import "MGRecessedPopUpButtonCell.h"


@implementation MGRecessedPopUpButtonCell


- (id)initTextCell:(NSString *)title pullsDown:(BOOL)pullsDown
{
	if ((self = [super initTextCell:title pullsDown:pullsDown])) {
		recessedButton = [[NSButton alloc] initWithFrame:NSMakeRect(0, 0, 30, 20)]; // arbitrary frame.
		[recessedButton setTitle:@""];
		[recessedButton setBezelStyle:NSRecessedBezelStyle];
		[recessedButton setButtonType:NSPushOnPushOffButton];
		[[recessedButton cell] setHighlightsBy:NSCellIsBordered | NSCellIsInsetButton];
		[recessedButton setShowsBorderOnlyWhileMouseInside:NO];
		[recessedButton setState:NSOnState]; // ensures it looks pushed-in.
	}
	return self;
}


- (void)dealloc
{
	[recessedButton release];
	[super dealloc];
}


- (void)drawTitleWithFrame:(NSRect)cellFrame inView:(NSView *)controlView
{
	// Inset title rect since its position is broken when NSPopUpButton
	// isn't using its selected item as its title.
	NSRect titleFrame = cellFrame;
	titleFrame.origin.y += 1.0;
	[super drawTitleWithFrame:titleFrame inView:controlView];
}


- (void)drawBezelWithFrame:(NSRect)frame inView:(NSView *)controlView
{
	[recessedButton setFrame:frame];
	[recessedButton drawRect:frame];
}


@end
