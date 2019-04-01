#ifndef SIREL_APPLE_REQUEST_H
#define SIREL_APPLE_REQUEST_H

#include <Foundation/NSURLRequest.h>
#include "private/sirel_request_private.h"

struct SRL_Request_Private {
  NSMutableURLRequest *request_;
};

#endif // SIREL_APPLE_REQUEST_H
