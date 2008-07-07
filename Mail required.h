//
//  Mail required.h
//  Bring up the Subject
//
//  Created by Jonathon Mah on 2008-07-03.
//  Copyright 2008 Playhaus. All rights reserved.
//

#import <Cocoa/Cocoa.h>



@interface MVMailBundle : NSObject
{
}

+ (id)allBundles;
+ (id)composeAccessoryViewOwners;
+ (void)registerBundle;
+ (id)sharedInstance;
+ (BOOL)hasPreferencesPanel;
+ (id)preferencesOwnerClassName;
+ (id)preferencesPanelName;
+ (BOOL)hasComposeAccessoryViewOwner;
+ (id)composeAccessoryViewOwnerClassName;

@end


@interface ASExtendedTableView : NSTableView
{
    struct {
        unsigned int delegateScrolls:1;
        unsigned int delegateProvidesDragImage:1;
        unsigned int delegateProvidesSourceDraggingMask:1;
        unsigned int delegateDoesCommandBySelector:1;
        unsigned int delegateDragWillEnd:1;
        unsigned int delegateDragWillEndOperation:1;
        unsigned int delegateDraggedImageMovedTo:1;
        unsigned int delegateProvidesBackgroundColor:1;
        unsigned int delegateProvidesBackgroundShadedRegions:1;
        unsigned int alwaysKeepColumnsSizedToFitAvailableSpace:1;
        unsigned int delegateProvidesColumnsToPinInPlace:1;
        unsigned int delegateProvidesHighlightStyle:1;
        unsigned int delegateProvidesHighlightColor:1;
        unsigned int delegateRespondsToWillDrawRowsInRange:1;
        unsigned int delegateRespondsToDidDrawRowsInRange:1;
        unsigned int delegateApprovesScrolling:1;
        unsigned int delegateRespondsToGotEvent:1;
        unsigned int delegateRespondsToShouldBeginDrag:1;
        unsigned int delegateRespondsToWillResizeColumnsToFit:1;
        unsigned int delegateRespondsToDidResizeColumnsToFit:1;
        unsigned int delegateRespondsToWillMoveToWindow:1;
        unsigned int delegateRespondsToDidMoveToWindow:1;
        unsigned int delegateRespondsToDidEndLiveResize:1;
    } _extendedTableViewFlags;
    BOOL _didLazyLoadMenu;
}

- (BOOL)_wantsLiveResizeToUseCachedImage;
- (void)viewDidEndLiveResize;
- (void)keyDown:(id)fp8;
- (void)setDelegate:(id)fp8;
- (id)menu;
- (NSRange)completelyVisibleRowsCapacity:(int *)fp8;
- (void)stopObservingViewBoundsChange:(id)fp8;
- (void)startObservingViewBoundsChange:(id)fp8;
- (void)viewWillMoveToSuperview:(id)fp8;
- (void)asetvSuperviewBoundsChanged:(id)fp8;
- (void)showTableColumnsFromArray:(id)fp8 allColumns:(id)fp12;
- (id)getPersistentTableColumnsAsArray;
- (void)scrollRowToVisible:(int)fp8;
- (void)setTableColumn:(id)fp8 toVisible:(BOOL)fp12 atPosition:(int)fp16;
- (void)moveColumn:(int)fp8 toColumn:(int)fp12;
- (void)setAlwaysKeepColumnsSizedToFitAvailableSpace:(BOOL)fp8;
- (BOOL)alwaysKeepColumnsSizedToFitAvailableSpace;
- (float)totalWidthOfAllColumns;
- (int)numberOfColumnsToPinToLefthandSide;
- (void)betterSizeToFit;
- (void)sizeToFit;
- (id)dragImageForRowsWithIndexes:(id)fp8 tableColumns:(id)fp12 event:(id)fp16 offset:(NSPoint *)fp20;
- (void)draggedImage:(id)fp8 endedAt:(NSPoint)fp12 operation:(unsigned int)fp20;
- (void)draggedImage:(id)fp8 movedTo:(NSPoint)fp12;
- (BOOL)shouldUseSecondaryHighlightColor;
- (id)_highlightColorForCell:(id)fp8;
- (void)drawBackgroundInClipRect:(NSRect)fp8;
- (void)drawRect:(NSRect)fp8;
- (void)drawRow:(int)fp8 clipRect:(NSRect)fp12;
- (NSRect)cellFrameForPaddedRect:(NSRect)fp8;
- (NSRect)paddedRectForCellFrame:(NSRect)fp8;

