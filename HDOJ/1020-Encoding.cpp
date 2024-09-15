#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#include<vector>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        int len = s.length();
        char pre = s[0];
        int num = 0;
        for(int i=0;i<len;i++){
            if(s[i]!=pre){
                if(num==1){
                    cout<<pre;
                    num = 0;
                }else {
                    cout<<num<<pre;
                    num = 0;
                }
            }
            pre = s[i];
            num++;
        }
        if(num==1)  cout<<pre;
        else cout<<num<<pre;
        cout<<endl;  
    }
    return 0;
}