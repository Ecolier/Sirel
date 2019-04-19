#include "oauth2/oauth2_request.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void handle_token(OAuth2Token *token) {
  printf("hello");
}

void handle_error(OAuth2Error *error) {

}

int main(int argc, char *argv[]) {
  const char *url = "http://127.0.0.1:8000/o/token/";
  const char *username = "evan";
  const char *password = "EvanKanye13";
  const char *client_id = "LDoQcyK47hhWiyhXRsRdMLsZROkRiq2A4WYh9TgA";

  OAuth2TokenRequest request;
  request.type = OAUTH2_GRANT_TYPE_PASSWORD;
  request.credentials.username = username;
  request.credentials.username_length = strlen(username);
  request.credentials.password = password;
  request.credentials.password_length = strlen(password);
  request.credentials.client_id = client_id;
  request.credentials.client_id_length = strlen(client_id);

  request_oauth2_token(url, strlen(url),
                       request, handle_token, handle_error);

  while (1) { }

  return 0;
}