@end


@protocol MVSelectionOwner
- (id)selection;
- (void)selectMessages:(id)fp8;
- (id)currentDisplayedMessage;
- (id)messageStore;
- (BOOL)transferSelectionToMailbox:(id)fp8 deleteOriginals:(BOOL)fp12;
@end


@protocol MessageBrowserController <NSObject, MVSelectionOwner>
- (id)messageBrowserView;
- (BOOL)isSelectionVisible;
- (void)showSelectionAndCenter:(BOOL)fp8;
- (void)updateTextViewerToSelection;
- (id)messagesToTransfer;
- (void)willTransferMessages:(id)fp8 toMailbox:(id)fp12 deleteOriginals:(BOOL)fp16;
- (void)transfer:(id)fp8 didCompleteWithError:(id)fp12;
- (id)messageToSelectIfEntireSelectionRemoved;
- (void)selectNextMessage:(BOOL)fp8;
- (void)selectPreviousMessage:(BOOL)fp8;
- (void)selectNextMessageMovingDownward:(BOOL)fp8;
- (void)selectNextMessageMovingUpward:(BOOL)fp8;
- (BOOL)includeDeleted;
- (void)setIncludeDeleted:(BOOL)fp8;
- (BOOL)shouldDeleteGivenCurrentState;
- (void)deleteSelectionAllowingMoveToTrash:(BOOL)fp8;
- (void)deleteMessages:(id)fp8 allowMoveToTrash:(BOOL)fp12 allowUndo:(BOOL)fp16;
- (void)undeleteMessagesAllowingUndo:(BOOL)fp8;
- (void)undeleteMessages:(id)fp8 allowUndo:(BOOL)fp12;
@end


@interface TableViewManager : NSObject <MessageBrowserController>
{
    ASExtendedTableView *_tableView;
    void *_messageMall;
    id _delegate;
    NSArray *_tableColumns;
    NSFont *_font;
    NSFont *_boldFont;
    NSFont *_noteFont;
    NSMutableArray *_selection;
    NSArray *_selectionExcludingThreads;
    BOOL _suspendChangesToScrollingAndSelection;
    void *_currentDisplayedMessage;
    NSMapTable *_storeStateTable;
    NSMutableArray *_draggedMessages;
    NSMutableAttributedString *_truncatedString;
    NSMutableDictionary *_truncatedStringAttributes;
    NSMutableDictionary *_truncatedParagraphStyle;
    NSString *_availableStatusImageName;
    int leftmostTextColumn;
    struct {
        unsigned int includeDeleted:1;
        unsigned int isFocused:1;
        unsigned int sortColumnOrderAscending:1;
        unsigned int isShowingSearchResults:1;
        unsigned int sortColumnOrder:8;
        unsigned int hasScrolledSinceMailboxChange:1;
        unsigned int userChangedSelectionSinceMailboxChange:1;
        unsigned int threadOpeningIsInProgress:1;
        unsigned int threadClosingIsInProgress:1;
        unsigned int doubleClickThreadOpeningIsInProgress:1;
        unsigned int animatingThreadOpening:1;
        unsigned int animatingThreadClosing:1;
        unsigned int animateInSlowMotion:1;
        unsigned int dontUpdateTrackingRects:1;
        unsigned int dontReadWriteStoreSpecificDefaultsToMailbox:1;
        unsigned int useBoldFontForUnreadMessages:1;
        unsigned int clearingSearch:1;
        unsigned int changingSelection:1;
        unsigned int selectionShouldNotChange:1;
        unsigned int searchSortColumnOrder:8;
        unsigned int searchSortColumnOrderAscending:1;
    } _flags;
    NSDictionary *_messageIDsToSelectWhenOpened;
    NSArray *_threadIDsToOpenWhenOpened;
    int colorHighlightLeftEdge;
    int colorHighlightWidth;
    int _windowWidthBeforeSearch;
    void *_visibleStateBeforeSearch;
    void *_messagesInSelectedThread;
    void *threadBeingClosed;
    void *threadBeingOpened;
    struct __CFDictionary *_rowDrawingCache;
    NSMutableSet *_mouseTrackers;
    struct _NSPoint _lastMouseDownInUnreadColumnPoint;
    int _lastMouseDownInUnreadColumnEventNumber;
    struct _NSPoint _currentMouseLocationInWindow;
    float _amountToScrollDownAfterClosingThread;
    int _numberOfSelectedRowsBeforeTogglingThread;
    int _selectedRowBeforeTogglingThread;
    BOOL _unreadColumnResizableAfterResizingColumnsToFit;
    void *_bytesFormatter;
    BOOL _isDragging;
}

