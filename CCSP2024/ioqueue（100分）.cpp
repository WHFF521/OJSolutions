#include<bits/stdc++.h>
using namespace std;
const int mxlen = 1e3+5;

int t[mxlen];
int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>t[i];
        }        
        sort(t+1,t+n+1);
        int ans1=0,ans2=0;
        for(int i=1;i<=n;i++){
            if(i%2){
                if(t[i]>=ans1){
                    ans1 = t[i]+10;
                }else {
                    ans1 += 10;
                }
            }else {
                if(t[i]>=ans2){
                    ans2 = t[i]+10;
                }else ans2 +=10;
            }
        }
        if(ans1>ans2) swap(ans1,ans2);
        cout<<ans1<<" "<<ans2;
    }
    return 0;
}