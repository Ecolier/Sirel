#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <sireley/sireley.h>

struct OAuth2_Request_Provider {
  struct SRL_Request_Provider *base_provider;
  const char *client_id;
};

void OAuth2_Successful(const char *response) {

}

void OAuth2_Unsuccessful(const char *response) {

}

void Simple_handle_response(const char *response) {

}

void SRL_handle_response(struct SRL_Response *response) {
  printf("got response!");
}

void OAuth2_get_token_with_credentials(const char *url,
    const char *username, const char *password,
    const char *client_id, const char *scope,
    void(*handle_response)(const char *response)) {

  char request_body[256];

  snprintf(request_body, 256, "%s%s%s%s%s%s",
      "grant_type=password&username=", username,
      "&password=", password,
      "&client_id=", client_id);

  struct SRL_Request *request = malloc(sizeof(&request));
  SRL_Request_create(url, strlen(url), "POST", request);
  SRL_Request_set_content(request, request_body, strlen(request_body));

  SRL_fetch(request, SRL_handle_response);
}




int main(int argc, char *argv[]) {

  const char *url = "http://127.0.0.1:8000";

  struct SRL_Request *request = malloc(sizeof(request));
  SRL_Request_create(url, strlen(url), SRL_METHOD_GET, &request);

  struct SRL_Request_Attributes *attributes = malloc(sizeof(attributes));
  SRL_Request_get_attributes(request, &attributes);

  SRL_fetch(request, SRL_handle_response);

  while (1) { }

  /**struct OAuth2_Request_Provider *provider = malloc(sizeof(provider));

  struct SRL_Request_Provider *base_provider = malloc(sizeof(base_provider));
  provider->base_provider = base_provider;

  OAuth2_get_token_with_credentials("http://localhost/o/token/",
      "evan", "root",
      "123456", "readwrite",
      Simple_handle_response); **/
}