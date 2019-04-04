#ifndef SIREL_HTTP_REQUEST_H
#define SIREL_HTTP_REQUEST_H

struct SRL_Http_Request;
typedef void(*SRL_Send_Callback)();

void SRL_send_http_request(struct SRL_Http_Request *request, SRL_Send_Callback callback);

void SRL_create_http_request(const char *url, size_t url_length, struct SRL_Http_Request **request);
void SRL_destroy_http_request(struct SRL_Http_Request *request);

void SRL_set_http_request_method(struct SRL_Http_Request *request, const char *method, size_t method_length);
void SRL_set_http_request_body(struct SRL_Http_Request *request, const char *body, size_t data_length);

#endif // SIREL_HTTP_REQUEST_H
