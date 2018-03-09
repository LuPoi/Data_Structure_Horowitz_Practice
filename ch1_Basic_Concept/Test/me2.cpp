#include <sys/resource.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct rusage r_usage;
int count = 0;

float Rsum(float *a, const int n) {
	getrusage(RUSAGE_SELF,&r_usage);
	printf("maximum resident set size = %ld\n",r_usage.ru_maxrss);
	printf("integral shared memory size = %ld\n",r_usage.ru_ixrss);
	printf("integral unshared data size = %ld\n",r_usage.ru_idrss);
	printf("integral unshared stack size = %ld\n",r_usage.ru_isrss);
	printf("======================\n");

	count ++;
	if (n <= 0) {
		count++;
		return 0;
	}
	else {
		count++;
		return (Rsum(a, n-1) + a[n-1]);
	}
}

int main() {
	float a[] = {1,3,2,3};
	int n = 4;
	float result = 0;

	printf("Rsum result: %f\n", Rsum(a, n));

  // printf("\nAllocated memory, sleeping ten seconds after which we will check again...\n\n");
  // getrusage(RUSAGE_SELF,&r_usage);
  // printf("Memory usage = %ld\n",r_usage.ru_maxrss);
  return 0;
}
