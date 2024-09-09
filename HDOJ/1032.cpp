#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int x,y;
    while(scanf("%d%d",&x,&y)!=EOF){
        cout<<x<<" "<<y<<" ";
        int ans = 0;
        if(x>y){
            swap(x,y);
        }
        for(int i=x;i<=y;i++){
            int cnt = 1;
            int temp = i;
            while(temp!=1){
                if(temp%2==0){
                    temp/=2;    
                }else{
                    temp = 3*temp+1;
                }
                cnt++;
            }
            ans = max(ans,cnt);
        }
        cout<<ans<<endl;
    }
    return 0;
}