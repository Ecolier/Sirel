#ifndef SRL_HTTP_PRIVATE_REQUEST_H
#define SRL_HTTP_PRIVATE_REQUEST_H

#include "core/request.h"

struct SRL_Http_Request {
  struct SRL_Request        *base_request_;
  struct SRL_Native_Request *native_request_;
};

#endif // SRL_HTTP_PRIVATE_REQUEST_H
