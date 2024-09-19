#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
const int maxn=1e6+5;
int a[maxn],len;
int n;

void factorial(int x){
    memset(a,0,sizeof(a));
    len = 0;
    a[0] = 1;
    for(int i=2;i<=x;i++){
        int c = 0;
        for(int j=0;j<=len;j++){
            int s = a[j]*i+c;
            a[j] = s%10;
            c = s/10;
        }
        while(c){
            len++;
            a[len] = c%10;
            c/=10;
        }
    }
}
int main(){
    while(scanf("%d",&n)!=EOF){
        factorial(n);
        for(int i=len;i>=0;i--){
            cout<<a[i];
        }
        cout<<endl;
    }
    return 0;
}