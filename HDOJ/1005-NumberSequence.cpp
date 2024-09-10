#include<iostream>
#include<cstdio>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

int main(){

    int A,B,n;
    while(1){
        cin >> A >> B >> n;
        if(!A&&!B&&!n) break;
        int f[100];
        f[1] = 1;
        f[2] = 1;
        int cycle = 1;
        for(int i=3;i<=60;i++){
            f[i] = (A*f[i-1]+B*f[i-2])%7;
            if(i>5&&f[i]==f[4]&&f[i-1]==f[3]){
                cycle = i-4;
                break;
            }
        }
        if(n<=5){
            cout<<f[n]<<endl;
            continue;
        }
        cout<<f[(n-3)%cycle+3]<<endl;
    }
    return 0;
}