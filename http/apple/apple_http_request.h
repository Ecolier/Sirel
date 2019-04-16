#ifndef SIREL_HTTP_APPLE_REQUEST_H
#define SIREL_HTTP_APPLE_REQUEST_H

#include "http/http_request.h"
#import <Foundation/Foundation.h>

typedef struct url_request_t {
  NSMutableURLRequest *native_request;
} Url_Request;

#endif // SIREL_HTTP_APPLE_REQUEST_H
