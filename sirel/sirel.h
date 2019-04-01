#ifndef SIREL_H
#define SIREL_H

/**
 * Sirel is a SImple REquest LibrarY
 *
 * Basic usage:
 * - Create an instance of a SRL_Request using the SRL_Request_create() function
 * - Submit the request using the SRL_submit() function
 * - Handle the response object in the function callback you supplied to SRL_fetch()
 */
#include "sirel_client.h"
#include "sirel_request.h"
#include "sirel_response.h"

#endif // SIREL_H
