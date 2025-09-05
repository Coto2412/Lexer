#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>
#include "lexer.h"
                    //    1    2    3    4    5    6    7
const char alphabet[] = {'+', '-', '<', '>', '=', 'Z', 'x'};
const size_t alpha_size = 7;


token_t *lexer(const char *file_name) {
    FILE *file = fopen(file_name, "r");
    char c;
    uint8_t last_state = 0;
    uint8_t state = 0;
    char buffer[32] = { 0 };

    size_t i;

    while ((c = fgetc(file)) != EOF) {

        last_state = state;
        switch (state) {
            case 0:
                memset(buffer, 0, 32);
                i = 0;
                state = 0;
                buffer[i] = c;
                for (size_t j = 0; j < alpha_size; j++)
                    if (alphabet[j] == c)
                        state = j + 1;

                if (isdigit(c))
                    state = 8;

                break;
            case 1:
            case 2:
            case 5:
            case 6:
            case 12:
            case 13:
                state = 0;
                break;
            case 11:
                state = 0;
                ungetc(c, file);
                break;
            case 3:
                state = 0;
                if (c == '=')
                    state = 12;
                break;
            case 4:
                state = 0;
                if (c == '=')
                    state = 13;
                break;

            case 8:
                state = 255;
                for (size_t j = 0; j < alpha_size; j++)
                    if (alphabet[j] == c || (c < 33))
                        state = 11;
                if (isdigit(c))
                    state = 8;
                if (c == '.')
                    state = 9;
                break;
            case 9:
                state = 255;
                if (isdigit(c))
                    state = 10;
                break;
            case 10:
                state = 255;
                for (size_t j = 0; j < alpha_size; j++)
                    if (alphabet[j] == c || (c < 33))
                        state = 11;
                if (isdigit(c))
                    state = 10;
                break;
            case 255:
                state = 255;
                break;

        }

        i++;

        printf("\r\nstate: %d, c: %c, last state: %d", state, c, last_state);
        getc(stdin);

        if (state == 255) {
            printf("Error\n");
            return NULL;
        }

        if (last_state != state && state == 0) {
            printf("%s\n", buffer);
        }
    }
}
