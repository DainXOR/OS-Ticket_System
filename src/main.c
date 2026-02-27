#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "stdbool.h"
#include "regex.h"

regex_t regex;

bool reg_comp(char *text, char *reg){
	int reti = regcomp(&regex, reg, REG_EXTENDED);

	if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        exit(1);
    }
	reti = regexec(&regex, text, 0, NULL, 0);
	printf("%i\n", reti);

	return !reti;
}

int main(int argc, char *argv[]){
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
	srand(time(NULL));
	printf("%i\n", rand());

	return 0;
}
