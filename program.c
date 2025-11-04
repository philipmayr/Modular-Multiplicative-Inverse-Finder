// Modular Multiplicative Inverse Finder

#include <stdio.h>
#include <stdint.h>

typedef uint64_t integer;

integer find_greatest_common_divisor(integer first_integer, integer second_integer)
{
    return second_integer ? find_greatest_common_divisor(second_integer, first_integer % second_integer) : first_integer;
}

integer find_modular_multiplicative_inverse(integer invertible_base, integer modulus)
{
    integer quotient, remainder, modular_multiplicative_inverse = 1;

    while (invertible_base != 1)
    {
        quotient = modulus / invertible_base;
        remainder = modulus % invertible_base;

        if (remainder < invertible_base - remainder)
        {
            invertible_base = remainder;
            modular_multiplicative_inverse = (modular_multiplicative_inverse * -quotient) % modulus;
        }
        else
        {
            invertible_base -= remainder; 
            modular_multiplicative_inverse = (modular_multiplicative_inverse * (quotient + 1)) % modulus;
        }
    }

    return modular_multiplicative_inverse;
}

integer main()
{
    integer set_modulus;
    integer invertible_base;

    for (;;)
    {
        printf("Enter the set modulus: ");

        // integer input validation
        // https://jackstromberg.com/2013/02/how-to-validate-numeric-integer-input-in-c/

        integer input, status, buffer;

        status = scanf("%i", & input);

        while (status != 1)
        {
              while ((buffer = getchar()) != EOF && buffer != '\n');

              printf("Invalid input.");
              printf("\n\n");
              printf("Enter the set modulus: ");

              status = scanf("%i", & input);
        }

        set_modulus = input;

        printf("Enter an invertible base (modulated by %i) to find its multiplicative inverse: ", set_modulus);

        status = scanf("%i", & input);

        while (status != 1)
        {
              while ((buffer = getchar()) != EOF && buffer != '\n');

              printf("Invalid input.");
              printf("\n\n");
              printf("Enter an invertible base (modulated by %i) to find its multiplicative inverse: ", set_modulus);

              status = scanf("%i", & input);
        }

        invertible_base = input;

        integer greatest_common_divisor_of_invertible_base_and_set_modulus = find_greatest_common_divisor(invertible_base, set_modulus);

        if (greatest_common_divisor_of_invertible_base_and_set_modulus != 1)
        {
            printf("\n");
            printf("A base is invertible only when it is coprime to the modulus; that is, when the greatest common divisor of the twain is but 1.");
            printf("\n");
            printf("The base %i is not coprime to the modulus %i as their greatest common divisor is %i, which is greater than 1;", invertible_base, set_modulus, greatest_common_divisor_of_invertible_base_and_set_modulus);
            printf("\n");
            printf("Therefore, the base %i, when modulated by %i, is not invertible and has no multiplicative inverse.", invertible_base, set_modulus);
        }
        else
        {
            integer modular_multiplicative_inverse = find_modular_multiplicative_inverse(invertible_base % set_modulus, set_modulus);

            if (modular_multiplicative_inverse < 0)
                modular_multiplicative_inverse += set_modulus;

            printf("The multiplicative inverse of %i (modulated by %i) is %i.", invertible_base, set_modulus, modular_multiplicative_inverse);
        }

        printf("\n\n");
    }

    return 0;
}