+ (void)initialize;
- (void)awakeFromNib;
- (id)tableViewGetDefaultMenu:(id)fp8;
- (id)_bytesFormatter;
- (void)_setBytesFormatter:(id)fp8;
- (void)tableViewScrolled:(id)fp8;
- (void)_setupColumnHeaderIcon:(id)fp8 inColumnWithIdentifier:(id)fp12 accessibilityTitle:(id)fp16 alignment:(unsigned int)fp20;
- (void)_setupTableColumnWidths;
- (void)_configureColumnForEndTruncation:(id)fp8;
- (void)_configureColumnForImageCell:(id)fp8 alignment:(unsigned int)fp12;
- (void)_configureColumnForRolloverCell:(id)fp8 alignment:(unsigned int)fp12 action:(SEL)fp16;
- (void)showFollowupsToMessage:(id)fp8;
- (void)showFollowupsToMessageAtRow:(int)fp8;
- (void)_setupColumnsForTableView;
- (void)dealloc;
- (void)windowWillClose:(id)fp8;
- (id)delegate;
- (void)setDelegate:(id)fp8;
- (void)setMessageMall:(id)fp8;
- (void)messagesUpdated:(id)fp8;
- (void)readDefaultsFromDictionary:(id)fp8;
- (void)writeDefaultsToDictionary:(id)fp8;
- (void)setDontReadWriteStoreSpecificDefaultsToMailbox:(BOOL)fp8;
- (void)writeStoreSpecificDefaultsToMailboxUid:(id)fp8;
- (void)readStoreSpecificDefaultsFromMailboxUid:(id)fp8;
- (void)readStoreSpecificDefaultsFromDictionary:(id)fp8;
- (BOOL)canSelectNextMessage;
- (BOOL)canSelectPreviousMessage;
- (void)rulePreferencesChanged:(id)fp8;
- (void)viewerPreferencesChanged:(id)fp8;
- (BOOL)threadHasSelectedMessages:(id)fp8;
- (void)presencePreferenceChanged:(id)fp8;
- (void)threadColorPreferenceChanged:(id)fp8;
- (void)presenceImageChanged:(id)fp8;
- (void)presenceChanged:(id)fp8;
- (void)_updateTableHeaderToMatchCurrentSort;
- (void)tableView:(id)fp8 didClickTableColumn:(id)fp12;
- (id)_columnWithIdentifierTag:(int)fp8;
- (id)_unreadColumn;
- (BOOL)isColumnVisible:(int)fp8;
- (void)setColumn:(int)fp8 toVisible:(BOOL)fp12;
- (void)_setColumn:(int)fp8 toVisible:(BOOL)fp12;
- (int)tableViewNumberOfColumnsToPinToLefthandSide:(id)fp8;
- (void)selectAllMessagesAndMakeFirstResponder;
- (void)makeMessageListFirstResponder;
- (void)updateTableViewRowHeight;
- (void)setFont:(id)fp8;
- (void)setNoteFont:(id)fp8;
- (BOOL)isInThreadedMode;
- (void)toggleThreadedMode;
- (void)threadedModeDidChange:(id)fp8;
- (void)_invalidateSelectionExcludingThreads;
- (BOOL)openThreadAtIndex:(int)fp8 andSelectMessage:(id)fp12 animate:(BOOL)fp16;
- (BOOL)closeThreadAtIndex:(int)fp8 focusRow:(int)fp12 animate:(BOOL)fp16;
- (void)openAllThreads;
- (void)closeAllThreads;
- (void)toggleThread:(id)fp8;
- (void)toggleThread:(id)fp8 ignoreModifierKeys:(BOOL)fp12;
- (int)_indexOfMessageNearest:(int)fp8 numberOfRows:(int)fp12 threaded:(BOOL)fp16 downward:(BOOL)fp20;
- (BOOL)canSelectPreviousThreadedMessage;
- (BOOL)canSelectNextThreadedMessage;
- (BOOL)canSelectParentOfMessage;
- (BOOL)canSelectFirstReplyToMessage;
- (BOOL)canSelectNextReplyToParent;
- (BOOL)selectionIsExactlyOneOpenThread;
- (void)selectNextMessageMovingDownward:(BOOL)fp8;
- (void)selectNextMessageMovingUpward:(BOOL)fp8;
- (BOOL)stepIntoSelectedThread;
- (BOOL)stepOutOfSelectedThread;
- (BOOL)openSelectedThread;
- (void)selectNextMessage:(BOOL)fp8;
- (void)selectPreviousMessage:(BOOL)fp8;
- (void)selectParentOfMessage;
- (void)selectFirstReplyToMessage;
- (void)selectPeer:(BOOL)fp8;
- (void)selectNextReplyToParent;
- (void)selectPreviousReplyToParent;
- (void)showSelectionAndCenter:(BOOL)fp8;
- (BOOL)isSelectionVisible;
- (void)scrollRowToVisible:(int)fp8 position:(int)fp12;
- (int)tableView:(id)fp8 shouldScrollRowToVisible:(int)fp12;
- (BOOL)_isMessageInSelectedThread:(id)fp8;
- (void)_setNeedsDisplayForMessagesInSet:(id)fp8 highlightOnly:(BOOL)fp12;
- (void)_setNeedsDisplayThreadColumnForMessagesInSet:(id)fp8;
- (void)_updateSelectedThreadList;
- (id)selectedThread;
- (void)_reallyUpdateTextViewerToSelection;
- (void)updateTextViewerToSelection;
- (BOOL)tableView:(id)fp8 shouldSelectRow:(int)fp12 byExtendingSelection:(BOOL)fp16;
- (void)selectionIsChanging:(id)fp8;
- (void)_selectOrDeselectMembersOfThread:(id)fp8 atIndex:(int)fp12 select:(BOOL)fp16;
- (void)selectionChanged:(id)fp8;
- (void)datesNeedRedisplay;
- (int)numberOfRowsInTableView:(id)fp8;
- (id)_attributesForTruncatedParagraphStyle;
- (id)_colorForMessage:(id)fp8 inRow:(int)fp12;
- (id)_truncatedAttributedStringForString:(id)fp8 message:(id)fp12 row:(int)fp16 shouldIndent:(BOOL)fp20;
- (id)_attributedUpdatedStringForRSSMessage:(id)fp8 row:(int)fp12;
- (id)tableView:(id)fp8 typeSelectStringForTableColumn:(id)fp12 row:(int)fp16;
- (BOOL)tableView:(id)fp8 shouldTypeSelectForEvent:(id)fp12 withCurrentSearchString:(id)fp16;
- (id)tableView:(id)fp8 objectValueForTableColumn:(id)fp12 row:(int)fp16;
- (void)_updateColorHighlightEdges;
- (void)tableView:(id)fp8 didDragTableColumn:(id)fp12;
- (void)tableViewDidEndLiveResize:(id)fp8;
- (void)tableViewColumnDidMove:(id)fp8;
- (void)tableViewColumnDidResize:(id)fp8;
- (void)tableView:(id)fp8 willDisplayCell:(id)fp12 forTableColumn:(id)fp16 row:(int)fp20;
- (id)tableViewHighlightColor:(id)fp8;
- (int)tableView:(id)fp8 highlightStyleForRow:(int)fp12 inRect:(NSRect *)fp16 color:(id *)fp20;
- (void)doubleClickedMessage:(id)fp8;
- (void)deleteKeyPressed;
- (void)deleteSelectionAllowingMoveToTrash:(BOOL)fp8;
- (id)selectionIncludingThreads:(BOOL)fp8;
- (id)selection;
- (void)_selectMessages:(id)fp8 scrollIfNeeded:(BOOL)fp12;
- (void)selectMessages:(id)fp8;
- (id)currentDisplayedMessage;
- (void)setCurrentDisplayedMessage:(id)fp8;
- (id)messageStore;
- (id)orderOfFromSubjectDateColumns;
- (id)tableView;
- (BOOL)tableView:(id)fp8 doCommandBySelector:(SEL)fp12;
- (id)_undoActionNameForMessageCount:(unsigned int)fp8;
- (void)selectMessagesForUndo:(id)fp8;
- (void)_undeleteMessages:(id)fp8 allowUndo:(BOOL)fp12 unreadMessages:(id)fp16;
- (void)undeleteMessages:(id)fp8 allowUndo:(BOOL)fp12;
- (void)_redeleteMessages:(id)fp8 messagesToSelect:(id)fp12;
- (void)deleteMessages:(id)fp8 allowMoveToTrash:(BOOL)fp12 allowUndo:(BOOL)fp16;
- (void)undeleteMessagesAllowingUndo:(BOOL)fp8;
- (BOOL)shouldDeleteGivenCurrentState;
- (void)tableViewDraggedImage:(id)fp8 movedTo:(NSPoint)fp12;
- (unsigned int)tableView:(id)fp8 draggingSourceOperationMaskForLocal:(BOOL)fp12;
- (id)messagesToTransfer;
- (void)willTransferMessages:(id)fp8 toMailbox:(id)fp12 deleteOriginals:(BOOL)fp16;
- (void)transfer:(id)fp8 didCompleteWithError:(id)fp12;
- (BOOL)transferSelectionToMailbox:(id)fp8 deleteOriginals:(BOOL)fp12;
- (void)tableViewDragWillEnd:(id)fp8 operation:(unsigned int)fp12;
- (BOOL)tableView:(id)fp8 writeRowsWithIndexes:(id)fp12 toPasteboard:(id)fp16;
- (void)pasteboard:(id)fp8 provideDataForType:(id)fp12;
- (id)tableView:(id)fp8 namesOfPromisedFilesDroppedAtDestination:(id)fp12 forDraggedRowsWithIndexes:(id)fp16;
- (id)_dragImageForRow:(int)fp8 event:(id)fp12 dragImageOffset:(NSPoint *)fp16;
- (id)tableView:(id)fp8 dragImageForRowsWithIndexes:(id)fp12 event:(id)fp16 dragImageOffset:(NSPoint *)fp20;
- (void)tableView:(id)fp8 willDrawRowsInRange:(NSRange)fp12;
- (void)tableView:(id)fp8 didDrawRowsInRange:(NSRange)fp12;
- (NSRect)frameOfClickedCell;
- (NSPoint)mouseLocationInWindow;
- (void)callWillDisplayCellForClickedCell;
- (void)setButtonCellNeedsDisplay;
- (void)tableView:(id)fp8 gotEvent:(id)fp12;
- (BOOL)shouldTrackMouse:(id)fp8;
- (id)tableView:(id)fp8 rangesForBackgroundShadingInRange:(NSRange)fp12 shadingColors:(id *)fp20 leftColumnColors:(id *)fp24;
- (id)messageMall;
- (int)_indexOfFirstNonDeletedNonSelectedMessage:(int)fp8 withinRowRange:(NSRange)fp12 goUp:(BOOL)fp20;
- (id)messageBrowserView;
- (id)messageToSelectIfEntireSelectionRemoved;
- (BOOL)includeDeleted;
- (void)setIncludeDeleted:(BOOL)fp8;
- (id)noteFont;
- (id)boldFont;
- (void)setBoldFont:(id)fp8;
- (id)font;
- (id)draggedMessages;
- (void)setDraggedMessages:(id)fp8;

