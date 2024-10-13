#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>
#define ll long long
using namespace std;

int main(){
    string s;
    map<string,string> m1;
    while(getline(cin,s)&&s!="@END@"){
        int pos = s.find(']');
        string key = s.substr(0,pos+1);
        string value = s.substr(pos+2);
        m1[key] = value;
    }
    int n;
    cin>>n;
    getchar();
    while(n--){
        getline(cin,s);
        if(s[0]=='['){
            if(m1.find(s)==m1.end()){
                cout<<"what?"<<endl;
            }
            else{
                cout<<m1[s]<<endl;
            }
        }
        else {
            bool flag = false;
            for(auto it=m1.begin();it!=m1.end();it++){
                if(it->second==s){
                    string key = it->first;
                    cout<<key.substr(1,key.size()-2)<<endl;
                    flag = true;
                    break;
                }
            }
            if(!flag){
                cout<<"what?"<<endl;
            }
        }

    }
    return 0;
}