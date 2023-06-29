#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

void f(mpz_t result, mpz_t input, mpz_t n) {
    mpz_mul(result, input, input);
    mpz_sub_ui(result, result, 1);
    mpz_mod(result, result, n);
}

void pollards_rho(mpz_t n, mpz_t factor) {
    if (mpz_even_p(n)) {
        mpz_set_ui(factor, 2);
        return;
    }

    mpz_t x, y, d;
    mpz_inits(x, y, d, NULL);
    mpz_set_ui(x, 2);
    mpz_set_ui(y, 2);

    mpz_t temp;
    mpz_init(temp);

    mpz_set_ui(factor, 1);

    while (mpz_cmp_ui(factor, 1) == 0) {
        f(x, x, n);
        f(temp, y, n);
        f(temp, temp, n);
        mpz_set(y, temp);

        mpz_sub(temp, x, y);
        mpz_abs(temp, temp);
        mpz_gcd(d, temp, n);

        if (mpz_cmp(d, n) == 0) {
            mpz_set_ui(factor, 0);
        } else {
            mpz_set(factor, d);
        }
    }

    mpz_clears(x, y, d, temp, NULL);
}

int main(int argc, char **argv) {
    mpz_t n, factor, cofactor;
    FILE *file;
    char *line = NULL;
    size_t buff = 0;

    if (argc != 2)
    {
        fprintf(stderr,"Usage: %s <FILE>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr,"Unable to open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (getline(&line, &buff, file) != -1)
    {
    mpz_inits(n, factor, cofactor, NULL);

    // Set the value of n to your desired number
    mpz_set_str(n, line, 10);

    pollards_rho(n, factor);

    if (mpz_cmp_ui(factor, 0) == 0) {
        mpz_set_ui(cofactor, 1);
        gmp_printf("%Zd=%Zd*%Zd\n", n, n, cofactor);
    } else {
        mpz_fdiv_q(cofactor, n, factor);
        gmp_printf("%Zd=%Zd*%Zd\n", n, cofactor, factor);
    }
    }
    mpz_clears(n, factor, cofactor, NULL);
    free(line);
    fclose(file);

    return 0;
}
