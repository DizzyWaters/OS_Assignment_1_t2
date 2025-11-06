#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BIGASS_DATAFILE "my_data.dat"
#define COORDS_IN_FILE 145000000 // should be > 2GB

int main(int argc, char **argv)
{
    FILE *fp = fopen(BIGASS_DATAFILE, "w");
    if(!fp)
    {
        perror("Can't open file to write");
        return 1;
    }

    printf("Genereting cood file: %s\n", BIGASS_DATAFILE);
    for(long i = 0; i < COORDS_IN_FILE; ++i)
    {
        // gen rand coords
        int x = rand() % 20001 - 10000;
        int y = rand() % 20001 - 10000;
        int z = rand() % 20001 - 10000;
        // put it in file
        fprintf(fp, "%d %d %d\n", x ,y, z);
    }

    fclose(fp);
    printf("Done file %s is genereted\n", BIGASS_DATAFILE);
    return 0;
}
