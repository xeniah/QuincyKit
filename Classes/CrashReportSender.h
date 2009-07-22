/*
 * Author: Andreas Linde <mail@andreaslinde.de>
 *         Kent Sutherland
 *
 * Copyright (c) 2009 Andreas Linde & Kent Sutherland. All rights reserved.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#import <Foundation/Foundation.h>

extern NSString *AutomaticallySendCrashReports;
extern NSString *CrashReportActivated;

typedef enum CrashAlertType {
	CrashAlertTypeSend = 0,
	CrashAlertTypeFeedback = 1,
} CrashAlertType;

typedef enum CrashReportStatus {
	CrashReportStatusFailure = -1,
	CrashReportStatusUnknown = 0,
	CrashReportStatusAssigned = 1,
	CrashReportStatusSubmitted = 2,
	CrashReportStatusAvailable = 3,
} CrashReportStatus;

@interface CrashReportSender : NSObject {
	NSTimer *_submitTimer;
	
	NSMutableString *_contentOfProperty;
	CrashReportStatus _serverResult;
	
	BOOL _crashReportActivated;
	BOOL _crashReportFeedbackActivated;
	
	int _crashReportAnalyzerStarted;
	NSString *_crashesDir;
	
	int _amountCrashes;
	BOOL _crashIdenticalCurrentVersion;
	
	NSMutableArray *_crashFiles;
	
	NSURL *_submissionURL;
	NSMutableData *_responseData;
	NSInteger _statusCode;
}

+ (CrashReportSender *)sharedCrashReportSender;

- (BOOL)hasPendingCrashReport;

- (void)scheduleCrashReportSubmissionToURL:(NSURL *)submissionURL activateFeedback:(BOOL)activateFeedback;

@end
