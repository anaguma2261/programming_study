#include <cstdio>
#include <algorithm>
#include <vector>


using namespace std;

const int MAX_N = 1000;
int n = 3, m = 9, k[] = {1, 3, 5};

bool binary_search(int x){
  int l = 0, r = n;
  int i;
  while(r - l >= 1){
    i = (l + r) / 2;
    if(k[i] == x) return true;
    else if (k[i] < x) l = i + 1;
    else r = i;
  }
  return false;
}

void solve() {
  sort(k, k+n);
  bool f = false;

  for(int a=0; a<n; a++){
    for(int b=0; b<n; b++){
      for(int c=0; c<n; c++){
	if(binary_search(m - k[a] - k[b] - k[c])){
	  f = true;
	  break;
	}
      }      
    }
  }
  if(f) puts("Yes");
  else puts("No");
}

int main() {
  solve();
}
