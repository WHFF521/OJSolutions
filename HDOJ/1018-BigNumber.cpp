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
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        double ans = 0;
        for(int i=1;i<=n;i++){
            ans+=log10(i);
        }
        cout<<(int)ans+1<<endl;
    }
    return 0;
}