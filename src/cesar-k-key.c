
/* Cesar algorith with k-key */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
    /* argumentos de entrada */
    if (argc != 3) {
        printf("syntax: %s -[e|d] key\n", argv[0]);
        printf("example: %s -e 3\n", argv[0]);
        exit(0);
    }

    if (argv[1][1] != 'e' && argv[1][1] != 'd') {
        printf("syntax: %s -[e|d] key\n", argv[0]);
        exit(0);
    }

    /* inicializaciones */
    char ed = argv[1][1]; /* encode o decode */
    int k = atoi(argv[2]); /* key */
    if (k > 255)
        k = k % 256;

    char c;

    /* encoding ... */
    if (ed == 'e') {
        while (read(0, &c, sizeof(unsigned char)) > 0)
            printf("%c", (c + k) % 256);
    }

    /* decoding ... */
    if (ed == 'd') {
        while (read(0, &c, sizeof(unsigned char)) > 0)
            printf("%c", (c - k) % 256);
    }

    return 0;
}

