#ifndef SIREL_CORE_REQUEST_H
#define SIREL_CORE_REQUEST_H

struct SRL_Request;

void SRL_make_request(struct SRL_Request **request);
void SRL_destroy_request(struct SRL_Request *request);

#endif // SIREL_CORE_REQUEST_H
