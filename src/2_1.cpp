#include <cstdio>

const int MAX_N = 200;
int memo[MAX_N+1];

int fact(int n){
  if(n==0) return 1;
  return n * fact(n-1);
}

int fib(int n){
  if(n <= 1) return n;
  return fib(n-1) + fib(n-2);
}

int fib2(int n){
  if(n <= 1) return n;
  if(memo[n] != 0) return memo[n];
  return memo[n] = fib2(n-1) + fib2(n-2);
}

int main() {
  int n = 40;
  //printf("%d\n", fact(5));
  printf("%d\n", fib(n));
  //for(int i=0; i<n; i++) printf("%d\n", memo[i]);
}
