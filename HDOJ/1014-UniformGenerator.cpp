#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF){
        int factor = gcd(a,b);
        if(factor==1){
            cout<<setw(10)<<a<<setw(20)<<b<<"     "<<"Good Choice"<<endl;
        }else {
            cout<<setw(10)<<a<<setw(20)<<b<<"     "<<"Bad Choice"<<endl;
        }
    }
    return 0;
}