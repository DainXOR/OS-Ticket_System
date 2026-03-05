#ifndef TICKET_DATA_H
#define TICKET_DATA_H

#include <stdint.h>

typedef char request_type;

typedef struct {
	uint64_t userID;
	char* email;
	uint64_t ticketID;
	request_type request;

} ticket_data;

#endif
