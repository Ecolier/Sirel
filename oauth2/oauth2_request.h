#ifndef SIREL_OAUTH2_REQUEST_H
#define SIREL_OAUTH2_REQUEST_H

#include "http/http_request.h"

/**
 * https://www.oauth.com/oauth2-servers/access-tokens/access-token-response/
 */
#define SOA2_INVALID_REQUEST        0x100
#define SOA2_INVALID_CLIENT         0x102
#define SOA2_INVALID_GRANT          0x103
#define SOA2_INVALID_SCOPE          0x104
#define SOA2_UNAUTHORIZED_CLIENT    0x105
#define SOA2_UNSUPPORTED_GRANT_TYPE 0x106

/**
 *
 */
typedef struct {
  const char *access_token;
  size_t access_token_length;
  unsigned int expires_in;
  const char *token_type;
  size_t token_type_length;
  const char *scope;
  size_t scope_length;
  const char *refresh_token;
  size_t refresh_token_length;
} SOA2_Token;

/**
 *
 */
typedef struct {
  const char *error_name;
  size_t error_name_length;
  const char *error_description;
  size_t error_description_length;
} SOA2_Error;

typedef void(*SOA2_Request_Was_Successful)(SOA2_Token);
typedef void(*SOA2_Request_Was_Unsuccessful)(SOA2_Error);

void SOA2_request_access_token_with_credentials(const char* url, size_t url_length,
                                  const char* username, size_t username_length,
                                  const char *password, size_t password_length,
                                  const char *client_id, size_t client_id_length,
                                  SOA2_Request_Was_Successful, SOA2_Request_Was_Unsuccessful);

#endif // SIREL_OAUTH2_REQUEST_H