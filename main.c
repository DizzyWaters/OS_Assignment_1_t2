#include <stdio.h>
#include <coordinates.h>

int main(int argc, char **argv)
{
    double maxDist;
    int line = find_farthest_point("my_data.dat", &maxDist);
	printf("Farthest point found at line: %d \n", line);
    printf("Distance from origin: %.2f\n", maxDist);
	return 0;
}

