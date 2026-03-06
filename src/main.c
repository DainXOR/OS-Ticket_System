#include <stdio.h>
#include <stdbool.h>

#include "ticket/ticket.h"

int main(void){
	char id_buf[INPUT_SIZE];
    char email_buf[INPUT_SIZE];
    char req_buf[INPUT_SIZE];

    printf("Identificacion: ");
    if (!read_line(id_buf, sizeof(id_buf))) {
        fprintf(stderr,"Error reading ID\n");
        return 1;
    }

    uint64_t id = strtoull(id_buf,NULL,10);

    if (id == 0){
        fprintf(stderr,"Invalid ID\n");
        return 1;
    }

    printf("Correo: ");
    if (!read_line(email_buf,sizeof(email_buf))){
        fprintf(stderr,"Error reading email\n");
        return 1;
    }

    if (!is_valid_email(email_buf)){
        fprintf(stderr,"Invalid email\n");
        return 1;
    }

    printf("Tipo de reclamacion: ");
    if (!read_line(req_buf,sizeof(req_buf))){
        fprintf(stderr,"Error reading request\n");
        return 1;
    }

    random_init();

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
