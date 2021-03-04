#include <stdio.h>
# include <assert.h>
int main(void)
{
	assert(0. == -0.);
	printf("%lf", 1. / 0.);
	// assert(1. / 0. == 1. / -0.);
}