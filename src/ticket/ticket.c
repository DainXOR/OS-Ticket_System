#include "ticket/ticket.h"

#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "utils/rand.h"
#include "ticket/ticket_data.h"

ticket_data generateTicket(uint64_t userID, char* email){
	const uint64_t emailSize = strlen(email);

	ticket_data str = {
		.email = (char*)malloc(emailSize),
		.ticketNumber = random_get(),
		.request = 0,
		.userID = userID
	};

	strcpy(str.email, email);

	return str;
}
