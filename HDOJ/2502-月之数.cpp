#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#define ll long long
using namespace std;

ll c[21][21];

int main(){
    c[0][0] = 1;
    for(int i = 1;i<=20;i++){
        c[i][0] = 1;
        for(int j = 1;j<=i;j++){
            c[i][j] = c[i-1][j]+c[i-1][j-1];
        }
    }
    int T;
    cin>>T;
    int n;
    while(T--){
        cin>>n;
        ll sum = 0;
        ll cnt = 1;
        for(int i=0;i<=n;i++){
            sum+=c[n-1][i]*(cnt++);
        }
        cout<<sum<<endl;
    }
    return 0;
}