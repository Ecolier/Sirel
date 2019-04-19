#ifndef SIREL_HTTP_APPLE_REQUEST_H
#define SIREL_HTTP_APPLE_REQUEST_H

#import <Foundation/Foundation.h>

typedef struct url_request_t {
  NSMutableURLRequest *native_request;
} URLRequest;

#endif // SIREL_HTTP_APPLE_REQUEST_H
