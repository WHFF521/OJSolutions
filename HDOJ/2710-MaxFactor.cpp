#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#define ll long long
using namespace std;
const int mxlen = 2e4+5;
int prime[mxlen];
bool isprime[mxlen];
void init(){
    fill(isprime,isprime+mxlen,true);
    isprime[0] = isprime[1] = false;
    for(int i = 2;i<mxlen;i++){
        if(isprime[i]){
            prime[++prime[0]] = i;
        }
        for(int j = 1;j<=prime[0] && i*prime[j]<mxlen;j++){
            isprime[i*prime[j]] = false;
            if(i%prime[j]==0) break;
        }
    }
}
int main(){
    int n;
    init();
    // be careful that the number "1" should be considered as a prime number
    isprime[1] = true;
    while(scanf("%d",&n)!=EOF){
        int ans = 0;
        int ans_prime = 0;
        int x;
        for(int i = 1;i<=n;i++){
            scanf("%d",&x);
            for(int j=x;j>=1;j--){
                if(x%j==0 && isprime[j]){
                    if(j>ans_prime){
                        ans_prime = j;
                        ans = x;
                    }
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }    
    return 0;
}