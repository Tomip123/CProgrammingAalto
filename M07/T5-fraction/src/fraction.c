#include "fraction.h"
#include <stdlib.h>
#include <stdio.h>


// Declare the structure fraction_st here
struct fraction_st {
    int numerator;
    int denominator;
};


/**
 * \brief Calculates the greatest common divisor of two integers.
 *
 * \details This function finds the greatest common divisor of
 *          of integers u and v using Binary GCD algorithm
 *          See http://en.wikipedia.org/wiki/Binary_GCD_algorithm for
 *          the details.
 *
 * \param u The first integer
 * \param v The second integer
 * \return The greatest common divisor between u and v
 */
unsigned int gcd(unsigned int u, unsigned int v)
{
    // simple cases (termination)
    if (u == v)
        return u;

    if (u == 0)
        return v;

    if (v == 0)
        return u;

    // look for factors of 2
    if (~u & 1) // u is even
    {
        if (v & 1) // v is odd
            return gcd(u >> 1, v);
        else // both u and v are even
            return gcd(u >> 1, v >> 1) << 1;
    }

    if (~v & 1) // u is odd, v is even
        return gcd(u, v >> 1);

    // reduce larger argument
    if (u > v)
        return gcd((u - v) >> 1, v);

    return gcd((v - u) >> 1, u);
}

/**
 * \brief Allocates and initializes a Fraction object
 *
 * \param numerator The numerator of the fraction
 * \param denominator The denominator of the fraction
 * \return A pointer to the allocated fraction
 */
Fraction *setFraction(unsigned int numerator, unsigned int denominator)
{
    Fraction *fraction = malloc(sizeof(Fraction));
    if (fraction == NULL)
        return NULL;

    fraction->numerator = numerator;
    fraction->denominator = denominator;

    return fraction;
    
}

/**
 * \brief Returns the numerator of the fraction f
 *
 * \param f The fraction
 * \return the numerator of f
 */
unsigned int getNum(const Fraction *f)
{
    return f->numerator;
}

/**
 * \brief Returns the denominator of the fraction f
 *
 * \param f The fraction
 * \return The denominator of fraction f
 */
unsigned int getDenom(const Fraction *f)
{
    return f->denominator;
}

/**
 * \brief Frees the memory of a fraction
 *
 * \param f The fraction to be freed.
 */
void freeFraction(Fraction *f)
{
    free(f);
}


/**
 * \brief Compares two fractions
 *
 * \param a The first fraction to be compared
 * \param b The second fraction to be compared
 * \returns -1 if a is smaller than b
 * \returns 0 if a is equal to b
 * \returns 1 is a is larger than b
 */
int compFraction(const Fraction *a, const Fraction *b)
{
    if (a->numerator * b->denominator < b->numerator * a->denominator)
        return -1;
    else if (a->numerator * b->denominator == b->numerator * a->denominator)
        return 0;
    else
        return 1;
    
}

/**
 * \brief Adds two fractions and returns the result as a new fraction
 *
 * \param a The fraction operand of addition
 * \param b The other fraction operand of addition
 * \return A pointer to the new fraction that contains addition of fractions a and b
 */
Fraction *addFraction(const Fraction *a, const Fraction *b)
{
    Fraction *result = malloc(sizeof(Fraction));
    if (result == NULL)
        return NULL;

    result->numerator = a->numerator * b->denominator + b->numerator * a->denominator;
    result->denominator = a->denominator * b->denominator;

    return result;
}

/**
 * \brief Reduces the fraction so that there is no common divisor greater than 1
 *        between its numerator and denominator.
 *
 * \param val the fraction to be reduced.
 */
void reduceFraction(Fraction *val)
{
    unsigned int g = gcd(val->numerator, val->denominator);
    val->numerator /= g;
    val->denominator /= g;
}

/**
 * \brief Prints a fraction as a human readable string in the standard output.
 *
 * \note This function is not graded, but it might help you in debugging.
 *
 * \param val The fraction to be printed.
 */
void printFraction(const Fraction *val)
{
    printf("%d/%d", val->numerator, val->denominator);
}
