#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "http/http_request.h"
#include "oauth2/oauth2_request.h"

void handle_response() {
  printf("got response!");
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

  SRLO2_send_request(request, handle_response);

  while (1) { }
}