#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<cstring>
#define ll long long
using namespace std;
const int mxlen = 1e3+5;

char a[mxlen][mxlen];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>(a[i]+1);
        }
        int ans = 0;
        for(int i=1;i<=min(n,m)/2;i++){
            string v;
            for(int j=i;j<=m-i+1;j++){
                v += a[i][j];
            }
            for(int j=i+1;j<=n-i+1;j++){
                v += a[j][m-i+1];
            }
            for(int j=m-i;j>=i;j--){
                v += a[n-i+1][j];
            }
            for(int j=n-i;j>i;j--){
                v += a[j][i];
            }
            for(int j=i;j<=min(i+2,m-i+1);j++){
                v += a[i][j];
            }
            if(i+2>m-i+1){
                v+=a[i+1][m-i+1];
            }
            size_t pos = 0;
            while((pos = v.find("1543", pos))!=string::npos){
                ans++;
                pos += 4;
            }

        }
        cout<<ans<<endl;
    }
    return 0;
}