#ifndef SIREL_APPLE_REQUEST_H
#define SIREL_APPLE_REQUEST_H

#include <Foundation/NSURLRequest.h>
#include "private/http_request.private.h"

struct SRL_Native_Request {
  NSMutableURLRequest *managed_request_;
};

#endif // SIREL_APPLE_REQUEST_H
