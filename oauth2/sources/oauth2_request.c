#include "oauth2_request.h"
#include "vendors/jsmn/jsmn.h"

#include <stdlib.h>
#include <string.h>
#include <http/apple/apple_http_request.h>

struct SOA2_Request;

char *substring_range(char *str, unsigned int start, unsigned int end) {
  size_t len = end - start;
  char *ret = malloc(len + 1);
  memcpy(ret, &(str[start]), len);
  return ret;
}

unsigned int handle_http_request(const void *data, size_t data_length, unsigned int error, struct SRL_HTTP_Request *initial_request) {

  switch (error) {
    case SRL_HTTP_CANNOT_CONNECT_TO_HOST:
      exit(SRL_HTTP_CANNOT_CONNECT_TO_HOST);
      break;
  }

  if (!data) {
    return 0;
  }

  char *json = malloc(data_length);
  memcpy(json, data, data_length);

  jsmn_parser parser;
  jsmn_init(&parser);

  jsmntok_t tokens[256];
  jsmn_parse(&parser, json, data_length, tokens, 256);

  const char *successful_blueprint = "access_token";
  char *first_json_object = substring_range(json, tokens[1].start, tokens[1].end);
  if (strncmp(successful_blueprint, first_json_object, strlen(successful_blueprint)) != 0) {
    int a = 0;
  }
}

void SRLO2_token_with_credentials(const char* url, const char* username,
                                  const char *password, const char *client_id,
                                  SOA2_Request_Was_Successful successful_completion,
                                  SOA2_Request_Was_Unsuccessful unsuccessful_completion) {

  struct url_request_t *request = malloc(sizeof(url_request));
  MAKE_HTTP_REQUEST(url, "POST", &request);



/**
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
  struct SRL_HTTP_Request *base_request = malloc(sizeof(base_request));

  // Initialize the base request
  SRL_create_http_request(url, url_length, &base_request);
  SRL_set_http_request_method(base_request, method, strlen(method));
  SRL_set_http_request_body(base_request, data, full_data_length);

  // Initialize the OAuth2 request
  out_request->http_request_ = base_request;
  *request = out_request; **/
}

void SRLO2_send_request(struct SRLO2_Request *request, SRL_Request_Did_Complete callback) {
    SRL_send_http_request(request->http_request_, handle_http_request);
}

void SRLO2_destroy_request(struct SRLO2_Request *request) {
  SRL_destroy_http_request(request->http_request_);
  free(request);
}