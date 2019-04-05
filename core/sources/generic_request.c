#include "generic_request.h"
#include <stddef.h>

struct SRL_Generic_Request {
  const char *protocol_name_;
  size_t protocol_name_length_;
};