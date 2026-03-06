#include "ticket/ticket.h"

#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#include "ticket/ticket_data.h"
#include "utils/rand.h"
#include "utils/fs.h"
#include "utils/str.h"

ticket_data newTicket(uint64_t userID, const char* const email){

	ticket_data ticket = {
		.email = str_clone(email),
		.ticketID = random_get(),
		.request = 0,
		.userID = userID
	};

	return ticket;
}
void deleteTicket(ticket_data* ticket){
	free(ticket->email);
	ticket->email = NULL;

	return;
}

bool saveTicket(const ticket_data* const ticket){
	return false;
}
bool eraseTicket(const ticket_data* const ticket){
	return false;
}
ticket_data loadTicket(uint64_t ticketID){
	ticket_data ticket = {
		.email = (char*)malloc(20),
		.ticketID = ticketID,
		.request = 0,
		.userID = 0
	};
	return
}
