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

int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        bool flag = false;
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1]){
                flag = true;
                break;
            }
        }
        if(flag){
            cout<<1<<endl;
        }else {
            cout<<s.length()<<endl;
        }
    }
    return 0;
}