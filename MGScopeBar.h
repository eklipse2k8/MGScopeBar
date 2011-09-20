//
//  MGScopeBar.h
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

#import <Cocoa/Cocoa.h>
#import "MGScopeBarDelegateProtocol.h"

@interface MGScopeBar : NSView {
@private
	IBOutlet id <MGScopeBarDelegate, NSObject> delegate; // weak ref.
	NSMutableArray *_separatorPositions; // x-coords of separators, indexed by their group-number.
	NSMutableArray *_groups; // groups of items.
	NSView *_accessoryView; // weak ref since it's a subview.
	NSMutableDictionary *_identifiers; // map of identifiers to items.
	NSMutableArray *_selectedItems; // all selected items in all groups; see note below.
	float _lastWidth; // previous width of view from when we last resized.
	NSInteger _firstCollapsedGroup; // index of first group collapsed into a popup.
	float _totalGroupsWidthForPopups; // total width needed to show all groups expanded (excluding padding and accessory).
	float _totalGroupsWidth; // total width needed to show all groups as native-width popups (excluding padding and accessory).
	BOOL _smartResizeEnabled; // whether to do our clever collapsing/expanding of buttons when resizing (Smart Resizing).
}

@property(nonatomic, assign) id delegate; // should implement the MGScopeBarDelegate protocol.

- (void)reloadData; // causes the scope-bar to reload all groups/items from its delegate.
- (void)sizeToFit; // only resizes vertically to optimum height; does not affect width.
- (void)adjustSubviews; // performs Smart Resizing if enabled. You should only need to call this yourself if you change the width of the accessoryView.

// Smart Resize is the intelligent conversion of button-groups into NSPopUpButtons and vice-versa, based on available space.
// This functionality is enabled (YES) by default. Changing this setting will automatically call -reloadData.
- (BOOL)smartResizeEnabled;
- (void)setSmartResizeEnabled:(BOOL)enabled;

// The following method must be used to manage selections in the scope-bar; do not attempt to manipulate buttons etc directly.
- (void)setSelected:(BOOL)selected forItem:(NSString *)identifier inGroup:(NSInteger)groupNumber;
- (NSArray *)selectedItems;
/*
 Note:	The -selectedItems method returns an array of arrays.
		Each index in the returned array represents the group of items at that index.
		The contents of each sub-array are the identifiers of each selected item in that group.
		Sub-arrays may be empty, but will always be present (i.e. you will always find an NSArray).
		Depending on the group's selection-mode, sub-arrays may contain zero, one or many identifiers.
		The identifiers in each sub-array are not in any particular order.
 */

- (BOOL) isItemSelectedWithIdentifier:(NSString*)identifier inGroup:(NSInteger)groupNumber;

@end
