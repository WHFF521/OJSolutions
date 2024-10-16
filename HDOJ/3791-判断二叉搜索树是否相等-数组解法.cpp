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
const int mxlen = 1100;

int origin[mxlen];
int test[mxlen];
int n;

void insert(int *array,int x){
    int p = 1;
    while(array[p]){
        if(x<array[p]) p = p*2;
        else p = p*2+1;
    }
    array[p] = x;
}
int main(){
    while(scanf("%d",&n)&&n){
        memset(origin,0,sizeof(origin));
        char s[10];
        scanf("%s",s);
        int len_or = strlen(s);
        for(int i=0;i<len_or;i++){
            insert(origin,s[i]-'0'+1);
        }
        while(n--){
            memset(test,0,sizeof(test));
            scanf("%s",s);
            int len_te = strlen(s);
            if(len_te!=len_or){
                cout<<"NO"<<endl;
                continue;
            }
            for(int i=0;i<len_te;i++){
                insert(test,s[i]-'0'+1);
            }
            bool flag = 1;
            for(int i=1;i<mxlen;i++){
                if(origin[i]!=test[i]){
                    flag = 0;
                    break;
                }
            }
            if(flag) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}