@end


@protocol MessageContentDisplay <NSObject>
+ (id)copyDocumentForMessage:(id)fp8 viewingState:(id)fp12;
- (id)contentView;
- (id)textView;
- (void)display:(id)fp8 inContainerView:(id)fp12 replacingView:(id)fp16 invokeWhenDisplayChanged:(id)fp20;
- (void)prepareToRemoveView;
- (void)highlightSearchText:(id)fp8;
- (id)selectedText;
- (id)selectedTextRepresentation;
- (void)setSelectedTextRepresentation:(id)fp8;
- (id)selectedWebArchive;
- (id)attachmentsInSelection;
- (id)webArchiveBaseURL:(id *)fp8;
- (void)adjustFontSizeBy:(int)fp8 viewingState:(id)fp12;
- (id)findTarget;
- (struct __CFDictionary *)stringsForURLification;
- (void)updateURLMatches:(id)fp8 viewingState:(id)fp12;
- (void)detectDataInMessage:(id)fp8 usingContext:(id)fp12;
- (id)delegate;
- (void)setDelegate:(id)fp8;
@end


@interface ThreadDisplay : NSObject <MessageContentDisplay>
{
    NSView *contentView;
    NSTextField *subjectField;
    NSTextField *originatorField;
    NSTextField *countsField;
    ASExtendedTableView *summaryTable;
    void *_thread;
    NSMutableArray *_messages;
    NSMutableDictionary *_attributes;
    float _deltaY;
    unsigned int _currentRow:16;
    unsigned int _enterCount:16;
    struct __CFSet *_trackingRectTags;
}

