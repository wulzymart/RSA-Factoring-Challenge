#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char *line = 0;
	size_t n = 0;
	unsigned long long num;
	unsigned long long i;
	int solved;
	FILE *file;

	file = fopen(argv[1], "r");
	while(getline(&line, &n, file) != -1)
	{
		solved = 0;
		num = atoll(line);
		i = 2;
		if (num % i == 0)
		{
			printf("%llu=%llu*%llu\n", num, num/i, i);
			solved = 1;
			continue;
		}
		i++;
		while (i * i <= num)
		{
			if (num % i == 0)
			{
				printf("%llu=%llu*%llu\n", num, num/i, i);
				solved = 1;
				break;
			}
			i += 2;
		}
		if (!solved)
			printf("%llu=%llu*%u\n", num, num, 1);
	}
	free(line);
	return 0;
}
