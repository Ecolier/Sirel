#ifndef SIREL_APPLE_REQUEST_H
#define SIREL_APPLE_REQUEST_H

#import "private/http_request.private.h"
#import <Foundation/NSURLRequest.h>

struct SRL_Native_Request {
  NSMutableURLRequest *managed_request_;
};

#endif // SIREL_APPLE_REQUEST_H
