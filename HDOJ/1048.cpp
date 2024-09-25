#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#define ll long long
using namespace std;
map<char,char>m;
int main(){
    for(int i=0;i<26;i++){
        m['A'+i] = 'A'+(i+21)%26;
    }
    string s;
    while(getline(cin,s)){
        if(s=="START"||s=="END") continue;
        else if(s=="ENDOFINPUT") break;
        else{
            for(int i=0;i<s.size();i++){
                if(s[i]>='A'&&s[i]<='Z') cout<<m[s[i]];
                else cout<<s[i];
            }
            cout<<endl;
        }
    }
    return 0;
}