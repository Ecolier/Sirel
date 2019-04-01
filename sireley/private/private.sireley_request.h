#ifndef SRL_PLATFORM_REQUEST_H
#define SRL_PLATFORM_REQUEST_H

struct SRL_Platform_Request;

struct SRL_Request {
  struct SRL_Request_Attributes *attributes_;
  struct SRL_Platform_Request   *platform_request_;
};

#endif // SRL_PLATFORM_REQUEST_H
