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
        s.replace(s.end()-2,s.end(),"i");
        cout<<s<<endl;
    }
    return 0;
}