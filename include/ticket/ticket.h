#ifndef TICKET_H
#define TICKET_H

#include <stdint.h>
#include <stdbool.h>

#include "ticket_data.h"

ticket_data newTicket(uint64_t userID, const char* const email);
void deleteTicket(ticket_data* ticket);

bool saveTicket(const ticket_data* const ticket);
bool eraseTicket(const ticket_data* const ticket);
#endif
