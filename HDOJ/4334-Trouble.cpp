#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cstring>
#define ll long long
using namespace std;
const int mod = 514229;
int n;
bool color[mod+1];
ll haxi[mod+1];
ll a[10][210];
// 注意所有应该是long long的地方
int getHash(ll x){
    int temp = x%mod;
    if(temp<0) temp+=mod;
    while(color[temp]&&haxi[temp]!=x){
        temp = (temp+1)%mod;
    }
    return temp;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        memset(color,0,sizeof(color));
        memset(haxi,0,sizeof(haxi));
        scanf("%d",&n);
        for(int i=1;i<=5;i++){
            for(int j=1;j<=n;j++){
                scanf("%lld",&a[i][j]);
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                ll sum = a[1][i]+a[2][j];
                sum = -sum;
                int ha = getHash(sum);
                color[ha] = 1;
                haxi[ha] = sum;
            }
        }
        string ans = "No";
        for(int i=1;i<=n;i++){
            if(ans=="Yes") break;
            for(int j=1;j<=n;j++){
                if(ans=="Yes") break;
                for(int k=1;k<=n;k++){
                    ll sum = a[3][i]+a[4][j]+a[5][k];
                    int ha = getHash(sum);
                    if(color[ha]){
                        ans = "Yes";
                        break;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}