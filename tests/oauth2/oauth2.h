//
// Created by Evan Gruère on 2019-04-04.
//

#ifndef SIREL_TESTS_OAUTH2_H
#define SIREL_TESTS_OAUTH2_H

#include <stddef.h>

struct SRLO2_Request;

void SRLO2_token_with_credentials(const char* url, size_t url_length,
                                  const char* username, size_t username_length,
                                  const char *password, size_t password_length,
                                  const char *client_id, size_t client_id_length,
                                  struct SRLO2_Request **O2_request);

void SRLO2_destroy_request(struct SRLO2_Request *O2_request);

#endif // SIREL_TESTS_OAUTH2_H
