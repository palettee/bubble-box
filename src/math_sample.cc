#include "math_sample.h"

int factorial(int n) {
    if(n == 1) return 1;

    return n * factorial(n-1);
}

bool isPrime(int n, int i = 2) {
    if(n <= 2) return ( n == 2 ) ? true : false;

    if(n % i == 0) return false;
    
    if(i * i > n) return true;
    return isPrime(n, i + 1);
}
