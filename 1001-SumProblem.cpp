#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main(){

    long long n;
    while (scanf("%lld", &n) != EOF)
    {
        cout<<n*(n+1)/2<<endl<<endl;
    }
    return 0;
}