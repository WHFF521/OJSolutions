#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
map<string,string>mp;
int main(){
    string s;
    string pre="";
    while(cin>>s&&s!="END"){
        if(s=="START") continue;
        if(pre==""){
            pre=s;
            continue;
        }
        mp[s]=pre;
        pre="";
    }
    while(getline(cin,s)&&s!="END"){
        if(s=="START") continue;
        string temp="";
        string ans = "";
        for(int i=0;i<s.size();i++){
            if(s[i]>='a'&&s[i]<='z'){
                temp+=s[i];
            }else{
                if(temp!=""){
                    if(mp.find(temp)!=mp.end()){
                        ans+=mp[temp];
                    }else {
                        ans+=temp;
                    }
                    temp="";
                }
                ans+=s[i];
            }
        }
        if(temp!=""){
            if(mp.find(temp)!=mp.end()){
                ans+=mp[temp];
            }else {
                ans+=temp;
            }
        }
        cout << ans << endl;
    }
    return 0;
}