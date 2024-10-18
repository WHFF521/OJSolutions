#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<functional>
#define ll long long
using namespace std;
const int mod = 1e9+7;

void exgcd(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1, y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= a / b * x;
}
// 1-两区间不相交的概率
// min(R1,R2)<max(L1,L2)
// 即找两个数a,b, a<b
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        
        int x,y;
        exgcd(2*n,mod,x,y);
        int ans = ((long long)(n+1)*(x%mod+mod))%mod;
        printf("%d\n",(ans+mod)%mod);
    }
    
    return 0;
}