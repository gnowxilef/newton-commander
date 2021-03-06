/*
IDEA: rename from NCMakeDirController to NCCreateItemSheet, where item can be: dir, file, link, file from template
IDEA: merge with NCMakeFileController
IDEA: merge with NCMakeLinkController
*/
//
//  NCMakeDirController.h
//  NCCore
//
//  Created by Simon Strandgaard on 24/04/10.
//  Copyright 2010 opcoders.com. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface NCMakeDirController : NSWindowController {
	id m_delegate;
	IBOutlet NSTextField* m_textfield;
	NSString* m_working_dir;
	NSString* m_suggest_name;          
}
@property (assign) IBOutlet id delegate;
@property(nonatomic, retain) NSString* suggestName;
@property(nonatomic, retain) NSString* workingDir;
+(NCMakeDirController*)shared;

-(void)beginSheetForWindow:(NSWindow*)parentWindow;

-(IBAction)cancelAction:(id)sender;
-(IBAction)submitAction:(id)sender;
-(IBAction)textAction:(id)sender;

@end

@interface NSObject (NCMakeDirControllerDelegate)
-(void)makeDirController:(NCMakeDirController*)ctrl didMakeDir:(NSString*)path;
@end