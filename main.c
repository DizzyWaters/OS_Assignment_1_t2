#include <stdio.h>
#include <coordinates.h>

int main(int argc, char **argv)
{
    double maxDist;
    int line = find_farthest_point("my_data.dat", &maxDist);
	printf("This is max dist %d \n", line);
	return 0;
}

