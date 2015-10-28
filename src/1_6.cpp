#include <cstdio>
#include <algorithm>
#include <vector>


using namespace std;

const int MAX_N = 100;
int n, a[MAX_N];

void solve() {
  int ans = 0;
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      for(int k=j+1; k<n; k++){
	int len = a[i] + a[j] + a[k];
	int ma = max(a[i], max(a[j], a[k]));
	int rest = len - ma;
	if (ma < rest){
	  ans = max(ans, len);
	}
      }
    }
  }
  printf("%d\n", ans);
}

void solve_nlogn() {
  // ソートのオーダでnlogn
  int ans = 0;
  vector<int> v(n);
  for(int i=0;i<n;i++) v[i] = a[i];
  sort(v.begin(), v.end());

  for(int i=2; i<n; i++){
    if(v[i] < v[i-1] + v[i-2]){
      ans = max(ans, v[i] + v[i-1] + v[i-2]);
    }
  }
  printf("%d\n", ans);
}


int main() {
  n = 5;
  int _a [] = {2, 3, 4, 5, 10};
  for(int i=0; i<n; i++){
    a[i] = _a[i];
  }

  solve_nlogn();
}
