#include <iostream>

typedef unsigned long long u64;

/* Multiply a and b, and reduce the product modulo m. Remainder is 
   returned */
u64 mulmod64 (u64 a, u64 b, u64 m) {
  unsigned long q, r, t1, t2;
  __asm__
    ( "mulq %3\n\t"
      : "=a" (t1), "=d" (t2)
      : "%0" (a), "rm" (b)
      : "cc");
  __asm__
    ( "divq %4"
      : "=a" (q), "=d" (r)
      : "0" (t1), "1" (t2), "rm" (m)
      : "cc"
      );
  return r;
}

int main() {
  std::cout << mulmod64(10, 20, 198) << '\n';
}
