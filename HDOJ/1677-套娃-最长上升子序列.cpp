#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<cmath>
#include<string>
#include<queue>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<functional>
#define ll long long
using namespace std;
struct node {
    int width;
    ll height;
    bool operator<(const node &a)const{
        if(width==a.width) return height<a.height;
        return width>a.width;
    }
};
bool cmp(node a,node b){
    return a.height<b.height;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int m;
        scanf("%d",&m);
        vector<node> v;
        for(int i=0,x,y;i<m;i++){
            scanf("%d%d",&x,&y);
            v.push_back({x,y});
        }
        sort(v.begin(),v.end());
        vector<node> seq;
        for(int i=0;i<v.size();i++){
            vector<node>::iterator iter = upper_bound(seq.begin(),seq.end(),v[i],cmp);
            if(iter == seq.end()) seq.push_back(v[i]);
            else *iter = v[i];
        }
        cout<<seq.size()<<endl;
    }

    return 0;
}