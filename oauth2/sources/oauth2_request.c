#include "oauth2_request.h"
#include <stdlib.h>
#include <string.h>

struct SRLO2_Request {
  struct SRL_Http_Request *http_request_;
};

void SRLO2_token_with_credentials(const char* url, size_t url_length,
                                  const char* username, size_t username_length,
                                  const char *password, size_t password_length,
                                  const char *client_id, size_t client_id_length,
                                  struct SRLO2_Request **request) {

  // Setting data manually is quite a pain in C...
  const char *fixed_data = "grant_type=password&username=&password=&client_id=";
  size_t fixed_data_length = strlen(fixed_data);
  size_t args_data_length =  username_length + password_length + client_id_length;
  size_t full_data_length = fixed_data_length + args_data_length;
  char *data = malloc(full_data_length);
  strcat(data, "grant_type=password&username=");
  strcat(data, username);
  strcat(data, "&password=");
  strcat(data, password);
  strcat(data, "&client_id=");
  strcat(data, client_id);

  // Getting a token requires a POST request
  const char *method = "POST";

  // Allocate space on the stack
  struct SRLO2_Request *out_request = malloc(sizeof(out_request));
  struct SRL_Http_Request *base_request = malloc(sizeof(base_request));

  // Initialize the base request
  SRL_create_http_request(url, url_length, &base_request);
  SRL_set_http_request_method(base_request, method, strlen(method));
  SRL_set_http_request_body(base_request, data, full_data_length);

  // Initialize the OAuth2 request
  out_request->http_request_ = base_request;
  *request = out_request;
}

void SRLO2_send_request(struct SRLO2_Request *request, SRL_Send_Callback callback) {
    SRL_send_http_request(request->http_request_, callback);
}

void SRLO2_destroy_request(struct SRLO2_Request *request) {

}