#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#define ll long long
using namespace std;
string ans;
string a,b,c;
int lena,lenb,lenc;
bool vis[205][205];

void dfs(int x,int y,int z){
    if(vis[x][y]) return ;
    if(ans=="yes") return ;
    if(z==lenc){
        ans = "yes";
        return ;
    }
    vis[x][y] = true;
    if(x<lena && a[x]==c[z]){
        dfs(x+1,y,z+1);
    }
    if(y<lenb && b[y]==c[z]){
        dfs(x,y+1,z+1);
    }
}
int main(){
    int T;
    cin>>T;
    for(int t = 1;t<=T;t++){
        
        cin>>a>>b>>c;
        lena = a.length();
        lenb = b.length();
        lenc = c.length();
        ans = "no";
        if(lena+lenb == lenc){
            memset(vis,0,sizeof(vis));
            dfs(0,0,0);
        }
        // cout<<"Data set "<<t<<": "<<ans<<endl;
        printf("Data set %d: %s\n",t,ans.c_str());
    }
    return 0;
}