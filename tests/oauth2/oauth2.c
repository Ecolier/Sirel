#include "oauth2/oauth2_request.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void handle_token(OAuth2Token *token) {

}

void handle_error(OAuth2Error *error) {

}

int main(int argc, char *argv[]) {
  const char *url = "http://localhost:8000/o/token/";
  const char *username = "Diego";
  const char *password = "ImAHappyPassword8372";
  const char *client_id = "FooBar1204";

  OAuth2TokenRequest request;
  MAKE_OAUTH2_TOKEN_REQUEST(OAUTH2_GRANT_TYPE_PASSWORD,
      username, password, client_id, request);
  GET_OAUTH2_TOKEN(url, request, handle_token, handle_error);

  while (1) { }

  return 0;
}