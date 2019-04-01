#import <Foundation/Foundation.h>
#import "sirel_request_apple.h"

NSString *str_to_ns(const char* str, size_t len) {
  return [[[NSString alloc] initWithData:
      [[[NSData alloc] initWithBytes:str length:len] autorelease]
                                encoding:NSUTF8StringEncoding] autorelease];
}

void SRL_Request_create(const char *url, size_t url_length, struct SRL_Request **request) {
  NSMutableURLRequest *native_request =
      [[[NSMutableURLRequest alloc] initWithURL:[[[NSURL alloc] initWithString:str_to_ns(url,
                                                                                         url_length)] autorelease]] autorelease];

  struct SRL_Request *ret = malloc(sizeof(ret));
  ret->private_ = malloc(sizeof(ret->private_));
  ret->private_->request_ = native_request;
  *request = ret;
}