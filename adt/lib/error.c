#include "./error.h"
#include <stdlib.h>
#include <stdio.h>

void abort(char* message, int code) {
    printf(message);
    exit(code);
}
