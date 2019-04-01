#ifndef SIRELEY_TYPES_H
#define SIRELEY_TYPES_H

/**
 * includes size_t and a bunch of useful types
 */
#include <stddef.h>

struct SRL_Request;
struct SRL_Response;

typedef void(*SRL_Submit_Callback)(struct SRL_Response *response);

#endif // SIRELEY_TYPES_H
