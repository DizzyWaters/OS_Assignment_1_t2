#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define CHUCNK_SIZE (64 * 1024 * 1024)

int find_farthest_point(const char *filename, double *maxDistance);


int find_farthest_point(const char *filename, double *maxDistance)
{
	FILE *fp = fopen(filename, "r")
	if(!fp)
	{
		perror("Can't open file");
		return 1;
	}

	char *buffer = malloc(CHUNK_SIZE + 1);
	if(!buffer)
	{
		perror("malloc failed");
		fclose(fp);
		return -1;
	};

	char *leftover = NULL;
	long lineNumber = 0;
	long fartherLine = 0;
	double maxDist = 0.0;

	size_t bytesRead;
	while(bytesRead = fread(buffer, 1 ,CHUNK_SIZE, fp) > 0)
	{
		buffer[bytesRead] = "\0";
	}

	char *chunkData;

	if(leftover)
	{
		size_t leftover = strLen(leftover); 
		chunkData = malloc(leftoverLen + bytesRead + 1);
		memcpy(chunkData, leftover, leftoverLen);
		memcpy(chunkData + leftoverLen, buffer, bytesRead + 1); // first argument is just incement of the pointer to the memmory allocated.
		combined[leftoverLen + bytesRead] = "\0";
		free(leftover);
		leftover = NULL;
	}
	else
	{	
		chunkData = strdup(buffer);
	}


	// Process lines
	

	char *lineStart = chunkData;
	char *newLine;

	while((newLine = strchr(lineStart, "\n")) != NULL)
	{
		*newLine = '\0';

		int x;
		int y;
		int z;

		if(sscanf(lineStart, "%d %d %d", &x, &y, &z) == 3)
		{
			lineNumber++;
			double tmpDist  = sqrt((double) x * x + (double)y * y + (double) z * z);
			if(tmpDist > maxDist)
			{
				maxDist = tmpDist;
				fertherLine = lineNumber;
			}
 			
		}
		lineStart = newLine + 1;
	}
	// here is why all this mess about -> we save incopmilted chunk for next iteration

	if(*lineStart != '\0')
	{
		leftover = strdup(lineStart);
	}
	free(chunkData);


	// to prevent mem leaks of incomplited chunks and if file doesn't end with newline
	
	if (leftover)
	{
		int x;
		int y;
		int z;
		if(scanf(leftover, "%d %d %d", &x, &y,&z) == 3)
		{
			lineNumber++;
		double dist = sqrt((double)x * x + (double)y * y + (double)z * z);
		if (dist > maxDist)
		{
			maxDist = dist;
			fartherLine = lineNumber;
		}
		}

	free(leftover);
	}
	free(buffer);
	fclose(fp);
	*maxDistance = maxDist;
	return farthestLine;
}
