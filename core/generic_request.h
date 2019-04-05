#ifndef SIREL_CORE_REQUEST_H
#define SIREL_CORE_REQUEST_H

struct SRL_Generic_Request;

void SRL_create_generic_request(const char* protocol, struct SRL_Generic_Request **request);
void SRL_destroy_generic_request(struct SRL_Generic_Request *request);
const char *SRL_get_request_protocol_name();

#endif // SIREL_CORE_REQUEST_H
