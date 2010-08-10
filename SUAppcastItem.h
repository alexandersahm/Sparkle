//
//  SUAppcastItem.h
//  Sparkle
//
//  Created by Andy Matuschak on 3/12/06.
//  Copyright 2006 Andy Matuschak. All rights reserved.
//

#ifndef SUAPPCASTITEM_H
#define SUAPPCASTITEM_H

@class SUAppcast;

@interface SUAppcastItem : NSObject
{
@private
	NSString *title;
	NSDate *date;
	NSString *itemDescription;
	
	NSURL *releaseNotesURL;
	
	NSString *DSASignature;	
	NSString *minimumSystemVersion;
	
	NSURL *fileURL;
	NSString *versionString;
	NSString *displayVersionString;

	NSDictionary *deltaUpdates;

	NSDictionary *propertiesDictionary;
	
	//the appcast this item is contained by
	SUAppcast *appcast;
}

// Initializes with data from a dictionary provided by the RSS class.
- initWithDictionary:(NSDictionary *)dict;
- initWithDictionary:(NSDictionary *)dict failureReason:(NSString**)error;
- initWithDictionary:(NSDictionary *)dict appcast:(SUAppcast *)theAppcast failureReason:(NSString**)error;

- (NSString *)title;
- (NSString *)versionString;
- (NSString *)displayVersionString;
- (NSDate *)date;
- (NSString *)itemDescription;
- (NSURL *)releaseNotesURL;
- (NSURL *)fileURL;
- (NSString *)DSASignature;
- (NSString *)minimumSystemVersion;
- (NSDictionary *)deltaUpdates;
- (BOOL)isDeltaUpdate;

// Returns the dictionary provided in initWithDictionary; this might be useful later for extensions.
- (NSDictionary *)propertiesDictionary;

- (SUAppcast *)appcast;

@end

#endif
