#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#define ll long long
using namespace std;
int n;
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        cout<<2*n*n-n+1<<endl;
    }
    return 0;
}