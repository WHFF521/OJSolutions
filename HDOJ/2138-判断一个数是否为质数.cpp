#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#define ll long long
using namespace std;
int n;

int quickPow(int a, int b, int mod) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = (long long)ans * a % mod;
    a = (long long)a * a % mod;
    b >>= 1;
  }
  return ans;
}
bool millerRabin(int x) {
  if (x < 3 || x % 2 == 0) return x == 2;
  if (x % 3 == 0) return x == 3;
  int u = x - 1, t = 0;
  while (u % 2 == 0) u /= 2, ++t;
  for (int i = 0; i < 10; ++i) {
    int a = rand() % (x - 3) + 2, v = quickPow(a, u, x);
    if (v == 1) continue;
    int s;
    for (s = 0; s < t; ++s) {
      if (v == x - 1) break;
      v = (long long)v * v % x;
    }
    if (s == t) return 0;
  }
  return 1;
}
int main(){
    while(scanf("%d",&n)!=EOF){
        int cnt = 0;
        ll x;
        for(int i=1;i<=n;i++){
            scanf("%lld",&x);
            if(millerRabin(x)){
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}