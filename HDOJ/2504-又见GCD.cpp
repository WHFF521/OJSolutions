#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#define ll long long
using namespace std;

ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}
int main(){
    int T;
    cin>>T;
    while(T--){
        ll a,b;
        cin>>a>>b;
        for(int i=2;i<=a/b+1;i++){
            ll x = b*i;
            ll y = gcd(a,x);
            if(y==b){
                cout<<x<<endl;
                break;
            }
        }
    }
    return 0;
}