#import <Foundation/Foundation.h>
#import "sirel_request_apple.h"

NSData *bytes_to_data(const void* bytes, size_t bytes_length) {
  return [[NSData alloc] initWithBytes:bytes length:bytes_length];
}

NSString *c_string_to_ns_string(const char* str, size_t len) {
    return [[NSString alloc] initWithData:bytes_to_data(str, len) encoding:NSUTF8StringEncoding];
}

void SRL_Request_create(const char *url, size_t url_length, struct SRL_Request **request) {
  NSMutableURLRequest *native_request =
      [[NSMutableURLRequest alloc] initWithURL:[[NSURL alloc] initWithString:c_string_to_ns_string(url,
                                                                                         url_length)]];

  struct SRL_Request *ret = malloc(sizeof(ret));
  ret->private_ = malloc(sizeof(ret->private_));
  ret->private_->request_ = native_request;
  *request = ret;
}

void SRL_Request_set_method(struct SRL_Request *request, const char *method, size_t method_length) {
  [request->private_->request_ setHTTPMethod:c_string_to_ns_string(method, method_length)];
}

void SRL_Request_set_data(struct SRL_Request *request, const char *data, size_t data_length) {
  [request->private_->request_ setHTTPBody:bytes_to_data(data, data_length)];
}