#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#include<vector>
#define ll long long
using namespace std;

void solve(int n){
    vector<int> v;
    int x;
    for(int i=0;i<n;i++){
        scanf("%d", &x);
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int l = 0,ans = n-2;
    for(int r=2;r<n;r++){
        while(r-l>=2&&v[l]+v[l+1]<=v[r]) l++;
        ans = min(ans,n-(r-l+1));
    }
    printf("%d\n", ans);
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        solve(n);        
    }
    return 0;
}