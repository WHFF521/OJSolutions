#include<algorithm>
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