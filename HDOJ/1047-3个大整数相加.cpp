#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int n;
string add_VeryLongIntegers(string a,string b){
    int len = max(a.size(), b.size());
    while(a.size() < len) a = "0" + a;
    while(b.size() < len) b = "0" + b;
    string ans = "";
    int carry = 0;
    for(int i = len - 1; i >= 0; i--){
        int sum = a[i] - '0' + b[i] - '0' + carry;
        ans = char(sum % 10 + '0') + ans;
        carry = sum / 10;
    }
    if(carry) ans = "1" + ans;
    return ans;
}
int main(){
    scanf("%d", &n);
    string a;
    while(n--){
        string ans = "0";
        while(cin>>a && a != "0"){
            ans = add_VeryLongIntegers(a, ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}