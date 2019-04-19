#include "oauth2_request.h"
#include "vendors/jsmn/jsmn.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *substring_range(char *str, unsigned int start, unsigned int end) {
  size_t len = end - start;
  char *ret = malloc(len + 1);
  memcpy(ret, &(str[start]), len);
  return ret;
}

int handle_http(
    struct url_request_t *request,
    HTTPResponse response,
    const void *data, size_t data_length,
    unsigned int error, void *user) {

  OAuth2Completion *completion = malloc(sizeof(completion));
  completion = user;

  switch (error) {
    case CANNOT_CONNECT_TO_HOST:
      exit(CANNOT_CONNECT_TO_HOST);
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

  //success
  if (strncmp(successful_blueprint, first_json_object, strlen(successful_blueprint)) == 0) {
    completion->token_handler(NULL);
  }
}

void request_oauth2_token(
    const char *url, size_t url_length,
    OAuth2TokenRequest  request,
    OAuth2HandleToken token_handler,
    OAuth2HandleError error_handler) {

  struct url_request_t *base = malloc(sizeof(base));
  MAKE_HTTP_REQUEST(url, "POST", &base);

  // !!!UNSAFE!!!
  char data[512];
  switch (request.type) {
    case OAUTH2_GRANT_TYPE_PASSWORD: {
      OAuth2Credentials credentials = request.credentials;
      sprintf(data, "grant_type=password&username=%s&password=%s&client_id=%s", credentials.username, credentials.password, credentials.client_id);
    }
  }
  set_http_body(base, data, strlen(data));

  OAuth2Completion completion;
  completion.token_handler = token_handler;
  completion.error_handler = error_handler;

  send_http_request(base, handle_http, &completion);
}