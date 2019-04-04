#include <string.h>
#include <stdlib.h>

#include "oauth2.h"

#include <sirel/sirel_request.h>
#include <sirel/sirel_client.h>

struct SRLO2_Request {
  struct SRL_Request *base_request;
};

void SRLO2_token_with_credentials(const char* url, size_t url_length,
                                  const char* username, size_t username_length,
                                  const char *password, size_t password_length,
                                  const char *client_id, size_t client_id_length,
                                  struct SRLO2_Request **request) {

  // Setting data manually is quite a pain in C...
  const char *fixed_data = "grant_type=password&username=&password=&client_id=";
  size_t fixed_data_length = strlen(fixed_data);
  size_t args_data_length = username_length + password_length + client_id_length;
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
  struct SRL_Request   *base_request = malloc(sizeof(base_request));

  // Initialize the base request
  SRL_Request_create(url, url_length, &base_request);
  SRL_Request_set_method(base_request, method, strlen(method));
  SRL_Request_set_data(base_request, data, full_data_length);

  // Initialize the OAuth2 request
  out_request->base_request = base_request;
  *request = out_request;
}

void SRLO2_destroy_request(struct SRLO2_Request *request) {

}

void handle_response() {

}

int main(int argc, char *argv[]) {
  const char *url = "http://192.168.1.51:8000/o/token/";
  const char *username = "evan";
  const char *password = "EvanKanye13";
  const char *client_id = "LDoQcyK47hhWiyhXRsRdMLsZROkRiq2A4WYh9TgA";

  struct SRLO2_Request *request = malloc(sizeof(request));
  SRLO2_token_with_credentials(
      url, strlen(url),
      username, strlen(username),
      password, strlen(password),
      client_id, strlen(client_id),
      &request);

  SRL_submit(request->base_request, handle_response);

  while (1) { }
}