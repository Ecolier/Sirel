#ifndef SIRELEY_REQUEST_H
#define SIRELEY_REQUEST_H

#include "sireley_types.h"

#define SRL_METHOD_GET    0x0100
#define SRL_METHOD_POST   0x0101
#define SRL_METHOD_PUT    0x0102
#define SRL_METHOD_UPDATE 0x0103

struct SRL_Request_Attributes {
  const char *url;
  size_t url_length;
  unsigned int method;
  const char *header;
  size_t header_length;
  const char *data;
  size_t data_length;
};

/*
 * Request creation
 */
void SRL_Request_create(const char *url, unsigned int url_length, unsigned int method, struct SRL_Request **request);
void SRL_Request_get_attributes(struct SRL_Request *request, struct SRL_Request_Attributes **attributes);

/*
 * Request header functions
 */
void SRL_Request_set_header(struct SRL_Request *request, const char *header, const char *header_size);
void SRL_Request_get_header(struct SRL_Request *request, char *header, const char *header_size);
unsigned int SRL_Request_get_header_size(struct SRL_Request *request);

/*
 * Request URL functions
 */
void SRL_Request_set_url(struct SRL_Request *request, const char *url, unsigned int url_length);
void SRL_Request_get_url(struct SRL_Request *request, char *url, unsigned int url_length);
unsigned SRL_Request_get_url_length(struct SRL_Request *request);

/*
 * Request Content functions
 */
void SRL_Request_set_content(struct SRL_Request *request, const char *content, unsigned int content_size);
void SRL_Request_get_content(struct SRL_Request *request, char *content, unsigned int content_size);
unsigned int SRL_Request_get_content_size(struct SRL_Request *request);

#endif // SIRELEY_REQUEST_H
