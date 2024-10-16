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

void AC(){
    cout<<"Accepted"<<endl;
}
void WA(){
    cout<<"Wrong Answer"<<endl;
}
int main(){
    char s[1005];
    while(scanf("%s",s)!=EOF){
        int a=0,b=0,c=0;
        int numz=0,numj=0;
        bool flag = 0;
        for(int i=0;i<strlen(s);i++){
            if(s[i]=='z') {
                numz++;
                if(numz>1) flag = 1;
            }
            else if(s[i]=='j') {
                numj++;
                if(numj>1) flag = 1;
            }
        }
        if(flag||numz==0||numj==0){
            WA();
            continue;
        }
        int pos = 0;
        while(s[pos++]!='z')a++;
        while(s[pos++]!='j')b++;
        c = strlen(s)-a-b-2;
        if(b==1&&a==c) AC();
        else if(b>1&&a*b==c) AC();
        else WA();
    }
    return 0;
}