#import <Foundation/Foundation.h>
#import <rest-client.h>
#import "rest-classes.h"
#include "../platform.h"

void REST_Request_Platform_create(const char *url, unsigned int url_length,
    unsigned int method, REST_Native_Request **native_request) {

  NSString *url_str = [[NSString alloc]
      initWithData:[[[NSData alloc] initWithBytes:url length:url_length] autorelease]
          encoding: NSUTF8StringEncoding];
  NSURL *native_url = [[NSURL alloc] initWithString:url_str];
  *native_request = [[REST_Native_Request alloc] initWithURL:native_url];

  /*
   * TODO: find a more elegant way to handle method types
   */
  NSString *method_str = @"GET";
  switch (method) {
    case REST_METHOD_GET:
      method_str = @"GET";
      break;
    case REST_METHOD_POST:
      method_str = @"POST";
      break;
    case REST_METHOD_PUT:
      method_str = @"PUT";
      break;
    case REST_METHOD_UPDATE:
      method_str = @"UPDATE";
      break;
    default: break;
  }

  (*native_request).HTTPMethod = method_str;

  [url_str release];
  [native_url release];
}

void REST_Request_get_content(struct REST_Request *request, char *content, unsigned int content_size) {

}

void REST_Request_set_header(struct REST_Request *request, const char *header, const char *header_size) {

}

void REST_Request_set_url(struct REST_Request *request, const char *url, unsigned int url_length) {

}

void REST_Request_set_content(struct REST_Request *request, const char *content, unsigned int content_size) {

}

void REST_Platform_fetch(REST_Native_Request *native_request, REST_Response_Callback callback) {
  NSURLSession *session = [NSURLSession sharedSession];
  NSURLSessionDataTask *task = [session dataTaskWithRequest: native_request
             completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
    callback(0);
  }];
  [task resume];
}


/**

void REST_get(const char *url, unsigned int url_length,
    struct REST_Request *request, REST_HandleResponse callback) {

  /**NSString *ns_url = [[NSString alloc] initWithData:[[NSData alloc] initWithBytes:url length:url_length]
                      encoding: NSUTF8StringEncoding];

  struct REST_Request* request = malloc(sizeof(request));
  request_provider->make_request(url, url_length, request);



  NSURLSession *session = [[NSURLSession alloc] init];
  NSURL *session_url = [[NSURL alloc] initWithString:ns_url];

  NSURLRequest *request = [provider make:session_url];

  [session dataTaskWithRequest:request
             completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
               [_delegate queryDidComplete:data :response :error];
             }];

  [session release];
  [session_url release];
}

@implementation RestBaseController

- (id)init {
  if (self = [super init]) {
    self.delegate = nil;
  }
  return self;
}

- fetch:(NSString *)url :(id<RestRequestProvider>)provider {

  NSURLSession *session = [[NSURLSession alloc] init];
  NSURL *session_url = [[NSURL alloc] initWithString:url];
  NSURLRequest *request = [provider make:session_url];
  [session dataTaskWithRequest:request
             completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
               [_delegate queryDidComplete:data :response :error];
  }];

  [session release];
  [session_url release];
}

@end**/