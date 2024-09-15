#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
int target;
string s;
int b[20];
bool vis[20];
bool flag = 0;
void dfs(int x){
    if(flag) return;
    if(x==5){
        int sum = b[0]-pow(b[1],2)+pow(b[2],3)-pow(b[3],4)+pow(b[4],5);
        if(sum==target){
            flag = 1;
            for(int i=0;i<5;i++){
                cout<<char(b[i]+'A'-1);
            }
            cout<<endl;
        }
        return;
    }
    for(int i=s.size()-1;i>=0;i--){
        if(!vis[i]){
            vis[i]=1;
            b[x] = s[i]-'A'+1;
            dfs(x+1);
            vis[i]=0;
        }
    }
}
int main(){
    while(1){
        memset(vis,0,sizeof(vis));
        flag = 0;
        cin>>target;
        cin>>s;
        if(!target&&!s.compare("END")) break;
        sort(s.begin(),s.end());
        dfs(0);
        if(!flag) cout<<"no solution"<<endl;
    }
    return 0;
}