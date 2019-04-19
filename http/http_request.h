#ifndef SIREL_HTTP_REQUEST_H
#define SIREL_HTTP_REQUEST_H

#include <stddef.h>

#define CANNOT_CONNECT_TO_HOST 0x101

struct url_request_t;

typedef struct http_request_t {
  const char *url;
  size_t url_length;
  const char *method;
  size_t method_length;
} HTTPRequest;

typedef struct http_response_t {
    int status_code;
} HTTPResponse;

typedef int(*handle_http_response)(
    struct url_request_t *request,
    HTTPResponse response,
    const void *data,
    size_t data_length,
    unsigned int error,
    void *user);

void create_http_request(HTTPRequest http_details, struct url_request_t **url_request);
void send_http_request(struct url_request_t *url_request, handle_http_response callback, void *user);
void destroy_http_request(struct url_request_t *url_request);

void set_http_url(struct url_request_t *request, const char *url, size_t url_length);
void set_http_method(struct url_request_t *request, const char *method, size_t method_length);
void set_http_body(struct url_request_t *request, const char *body, size_t data_length);

#define MAKE_HTTP_REQUEST(url, method, request) \
HTTPRequest req = { url, strlen(url), method, strlen(method) };\
create_http_request(req, request);

#endif // SIREL_HTTP_REQUEST_H
