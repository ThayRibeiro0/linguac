#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE");
        return 1;
    }
    FILE *infile = fopen(argv[1], "r");

    if (infile == NULL)
    {
        printf("Couldn't open file");
        return 2;
    }

    unsigned char buffer[512];

    int countimg = 0;

    FILE *outfile = NULL;

    char *namefile = malloc(8 * sizeof(char));

    while (fread(buffer, sizeof(char), 512, infile))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(namefile, "%03i.jpg", countimg);

            outfile = fopen(namefile, "w");

            countimg++;
        }
        if (outfile != NULL)
        {
            fwrite(buffer, sizeof(char), 512, outfile);
        }
    }

    free(namefile);

    fclose(outfile);
    fclose(infile);

    return 0;
}