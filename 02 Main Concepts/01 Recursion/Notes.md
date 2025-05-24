# Recursion: Key Recursive Formulae and Base Cases

---

**Sum of n Numbers**
- Recursive:  
  `sum(n) = sum(n-1) + n`
- Base case:  
  `sum(0) = 0`

**Factorial**
- Recursive:  
  `fact(n) = n * fact(n-1)`
- Base case:  
  `fact(0) = 1`

**Power Calculation**
- Recursive:  
  `pow(m, n) = m * pow(m, n-1)`
- Base case:  
  `pow(m, 0) = 1`

**Fibonacci**
- Recursive:  
  `fib(n) = fib(n-1) + fib(n-2)`
- Base cases:  
  `fib(0) = 0`  
  `fib(1) = 1`

**nCr (Combinations)**
- Recursive:  
  `nCr(n, r) = nCr(n-1, r-1) + nCr(n-1, r)`
- Base cases:  
  `nCr(n, 0) = 1`  
  `nCr(n, n) = 1`

**Taylor Series**
- Recursive:  
  `e(x, n) = 1 + (x/n) * e(x, n-1)`
- Base case:  
  `e(x, 0) = 1`

**Tower of Hanoi**
- Recursive:  
  `TOH(n, A, B, C): TOH(n-1, A, C, B), move disk, TOH(n-1, B, A, C)`
- Base case:  
  `TOH(0, ...)` does nothing

---
