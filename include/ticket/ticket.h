#ifndef TICKET_H
#define TICKET_H

#include <stdint.h>

#include "ticket_data.h"

ticket_data generateTicket(uint64_t userID, char* email);

#endif
