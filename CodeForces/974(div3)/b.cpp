#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n,k;
        scanf("%d%d", &n,&k);
        int ans = 1;
        ans = k*(n-k+1+n)/2;
        ans%=2;
        // for(int i=n;i>=n-k+1;i--){
        //     ans+=i;
        //     ans%=2;
        // }
        if(ans==0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}