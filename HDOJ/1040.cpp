#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
int n;
int  a[2000];
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}