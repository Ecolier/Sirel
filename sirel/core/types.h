#ifndef SIREL_CORE_TYPES_H
#define SIREL_CORE_TYPES_H

/**
 * includes size_t and a bunch of useful types
 */
#include <stddef.h>

struct SRL_Request;
struct SRL_Response;

typedef void(*SRL_Submit_Callback)(struct SRL_Response *response);

#endif // SIREL_CORE_TYPES_H
