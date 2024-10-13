#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

const int mxlen = 1e5+5;
struct node{
    double x;
    double y;
}points[mxlen];
// sort by x
bool cmpx(node qw,node er){
    if(qw.x==er.x) return qw.y<er.y;
    return qw.x<er.x;
    
}

// sort by y
bool cmpy(node qw,node er){
    if(qw.y==er.y) return qw.x<er.x;
    return qw.y<er.y;
}
// count the distance between two points
// name can not be distance, because there is a function named distance in cmath
double dis(node qw,node er){
    return sqrt((qw.x-er.x)*(qw.x-er.x)+(qw.y-er.y)*(qw.y-er.y));
}  

int n;
node temp[mxlen];
double solve(int l,int r){
    if(l==r) return 1e20;
    // if there are only two points
    if(l+1==r) return dis(points[l],points[r]);
    int mid = (l+r)>>1;
    double d = min(solve(l,mid),solve(mid+1,r));

    // sort by y, otherwise the code will TLE
    int len = 1;
    for(int i=mid;i>=l&&points[mid].x-points[i].x<d;i--) temp[len++] = points[i];
    for(int i=mid+1;i<=r&&points[i].x-points[mid].x<d;i++) temp[len++] = points[i];
    sort(temp+1,temp+len,cmpy);
    for(int i=1;i<len;i++){
        for(int j=i+1;j<len&&temp[j].y-temp[i].y<d;j++){
            d = min(d,dis(temp[i],temp[j]));
        }
    }
    return d;
}
int main(){
    while(1){
        scanf("%d",&n);
        if(!n) break;
        for(int i=1;i<=n;i++){
            scanf("%lf%lf",&points[i].x,&points[i].y);
        }
        sort(points+1,points+n+1,cmpx);
        double ans = solve(1,n);
        printf("%.2f\n",ans/2);
    }
    return 0;
}