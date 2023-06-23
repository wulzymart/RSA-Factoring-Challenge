#include <stdio.h>

int factorise(long long int num)
{
		int unsolved = 1;
		long long int div;
		if (num % 2 == 0) {
				printf("%lld=%lld*%d\n", num, num / 2, 2);
				return 0;
			}
		if (num % 3 == 0) {
				printf("%lld=%lld*%d\n", num, num / 3, 3);
				return 0;
			}
			div = 5;
		while (div * div <= num) {
			if (num % div == 0) {
				printf("%lld=%lld*%lld\n", num, num / div, div);
				return 0;
			}
			div += 2;
		}
		printf("%lld=%lld*%d\n", num, num, 1);
		return 1;
			
}
