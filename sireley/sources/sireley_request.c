#include <Foundation/Foundation.h>
#include <string.h>
#include <stdlib.h>

#include "platform/sireley_request.platform.h"
#include "sireley_request.h"

struct SRL_Request {
  struct SRL_Request_Attributes *attributes_;
  SRL_Native_Request *native_request_;
};

void SRL_Request_create(const char *url, unsigned int url_length, unsigned int method, struct SRL_Request **request) {
  struct SRL_Request *req = *request;
  req->native_request_ = malloc(sizeof(req->native_request_));
  SRL_Request_Platform_create(url, url_length, method, &req->native_request_);
}

void SRL_Request_get_attributes(struct SRL_Request *request, struct SRL_Request_Attributes **attributes) {

}

void SRL_fetch(struct SRL_Request *request, SRL_Response_Callback callback) {
  SRL_Platform_fetch(request->native_request_, callback);
}

void SRL_Request_get_native_object(struct SRL_Request *request, SRL_Native_Request *native_request) {
  native_request = request->native_request_;
}