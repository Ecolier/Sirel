#ifndef SIRELEY_REQUEST_H
#define SIRELEY_REQUEST_H

#include "sireley_types.h"

/**
 * Create a request using a single string, for instance:
 * "POST http://localhost/ -h HEADER-1: VALUE, HEADER-2: VALUE -d DATA"
 * @param raw the raw string to parse
 */
void SRL_Request_create_raw(const char* raw, size_t raw_length, struct SRL_Request **request);
void SRL_Request_create(const char *url, size_t url_length, struct SRL_Request **request);
void SRL_Request_delete(struct SRL_Request *request);

#endif // SIRELEY_REQUEST_H
