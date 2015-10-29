#include <cstdio>
#include <algorithm>
#include <vector>


using namespace std;

int L = 10;
int n = 3;
int x[] = {2, 6, 7};


void solve() {
  int minT = 0;
  for(int i=0; i<n; i++){
    minT = max(minT, min(x[i], L - x[i]));
  }
  int maxT = 0;
  for(int i=0; i<n; i++){
    maxT = max(maxT, max(x[i], L - x[i]));
  }
  printf("%d %d\n", minT, maxT);
}

int main() {
  solve();
}
