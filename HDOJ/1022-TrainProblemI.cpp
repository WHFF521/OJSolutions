#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<stack>
using namespace std;
int n;
string o1,o2;
int main(){
    while(scanf("%d",&n)!=EOF){
        stack<char> st;
        cin>>o1>>o2;
        int pos1 = 0,pos2 = 0;
        string ans = "";
        while(pos1<n){
            st.push(o1[pos1++]);
            ans+="in\n";
            while(!st.empty()&&st.top()==o2[pos2]){
                st.pop();
                ans+="out\n";
                pos2++;
            }
        }
        if(st.empty())
        {
            cout<<"Yes."<<endl;
            cout<<ans;
            cout<<"FINISH"<<endl;
        }else {
            cout<<"No."<<endl;
            cout<<"FINISH"<<endl;
        }
    }
    return 0;
}