#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#define ll long long
using namespace std;

bool ask(string cur){
    cout<<"? "<<cur<<endl;
    cout<<endl;
    cout.flush();
    bool b;
    cin>>b;
    return b;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        string s="";
        while(s.size()<n){
            if(ask(s+"0")){
                s+="0";
            }else if(ask(s+"1")){
                s+="1";
            }else break;
        }
        while(s.size()<n){
            if(ask("0"+s)){
                s="0"+s;
            }else {s="1"+s;}
        }
        cout<<"! "<<s<<endl;
        cout<<endl;
        cout.flush();
    }
    return 0;
}