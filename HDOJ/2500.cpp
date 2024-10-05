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
    string s = "HDU";
    while(T--){
        cin>>n;
        for(int i =1;i<=n*3;i++){
            for(int j = 1;j<=n;j++){
                cout<<s;
            }
            cout<<endl;
        }
    }
    return 0;
}