+ (id)copyDocumentForMessage:(id)fp8 viewingState:(id)fp12;
- (void)awakeFromNib;
- (void)dealloc;
- (id)contentView;
- (id)textView;
- (void)_resetTrackingRectsForTableView:(id)fp8;
- (void)_adjustViewHeightsIncludingRoundedView:(BOOL)fp8;
- (void)_adjustColumnsBasedOnTableManager:(id)fp8;
- (BOOL)_updateFlagsColumnWidth;
- (BOOL)_updateContentsColumnWidth;
- (void)_updateFlagsColumnWidth:(BOOL)fp8 updateContentsColumn:(BOOL)fp12;
- (void)_reloadMessages;
- (void)_mallStructureChanged:(id)fp8;
- (void)_messageFlagsChanged:(id)fp8;
- (void)_mallSortChanged:(id)fp8;
- (void)_tableSuperviewFrameChanged:(id)fp8;
- (void)_tableViewScrolled:(id)fp8;
- (void)_datesNeedRedisplay;
- (void)_windowDidBecomeKey:(id)fp8;
- (void)_windowDidResignKey:(id)fp8;
- (void)display:(id)fp8 inContainerView:(id)fp12 replacingView:(id)fp16 invokeWhenDisplayChanged:(id)fp20;
- (void)prepareToRemoveView;
- (void)highlightSearchText:(id)fp8;
- (id)selectedTextRepresentation;
- (void)setSelectedTextRepresentation:(id)fp8;
- (id)selectedText;
- (id)delegate;
- (void)setDelegate:(id)fp8;
- (id)selectedWebArchive;
- (id)attachmentsInSelection;
- (id)webArchiveBaseURL:(id *)fp8;
- (void)adjustFontSizeBy:(int)fp8 viewingState:(id)fp12;
- (id)findTarget;
- (struct __CFDictionary *)stringsForURLification;
- (void)updateURLMatches:(id)fp8 viewingState:(id)fp12;
- (void)detectDataInMessage:(id)fp8 usingContext:(id)fp12;
- (id)_colorForMessage:(id)fp8;
- (int)numberOfRowsInTableView:(id)fp8;
- (id)tableView:(id)fp8 objectValueForTableColumn:(id)fp12 row:(int)fp16;
- (void)tableView:(id)fp8 willDisplayCell:(id)fp12 forTableColumn:(id)fp16 row:(int)fp20;
- (BOOL)tableView:(id)fp8 shouldSelectRow:(int)fp12;
- (void)_updateCurrentRow:(id)fp8;
- (void)mouseEntered:(id)fp8;
- (void)mouseExited:(id)fp8;
- (void)tableView:(id)fp8 willMoveToWindow:(id)fp12;
- (void)tableViewDidMoveToWindow:(id)fp8;

@end


@interface NSObject (BUTSOtherMailMethods)

- (id)tableManager;

@end
