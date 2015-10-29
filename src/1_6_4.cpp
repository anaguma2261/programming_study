#include <cstdio>
#include <algorithm>
#include <vector>


using namespace std;

const int MAX_N = 1000;
int n = 3;
int m = 10;
int k[] = {1, 3, 5};
int kk[MAX_N * MAX_N];

bool binary_search(int x){
  int l = 0, r = n;
  int i;
  while(r - l >= 1){
    i = (l + r) / 2;
    if(kk[i] == x) return true;
    else if (kk[i] < x) l = i + 1;
    else r = i;
  }
  return false;
}

void solve() {
  for(int c=0; c<n; c++){
    for(int d=0; d<n; d++){
      kk[c * n + d] = k[c] + k[d];
    }      
  }

  sort(kk, kk + n*n);
  bool f = false;

  for(int a=0; a<n; a++){
    for(int b=0; b<n; b++){
      if(binary_search(m - k[a] - k[b])){
	f = true;
	break;
      }      
    }
  }
  if(f) puts("Yes");
  else puts("No");
}

int main() {
  solve();
}
