#ifndef SIRELEY_APPLE_REQUEST_H
#define SIRELEY_APPLE_REQUEST_H

#include <Foundation/NSURLRequest.h>
#include "private/private.sireley_request.h"

struct SRL_Request_Private {
  NSMutableURLRequest *request_;
};

#endif // SIRELEY_APPLE_REQUEST_H
