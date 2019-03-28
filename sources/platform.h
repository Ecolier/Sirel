//
// Created by Evan Gruère on 2019-03-27.
//

#ifndef REST_CLIENT_PLATFORM_H
#define REST_CLIENT_PLATFORM_H

#include <rest-client.h>

#ifdef __APPLE__
#import <Foundation/NSURLRequest.h>
typedef NSMutableURLRequest REST_Native_Request;
#endif

/**
 * retrieve the managed native request from a platform-independent object
 * @param request
 * @param native_request
 */
void REST_Request_Platform_get_object(struct REST_Request *request, REST_Native_Request *native_request);
void REST_Request_Platform_create(const char *url, unsigned int url_length, unsigned int method, REST_Native_Request **native_request);

void REST_Platform_fetch(REST_Native_Request *native_request, REST_Response_Callback callback);

#endif // REST_CLIENT_PLATFORM_H
