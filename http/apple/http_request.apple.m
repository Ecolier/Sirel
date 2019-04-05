#import <Foundation/Foundation.h>
#import "http_request.apple.h"
#import "http_request.h"

NSData *bytes_to_data(const void* bytes, size_t bytes_length) {
  return [[NSData alloc] initWithBytes:bytes length:bytes_length];
}

NSString *c_string_to_ns_string(const char* str, size_t len) {
    return [[NSString alloc] initWithData:bytes_to_data(str, len) encoding:NSUTF8StringEncoding];
}

void SRL_create_http_request(const char *url, size_t url_length, struct SRL_Http_Request **request) {
  NSMutableURLRequest *native_request =
      [[NSMutableURLRequest alloc] initWithURL:[[NSURL alloc] initWithString:c_string_to_ns_string(url,
                                                                                         url_length)]];

  struct SRL_Http_Request *ret = malloc(sizeof(ret));
  ret->base_request_ = malloc(sizeof(ret->base_request_));
  ret->native_request_ = malloc(sizeof(ret->native_request_));
  ret->native_request_->managed_request_ = malloc(sizeof(ret->native_request_->managed_request_));
  ret->native_request_->managed_request_ = native_request;
  *request = ret;
}

void SRL_set_http_request_method(struct SRL_Http_Request *request, const char *method, size_t method_length) {
  [request->native_request_->managed_request_ setHTTPMethod:c_string_to_ns_string(method, method_length)];
}

void SRL_set_http_request_body(struct SRL_Http_Request *request, const char *data, size_t data_length) {
  [request->native_request_->managed_request_ setHTTPBody:bytes_to_data(data, data_length)];
}

void SRL_send_http_request(struct SRL_Http_Request *request, SRL_Send_Callback callback) {
  NSMutableURLRequest *req = request->native_request_->managed_request_;
  NSURLSession *shared = [NSURLSession sharedSession];
  NSURLSessionDataTask *task = [shared dataTaskWithRequest:req completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
    callback();
  }];
  [task resume];
}

void SRL_destroy_http_request(struct SRL_Http_Request *request) {

}
