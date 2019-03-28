//
// Created by Evan Gruère on 2019-03-27.
//

#ifndef SRL_CLIENT_PLATFORM_H
#define SRL_CLIENT_PLATFORM_H

#include "../sireley_request.h"

#ifdef __APPLE__
#import <Foundation/Foundation.h>
typedef NSMutableURLRequest SRL_Native_Request;
#endif

/**
 * retrieve the managed native request from a platform-independent object
 * @param request
 * @param native_request
 */
void SRL_Request_Platform_get_object(struct SRL_Request *request, SRL_Native_Request *native_request);
void SRL_Request_Platform_create(const char *url, unsigned int url_length, unsigned int method, SRL_Native_Request **native_request);

void SRL_Platform_fetch(SRL_Native_Request *native_request, SRL_Response_Callback callback);

#endif // SRL_CLIENT_PLATFORM_H
