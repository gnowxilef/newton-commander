//
//  daemonize.m
//  NCWorkerChild
//
//  Created by Simon Strandgaard on 30/05/10.
//  Copyright 2010 opcoders.com. All rights reserved.
//

#import "daemonize.h"


void close_stdout_stderr_stdin() {
// #define DEBUG_STDERR
#ifdef DEBUG_STDERR
	fprintf(stderr, "stderr - now you see me\n");
	fflush(stderr);
	fprintf(stdout, "stdout - now you see me\n");
	fflush(stdout);
#endif	

	int i;
	
	// close all open descriptors.
	for(i=getdtablesize(); i>=0; --i)
	  close(i);

	// reopen STDIN, STDOUT, STDERR to /dev/null.
	i=open("/dev/null", O_RDWR); // STDIN
	dup(i); // STDOUT
	dup(i); // STDERR

#ifdef DEBUG_STDERR
	fprintf(stderr, "stderr - now you dont\n");
	fflush(stderr);
	fprintf(stdout, "stdout - now you dont\n");
	fflush(stdout);
#endif	
}


