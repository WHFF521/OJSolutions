// 参考tourist的代码
#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<set>
#include<cstring>
#define ll long long
using namespace std;
string s;
set<int> a;
void update(int pos){
    if(0<=pos&&pos<=s.size()-4){
        if(s.substr(pos,4)=="1100"){
            a.insert(pos);
        }else a.erase(pos);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        a.clear();
        cin>>s;
        for(int j=0;j<s.size();j++){
            update(j);
        }
        int q;
        cin>>q;
        int pos,v;
        while(q--){
            cin>>pos>>v;
            pos--;
            s[pos] = char('0'+v);
            for(int j=pos-3;j<=pos;j++){
                update(j);
            }
            cout<<(!a.empty()?"YES":"NO")<<endl;
        }
    }
    return 0;
}