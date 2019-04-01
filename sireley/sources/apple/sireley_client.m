#include <apple.sireley_client.h>
#include <Foundation/Foundation.h>

#include <platform/platform.sireley_request.h>
#include "apple.sireley_request.h"

void SRL_Platform_fetch(struct SRL_Request *request, SRL_Response_Callback callback) {
  NSURLSession *session = [NSURLSession sharedSession];
  NSURLSessionDataTask *task = [session dataTaskWithRequest: request->platform_request_->r
  completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
  callback(0);
}];
  [task resume];
}