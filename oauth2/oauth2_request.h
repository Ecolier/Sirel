#ifndef SIREL_OAUTH2_REQUEST_H
#define SIREL_OAUTH2_REQUEST_H

#include "http/http_request.h"

struct SRLO2_Request;

void SRLO2_token_with_credentials(const char* url, size_t url_length,
                                  const char* username, size_t username_length,
                                  const char *password, size_t password_length,
                                  const char *client_id, size_t client_id_length,
                                  struct SRLO2_Request **O2_request);

void SRLO2_send_request(struct SRLO2_Request *O2_request, SRL_Send_Callback callback);

void SRLO2_destroy_request(struct SRLO2_Request *O2_request);

#endif // SIREL_OAUTH2_REQUEST_H