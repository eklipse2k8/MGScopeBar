//
//  MGScopeBarDelegateProtocol.h
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


// Selection modes for the buttons within a group.
typedef enum _MGScopeBarGroupSelectionMode {
    MGRadioSelectionMode         = 0,	// Exactly one item in the group will be selected at a time (no more, and no less).
    MGMultipleSelectionMode      = 1	// Any number of items in the group (including none) may be selected at a time.
} MGScopeBarGroupSelectionMode;


@class MGScopeBar;
@protocol MGScopeBarDelegate


// Methods used to configure the scope bar.
// Note: all groupNumber parameters are zero-based.

@required
- (int)numberOfGroupsInScopeBar:(MGScopeBar *)theScopeBar;
- (NSArray *)scopeBar:(MGScopeBar *)theScopeBar itemIdentifiersForGroup:(int)groupNumber;
- (NSString *)scopeBar:(MGScopeBar *)theScopeBar labelForGroup:(int)groupNumber; // return nil or an empty string for no label.
- (MGScopeBarGroupSelectionMode)scopeBar:(MGScopeBar *)theScopeBar selectionModeForGroup:(int)groupNumber;
- (NSString *)scopeBar:(MGScopeBar *)theScopeBar titleOfItem:(NSString *)identifier inGroup:(int)groupNumber;

@optional
// If the following method is not implemented, all groups except the first will have a separator before them.
- (BOOL)scopeBar:(MGScopeBar *)theScopeBar showSeparatorBeforeGroup:(int)groupNumber;
- (NSImage *)scopeBar:(MGScopeBar *)theScopeBar imageForItem:(NSString *)identifier inGroup:(int)groupNumber; // default is no image. Will be shown at 16x16.
- (NSView *)accessoryViewForScopeBar:(MGScopeBar *)theScopeBar; // default is no accessory view.


// Notification methods.

@optional
- (void)scopeBar:(MGScopeBar *)theScopeBar selectedStateChanged:(BOOL)selected forItem:(NSString *)identifier inGroup:(int)groupNumber;


@end
