#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string s;
    while(1){
        cin>>s;
        if(s=="0") break;
        int sum = 0;
        for(int i=0;i<s.size();i++){
            sum += s[i]-'0';
        }
        // 九余数定理，一个数的数根就是它对9的余数
        // 数根是一个数的各位数字相加，直到只剩下一个一位数字
        if(sum%9==0) cout<<9<<endl;
        else cout<<sum%9<<endl;
    }    
    return 0;
}