#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#include<vector>
using namespace std;
int m;
long long gcd(long long a,long long b){
    return b==0?a:gcd(b,a%b);
}
int main(){
    int T;
    cin>>T;
    while (T--)
    {
        cin>>m;
        long long ans = 1;
        long long x;
        for(int i=1;i<=m;i++){
            cin>>x;
            ans = ans/gcd(ans,x)*x;
        }  
        cout<<ans<<endl;
    }
    
    return 0;
}