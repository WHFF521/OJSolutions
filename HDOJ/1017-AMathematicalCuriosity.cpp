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
        int n,m;
        int cnt = 0;
        while(1){
            cin>>n>>m;
            if(n==0&&m==0) break;
            int ans = 0;
            for(int i=1;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if((i*i+j*j+m)%(i*j)==0) ans++;
                }
            }
            cout<<"Case "<<++cnt<<": "<<ans<<endl;
        }
        if(T) cout<<endl;
    }
    return 0;
}