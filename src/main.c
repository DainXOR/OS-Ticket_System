#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "ticket/ticket.h"
#include "utils/rand.h"
#include "utils/regx.h"

#define INPUT_SIZE 1024

int main(void){
	random_init();

	char id_buf[INPUT_SIZE];
    char email_buf[INPUT_SIZE];
    char req_buf[INPUT_SIZE];

    printf("Identificacion: ");
    if (!scanf("%1023s", id_buf)) {
        fprintf(stderr,"Error reading ID\n");
        return 1;
    }

    uint64_t id = strtoull(id_buf,NULL,10);

    if (id == 0){
        fprintf(stderr,"Invalid ID\n");
        return 1;
    }

    printf("Correo: ");
    if (!scanf("%1023s", email_buf)){
        fprintf(stderr,"Error reading email\n");
        return 1;
    }

    if (!regx_comp(email_buf, "(@+)")){
        fprintf(stderr,"Invalid email\n");
        return 1;
    }

    printf("Tipo de reclamacion: ");
    if (!scanf("%1023s", req_buf)){
        fprintf(stderr,"Error reading request\n");
        return 1;
    }

    ticket_data ticket = newTicket(id,email_buf);
    ticket.request = req_buf[0];

    if (!saveTicket(&ticket)){
        fprintf(stderr,"Failed to save ticket\n");
        deleteTicket(&ticket);
        return 1;
    }

    printf("Ticket generado: %llu\n",(unsigned long long)ticket.ticketID);

    deleteTicket(&ticket);
    return 0;
}
