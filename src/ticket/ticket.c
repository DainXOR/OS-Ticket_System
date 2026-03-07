#include "ticket/ticket.h"

#include <stdlib.h>
#include <stdio.h>
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

    if (!ticket)
        return false;

    char path[256];

    snprintf(
        path,
        sizeof(path),
        "assets/ticket_%llu.txt",
        (unsigned long long)ticket->ticketID
    );

    char line1[128];
    char line2[128];
    char line3[256];
    char line4[64];

    snprintf(line1,sizeof(line1),
        "Radicado: %llu",
        (unsigned long long)ticket->ticketID);

    snprintf(line2,sizeof(line2),
        "Identificacion: %llu",
        (unsigned long long)ticket->userID);

    snprintf(line3,sizeof(line3),
        "Correo: %s",
        ticket->email);

    snprintf(line4,sizeof(line4),
        "Tipo de reclamacion: %c",
        ticket->request);

    return fs_write(path,4,line1,line2,line3,line4) == 0;
}

bool eraseTicket(const ticket_data* const ticket){

    if (!ticket)
        return false;

    char path[256];

    snprintf(
        path,
        sizeof(path),
        "assets/ticket_%llu.txt",
        (unsigned long long)ticket->ticketID
    );

    return remove(path) == 0;
}
ticket_data loadTicket(uint64_t ticketID){

    ticket_data ticket = {
        .email = NULL,
        .ticketID = ticketID,
        .request = 0,
        .userID = 0
    };

    char path[256];

    snprintf(
        path,
        sizeof(path),
        "assets/ticket_%llu.txt",
        (unsigned long long)ticketID
    );

    file_lines fl = fs_read(path);

    if (fl.count < 4)
        return ticket;

    sscanf(fl.lines[1],"Identificacion: %llu",
        (unsigned long long*)&ticket.userID);

    char email[256];
    sscanf(fl.lines[2],"Correo: %255[^\n]",email);

    ticket.email = str_clone(email);

    sscanf(fl.lines[3],"Tipo de reclamacion: %c",&ticket.request);

    fs_freeLines(&fl);

    return ticket;
}
