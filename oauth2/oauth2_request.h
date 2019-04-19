#ifndef SIREL_OAUTH2_REQUEST_H
#define SIREL_OAUTH2_REQUEST_H

#include "http/http_request.h"

/**
 * https://www.oauth.com/oauth2-servers/access-tokens/access-token-response/
 */
#define OAUTH2_INVALID_REQUEST        0x100
#define OAUTH2_INVALID_CLIENT         0x102
#define OAUTH2_INVALID_GRANT          0x103
#define OAUTH2_INVALID_SCOPE          0x104
#define OAUTH2_UNAUTHORIZED_CLIENT    0x105
#define OAUTH2_UNSUPPORTED_GRANT_TYPE 0x106

#define OAUTH2_GRANT_TYPE_PASSWORD      0x200
#define OAUTH2_GRANT_TYPE_AUTHORIZATION 0x201

// Different kind of grants
typedef struct oauth2_token_credentials_request_t {
  const char *username;
  size_t username_length;
  const char *password;
  size_t password_length;
  const char *client_id;
  size_t client_id_length;
} OAuth2Credentials;

typedef struct oauth2_token_authorization_request_t {
  const char *authorization_code;
  size_t authorization_code_length;
} OAuth2Authorization;

typedef struct oauth2_token_request_t {
  int type; //OAUTH_2_GRANT_TYPE_*
  union {
    OAuth2Credentials credentials;
    OAuth2Authorization authorization;
  };
} OAuth2TokenRequest;

typedef struct oauth2_token_t {
  const char *access_token;
  unsigned int expires_in;
  const char *token_type;
  const char *scope;
  const char *refresh_token;
} OAuth2Token;

typedef struct oauth2_error_t {
  const char *error_name;
  const char *error_description;
} OAuth2Error;

typedef void(*OAuth2HandleToken)(OAuth2Token *);
typedef void(*OAuth2HandleError)(OAuth2Error *);

typedef struct oauth2_completion_t {
  OAuth2HandleToken token_handler;
  OAuth2HandleError error_handler;
} OAuth2Completion;

void request_oauth2_token(const char *url, size_t url_length,
    OAuth2TokenRequest, OAuth2HandleToken, OAuth2HandleError);

#endif // SIREL_OAUTH2_REQUEST_H