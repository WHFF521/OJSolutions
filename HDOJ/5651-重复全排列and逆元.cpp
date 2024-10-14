#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cstring>
// greater引用自functional头文件
#include<functional>
#define ll long long
using namespace std;
const int mod = 1e9+7;

ll factorial(int n){
    ll ans = 1;
    for(int i=1;i<=n;i++){
        ans = ans*i%mod;
    }
    return ans;
}

void exgcd(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1, y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= a / b * x;
}
int main(){
    // 给出字符串s，全排列成回文串的方案数
    // 重复全排列的方案数为n!/a!/b!/c!...
    // 回文数只需要考虑一半字符串的长度的全排列
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        int len = s.size();
        ll ans = 0;
        vector<int> cnt(26,0);
        for(int i=0;i<len;i++){
            cnt[s[i]-'a']++;
        }
        sort(cnt.begin(),cnt.end(),greater<int>());
        int odd_num = 0;
        for(auto num:cnt){
            if(num%2) odd_num++;
            if(num==0) break;
        }
        if(odd_num>1){
            cout<<0<<endl;
            continue;
        }
        ans = factorial(len/2);
        for(auto num:cnt){
            if(num==0) break;
            int x = num/2;
            int y;
            exgcd(factorial(x),mod,x,y);
            if(x<0) x+=mod;
            ans = ans*x%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}