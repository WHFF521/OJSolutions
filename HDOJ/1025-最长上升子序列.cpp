#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
const int mxlen = 5e5+5;
int n;
int seq[mxlen];
int a[mxlen];
int main(){
    int cnt = 0;
    while(scanf("%d",&n)!=EOF){
        int x,y;
        for(int i=1;i<=n;i++){
            scanf("%d%d",&x,&y);
            a[x]=y;
        }
        memset(seq,0,sizeof(seq));
        int len = 0;
        for(int i=1;i<=n;i++){
            if(a[i]>seq[len]){
                seq[++len] = a[i];
            }else {
                int l=1,r=len;
                while(l<=r){
                    int mid = (l+r)>>1;
                    if(seq[mid]>=a[i]) r = mid-1;
                    else l = mid+1;
                }
                seq[l] = a[i];
            }
        }
        // When the number of roads is greater than 2, an s needs to be added after the road.
        if(len==1) printf("Case %d:\nMy king, at most 1 road can be built.\n\n",++cnt);
        else printf("Case %d:\nMy king, at most %d roads can be built.\n\n",++cnt,len);
    }
    return 0;
}