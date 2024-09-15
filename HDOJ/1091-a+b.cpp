#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#include<vector>
using namespace std;

int main(){
    long long a,b;
    while(scanf("%lld %lld",&a,&b)){
        if(a==0 && b==0)  break;
        cout<<a+b<<endl;
    }
    return 0;
}