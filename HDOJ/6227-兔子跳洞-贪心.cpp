#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
const int mxlen = 505;
int n;
int num[mxlen];
int pos[mxlen];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        int cnt = 0;
        int x,pre;
        for(int i=1;i<=n;i++) cin>>pos[i];
        sort(pos+1,pos+n+1);
        int ans = 0;
        for(int i=1;i<=n;i++){
            x = pos[i];
            if(i==1){
                pre = x;
                continue;
            }
            num[++cnt] = x - pre - 1;
            pre = x;
            ans+=num[cnt];
        }
        cout<<ans-min(num[1],num[cnt])<<endl;
    }
    return 0;
}