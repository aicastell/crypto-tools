
/* Frequency of every ASCII char */

#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    /* inicializaciones */
    unsigned long int total = 0;
    float freq = 0;

    int i;
    int ascii[256]; /* numero de apariciones de cada ascii[i] */
    for (i = 0; i < 256; i++)
        ascii[i] = 0;

    unsigned char c;

    /* actualizacion de la tabla ascii y de la variable total */
    while (read(0, &c, sizeof(unsigned char)) > 0 ) {
        ascii[c]++;
        total++;
    }
    close(0);

    /* visualizacion resultados tabla ASCII */
    for (i = 0; i < 256; i++) {
        if (ascii[i]) {
            freq = ((float) ascii[i]) / ((float) total);
            printf("ASCII[%d %c] = %d\tfreq = %f\n", i, i, ascii[i], freq);
        }
    }

    /* visualizacion total */
    printf("\nTotal of characters: %lu", total);
    printf("\n");

    return(0);
}

