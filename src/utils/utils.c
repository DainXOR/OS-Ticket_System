

/*
#include <stdlib.h>
#include <stdio.h>
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
*/
