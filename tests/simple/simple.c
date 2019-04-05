#include <string.h>
#include <stdlib.h>

#include "http/http_request.h"

void handle_response() {
  // handle the response here
}

int main(int argc, char *argv[]) {
  const char* url = "http://localhost/";

  struct SRL_Http_Request *request = malloc(sizeof(request));
  SRL_create_http_request(url, strlen(url), request);

  SRL_send_http_request(request, handle_response);

  while (1) { }
}