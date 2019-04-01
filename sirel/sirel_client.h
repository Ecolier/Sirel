#ifndef SIREL_CLIENT_H
#define SIREL_CLIENT_H

#include "sirel_types.h"

void SRL_submit(struct SRL_Request *request, SRL_Submit_Callback callback);

#endif // SIREL_CLIENT_H
