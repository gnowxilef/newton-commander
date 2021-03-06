//
//  NCFileEventManager.h
//  NCCore
//
//  Created by Simon Strandgaard on 24/04/10.
//  Copyright 2010 opcoders.com. All rights reserved.
//

#import <Foundation/Foundation.h>

// NCFileEventManagerPrivate is defined in the implementation file
typedef struct NCFileEventManagerPrivate NCFileEventManagerPrivate;

@interface NCFileEventManager : NSObject {
	id m_delegate;
	NCFileEventManagerPrivate* m_private;
	NSArray* m_paths_to_watch;
	BOOL m_is_running;
}
-(void)setDelegate:(id)delegate;

-(void)start;
-(void)stop;

-(void)notify:(NSArray*)ary;

-(void)setPathsToWatch:(NSArray*)paths;
@end


@interface NSObject (NCFileEventManagerDelegate)

-(void)fileEventManager:(NCFileEventManager*)fileEventManager changeOccured:(NSArray*)ary;

@end