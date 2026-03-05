#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

//#include "utils/ticket_utils.h"


void init(void){
	srand((unsigned)time(NULL));

}

int main(int argc, char *argv[]){
	(void)argc;
    (void)argv;
	init();

	char *tst = (char*)malloc(1024);

	printf("Mete un numero: ");
	scanf("%1024[^\n]", tst);
	printf("El numero ese: %s\n", tst);
	/*
	if(!argc){
		exit(-1);
	}

	if(!reg_comp(argv[1], "(@+)")){
		puts("Vea pendejo estupido, habla bien bobo");
	}

	FILE *fptr = fopen("mei.txt", "w");

	fprintf(fptr, "Hola xd");

	fclose(fptr);
	*/

	//printf("%i\n", rand());


	free(tst);
	return 0;
}
