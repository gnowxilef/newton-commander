//
//  NCWorkerParent.h
//  NCWorker
//
//  Created by Simon Strandgaard on 08/06/10.
//  Copyright 2010 opcoders.com. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@class NCWorker;
@class NCWorkerThread;


@protocol NCWorkerController

-(void)worker:(NCWorker*)worker response:(NSDictionary*)dict;

@end

@interface NCWorker : NSObject {
	id m_controller;
	NSString* m_label;
	NCWorkerThread* m_thread;
	NSString* m_identifier;
	int m_uid;
}
-(id)initWithController:(id<NCWorkerController>)controller label:(NSString*)label;

-(void)setUid:(int)uid;
-(void)resetUid;

-(void)start;   
-(void)restart;

-(void)request:(NSDictionary*)dict;

/*
TODO: transaction id.. how?
TODO: kill task
*/
@end
