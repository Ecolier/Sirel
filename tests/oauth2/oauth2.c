#include "oauth2/oauth2_request.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void did_receive_token(SOA2_Token token) {

}

void did_receive_error(SOA2_Error error) {

}

int main(int argc, char *argv[]) {
  const char *url = "http://127.0.0.1:8000/o/token/";
  const char *username = "evan";
  const char *password = "EvanKanye13";
  const char *client_id = "LDoQcyK47hhWiyhXRsRdMLsZROkRiq2A4WYh9TgA";

  SOA2_request_access_token_with_credentials(
      url, strlen(url), username, strlen(username),
      password, strlen(password), client_id, strlen(client_id),
      did_receive_token, did_receive_error);

  return 0;
}