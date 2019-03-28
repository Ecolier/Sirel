//
//  rest-client.h
//  RestClientFramework
//
//  Created by Evan Gruère on 24/03/2019.
//  Copyright © 2019 Evan Gruère. All rights reserved.
//

#ifndef rest_client_h
#define rest_client_h

#define REST_METHOD_GET    0x0100
#define REST_METHOD_POST   0x0101
#define REST_METHOD_PUT    0x0102
#define REST_METHOD_UPDATE 0x0103

struct REST_Request;
struct REST_Response;
struct REST_Request_Provider;

struct REST_Request_Attributes {
  const char *url;
  size_t url_length;
  unsigned int method;
  const char *header;
  size_t header_length;
  const char *data;
  size_t data_length;
};

typedef void(*REST_Response_Callback)(struct REST_Response *response);
typedef void(*REST_Request_Factory)(const char *url, unsigned int url_length, struct REST_Request *request);

/*
 * Request creation
 */
void REST_Request_create(const char *url, unsigned int url_length, unsigned int method, struct REST_Request **request);
void REST_Request_get_attributes(struct REST_Request *request, struct REST_Request_Attributes **attributes);

/*
 * Request header functions
 */
void REST_Request_set_header(struct REST_Request *request, const char *header, const char *header_size);
void REST_Request_get_header(struct REST_Request *request, char *header, const char *header_size);
unsigned int REST_Request_get_header_size(struct REST_Request *request);

/*
 * Request URL functions
 */
void REST_Request_set_url(struct REST_Request *request, const char *url, unsigned int url_length);
void REST_Request_get_url(struct REST_Request *request, char *url, unsigned int url_length);
unsigned REST_Request_get_url_length(struct REST_Request *request);

/*
 * Request Content functions
 */
void REST_Request_set_content(struct REST_Request *request, const char *content, unsigned int content_size);
void REST_Request_get_content(struct REST_Request *request, char *content, unsigned int content_size);
unsigned int REST_Request_get_content_size(struct REST_Request *request);




/*
 * Response
 */
struct REST_Response {
  const char *data;
  unsigned int data_size;
};

struct REST_Request_Provider {
  REST_Request_Factory request_factory;
};

void REST_fetch(struct REST_Request *request, REST_Response_Callback callback);

#endif // rest_client_h
