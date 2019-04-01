#import <Foundation/Foundation.h>
#import <sireley.h>

#import "apple.sireley_types.h"
#import "platform/sireley_request.platform.h"
#import "platform/sireley_client.platform.h"
#import "sireley_client.h"

void SRL_Request_Platform_create(const char *url, unsigned int url_length,
    unsigned int method, SRL_Native_Request **native_request) {

  NSString *url_str = [[NSString alloc]
      initWithData:[[[NSData alloc] initWithBytes:url length:url_length] autorelease]
          encoding: NSUTF8StringEncoding];
  NSURL *native_url = [[NSURL alloc] initWithString:url_str];
  *native_request = [[SRL_Native_Request alloc] initWithURL:native_url];

  /*
   * TODO: find a more elegant way to handle method types
   */
  NSString *method_str = @"GET";
  switch (method) {
    case SRL_METHOD_GET:
      method_str = @"GET";
      break;
    case SRL_METHOD_POST:
      method_str = @"POST";
      break;
    case SRL_METHOD_PUT:
      method_str = @"PUT";
      break;
    case SRL_METHOD_UPDATE:
      method_str = @"UPDATE";
      break;
    default: break;
  }

  (*native_request).HTTPMethod = method_str;

  [url_str release];
  [native_url release];
}

void SRL_Platform_fetch(SRL_Native_Request *native_request, SRL_Response_Callback callback) {
  NSURLSession *session = [NSURLSession sharedSession];
  NSURLSessionDataTask *task = [session dataTaskWithRequest: native_request
             completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
    callback(0);
  }];
  [task resume];
}

void SRL_Request_Platform_get_attributes(SRL_Native_Request *request, struct SRL_Request_Attributes **attributes) {
  struct SRL_Request_Attributes *attrs = *attributes;

  NSString *url = [[request URL] absoluteString];

  attrs->url_length = [url length];
  attrs->url = malloc(attrs->url_length);
  strcpy(attrs->url, [url UTF8String]);
}

void SRL_Request_Platform_set_attributes(SRL_Native_Request *request, struct SRL_Request_Attributes *attributes) {

}