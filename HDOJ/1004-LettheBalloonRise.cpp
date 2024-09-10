#include<iostream>
#include<cstdio>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int n;
    while(1){
        cin >> n;
        if(!n) break;
        string s;
        map<string,int> m;
        int max_num = 0;
        string max_s;
        for(int i=0;i<n;i++){
            cin >> s;
            m[s]++;
            if(m[s]>max_num){
                max_num = m[s];
                max_s = s;
            }
        }
        cout << max_s << endl;
    }
    return 0;
}