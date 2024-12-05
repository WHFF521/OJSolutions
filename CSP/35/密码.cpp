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
map<char,int> mp;
void check(string s){
    int len = s.length();
    map<char,int> m;
    bool high = true;
    bool mid = false;
    for(int i=0;i<len;i++){
        m[s[i]]++;
        if(m[s[i]]>2){
            high = false;
        }
        if(mp[s[i]]==3) mid = true;
    }
    if(mid == true){
        mid = false;
        for(int i=0;i<=9;i++){
            if(m[i+'0']>=1){
                mid = true;
                break;
            }
        }
        if(mid){
            mid = false;
            for(int i=0;i<26;i++){
                if(m[i+'a']>=1){
                    mid = true;
                    break;
                }
            }
            for(int i=0;i<26;i++){
                if(m[i+'A']>=1){
                    mid = true;
                    break;
                }
            }
        }
    }
    if(high&&mid){
        cout<<2<<endl;
    }else if(mid){
        cout<<1<<endl;
    }else cout<<0<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    mp['*'] = 3;
    mp['#'] = 3;
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        check(s);
    }
    return 0;
}