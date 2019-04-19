#import "apple_http_request.h"
#import "http_request.h"

NSDictionary *error_codes() {
  NSMutableDictionary *errors = [[NSMutableDictionary alloc] init];
  [errors setObject:@CANNOT_CONNECT_TO_HOST forKey:[NSNumber numberWithInt:NSURLErrorCannotConnectToHost]];
  return errors;
}

NSData *bytes_to_data(const void* bytes, size_t bytes_length) {
  return [[NSData alloc] initWithBytes:bytes length:bytes_length];
}

NSString *c_string_to_ns_string(const char* str, size_t len) {
    return [[NSString alloc] initWithData:bytes_to_data(str, len) encoding:NSUTF8StringEncoding];
}

void create_http_request(
    HTTPRequest http_details,
    struct url_request_t **request) {
  (*request)->native_request = [[NSMutableURLRequest alloc] initWithURL:[
      [NSURL alloc] initWithString:c_string_to_ns_string(http_details.url, http_details.url_length)]];
  [(*request)->native_request setHTTPMethod:c_string_to_ns_string(http_details.method, http_details.method_length)];
}

void send_http_request(struct url_request_t *request, handle_http_response completion, void *user) {
  NSMutableURLRequest *req = request->native_request;
  NSURLSession *shared = [NSURLSession sharedSession];
  NSURLSessionDataTask *task = [shared dataTaskWithRequest:req completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {

    // Fill out the response struct
    HTTPResponse resp;
    NSHTTPURLResponse *http_url_response = (NSHTTPURLResponse *)response;
    resp.status_code = (int)http_url_response.statusCode;

    // Deal with internal errors
    NSDictionary *errors = error_codes();
    NSNumber *code = [NSNumber numberWithInt:[error code]];
    NSNumber *errorcode = errors[code];

    completion(request, resp, data.bytes, data.length, errorcode, user);
  }];
  [task resume];
}

void destroy_http_request(struct url_request_t *request) {
  [request->native_request release];
  free(request);
}

void set_http_url(struct url_request_t *request, const char *url, size_t url_length) {
  [request->native_request setURL:[[NSURL alloc] initWithString:c_string_to_ns_string(url, url_length)]];
}

void set_http_method(struct url_request_t *request, const char *method, size_t method_length) {
  [request->native_request setHTTPMethod:c_string_to_ns_string(method, method_length)];
}

void set_http_body(struct url_request_t *request, const char *body, size_t body_length) {
  [request->native_request setHTTPBody:bytes_to_data(body, body_length)];
}