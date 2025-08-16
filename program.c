// Modular Multiplicative Inverse Finder

#include <stdio.h>

int find_greatest_common_divisor(int first_integer, int second_integer)
{
    return second_integer ? find_greatest_common_divisor(second_integer, first_integer % second_integer) : first_integer;
}

int find_modular_multiplicative_inverse(int multiplicand, int modulus)
{
    if (find_greatest_common_divisor(multiplicand, modulus) != 1) return -1;
    
    int quotient, remainder, modular_multiplicative_inverse = 1;
    
    while (multiplicand != 1)
    {
        quotient = modulus / multiplicand;
        remainder = modulus % multiplicand;
        
        if (remainder < multiplicand - remainder)
        {
            multiplicand = remainder;
            modular_multiplicative_inverse = (modular_multiplicative_inverse * -quotient) % modulus;
        }
        else
        {
            multiplicand -= remainder; 
            modular_multiplicative_inverse = (modular_multiplicative_inverse * (quotient + 1)) % modulus;
        }
    }
    
    return modular_multiplicative_inverse;
}

int main()
{
    int multiplicand = 37;
    int modulus = 73;
    
    int modular_multiplicative_inverse = find_modular_multiplicative_inverse(multiplicand, modulus);
    
    printf("The multiplicative inverse of %i modulated by %i is %i.", multiplicand, modulus, modular_multiplicative_inverse);
    
    return 0;
}
