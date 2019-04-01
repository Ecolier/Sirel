# Sirel

A Simple Cross-platform Request Library

## Basic Usage

Creating request, sending it and handling the response is a straightforward process that requires minimal boilerplate code.
Here is a piece of code that creates an empty request, sends it to localhost and handles a response.

```c
#include <string.h>
#include <stdlib.h>

#include <sirel/sirel.h>

void handle_response(struct SRL_Response *response) {
  // handle the response object here
}

int main(int argc, char *argv[]) {
  const char* url = "http://localhost/";
  struct SRL_Request *request = malloc(sizeof(request));
  SRL_Request_create(url, strlen(url), &request);
  SRL_send(request, handle_response);
}
```
