#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t n = 0;
	unsigned long long div, number;
	int unsolved =  1;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL) {
		fprintf(stderr,"Error opening file\n");
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &n, file) != -1) {
		unsolved = 1;
		div = 2;
		number = atoll(line);
		while (unsolved && div * div <= number) {
			if (number % div == 0) {
				printf("%llu=%llu*%lld\n", number, number / div, div);
				unsolved = 0;
			}
			div++;
		}
		if (unsolved)
			printf("%llu=%llu*%d\n", number, number, 1);
	}

	free(line);
	fclose(file);
	exit(EXIT_SUCCESS);
}
