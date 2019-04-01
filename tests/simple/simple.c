#include <string.h>
#include <stdlib.h>

#include <sirel/sirel.h>

void handle_response(struct SRL_Response *response) {
  // handle the response here
}

int main(int argc, char *argv[]) {
  const char* url = "http://localhost/";

  struct SRL_Request *request = malloc(sizeof(request));
  SRL_Request_create(url, strlen(url), &request);

  SRL_submit(request, handle_response);
}