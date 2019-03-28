#include <string.h>
#include <stdlib.h>
#include <Foundation/Foundation.h>

#include "../rest-client.h"
#include "platform.h"

struct REST_Request {
  struct REST_Request_Attributes *attributes_;
  REST_Native_Request *native_request_;
};

void REST_Request_create(const char *url, unsigned int url_length,
    unsigned int method, struct REST_Request **request) {
  struct REST_Request *req = *request;
  req->native_request_ = malloc(sizeof(req->native_request_));
  REST_Request_Platform_create(url, url_length, method, &req->native_request_);
}

void REST_Request_get_attributes(struct REST_Request *request, struct REST_Request_Attributes **attributes) {

}

void REST_fetch(struct REST_Request *request, REST_Response_Callback callback) {
  REST_Platform_fetch(request->native_request_, callback);
}

void REST_Request_get_native_object(struct REST_Request *request, REST_Native_Request *native_request) {
  native_request = request->native_request_;
}

/**
void REST_Request_create(const char *url, unsigned int url_length, const char *method, struct REST_Request *request) {
  request = malloc(sizeof(request));
  REST_Request_set_url(request, url, url_length);

}

void REST_Request_set_url(struct REST_Request *request, const char *url, unsigned int url_length) {
  request->url = malloc(url_length);
  request->url_length = url_length;
  memcpy((void *)request->url, url, url_length);
}

void REST_Request_set_body(struct REST_Request *request, const char *body) {
  request->body_size = strlen(body);
  request->body = malloc(request->body_size);
  memcpy((void *)request->body, body, request->body_size);
} **/