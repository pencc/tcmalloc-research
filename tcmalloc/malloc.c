#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>

int len = 64;
int count = 40000000;

void main()
{
	char *p;
	struct timespec timeStart = {0,0},timeEnd = {0,0};
	long long elapsed = 0;
	int i = count;
	while(i--) {
		clock_gettime(CLOCK_REALTIME_COARSE, &timeStart);
		p = malloc(len);
	//	memset(p, 0xfe, len);
		free(p);
		clock_gettime(CLOCK_REALTIME_COARSE, &timeEnd);
	
		elapsed = elapsed + (timeEnd.tv_sec - timeStart.tv_sec) * 1000000000 + (timeEnd.tv_nsec - timeStart.tv_nsec);
	}

	printf("%luns per req", elapsed / count);
}

