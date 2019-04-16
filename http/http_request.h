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
} HTTP_Request;

typedef struct http_response_t {
    int status_code;
} HTTP_Response;

typedef void(*received_http_response)(
    struct url_request_t *request,
    HTTP_Response response,
    const void *data,
    size_t data_length,
    unsigned int error);

void create_http_request(HTTP_Request http_details, struct url_request_t **url_request);
void send_http_request(struct url_request_t *url_request, received_http_response callback);
void destroy_http_request(struct url_request_t *url_request);

void set_http_url(struct url_request_t *request, const char *url, size_t url_length);
void set_http_method(struct url_request_t *request, const char *method, size_t method_length);
void set_http_body(struct url_request_t *request, const char *body, size_t data_length);

#define MAKE_HTTP_REQUEST(url, method, request) create_http_request({ url, strlen(url), method, strlen(method)}, request);

#endif // SIREL_HTTP_REQUEST_H
