#include<bits/stdc++.h>
using namespace std;
const int mxlen = 1e5+5;

struct node{
    int pid;
    int tid;
    int load;

    bool operator < (const node& x) const{
        if(pid==x.pid) return tid<x.tid;
        return pid<x.pid;
    }
};
set<node> pools;

void solve_CREATE_Proc(){
    int pid,load;
    cin>>pid>>load;
    bool flag = 0;
    for(auto i:pools){
        if(i.pid==pid){
            flag=1;
            break;
        }
    }
    if(flag) return ;
    pools.insert((node){pid,pid,load});
}

void solve_CREATE_Thread(){
    int pid,tid,load;
    cin>>pid>>tid>>load;
    bool flagpid = 0;
    bool flagtid = 0;
    for(auto i:pools){
        if(i.pid==pid){
            flagpid = 1;
            if(i.tid==tid){
                flagtid = 1;
                break;
            }
        }
    }
    if(!flagpid) return ;
    if(flagtid) return ;
    pools.insert((node){pid,tid,load});
}

void solve_DESTROY_Thread(){
    int tid;
    cin>>tid;
    for(auto i:pools){
        if(i.tid==tid){
            pools.erase(i);
            break;
        }
    }
   
}

void solve_CREATE_Shm(){
    int shm_key,size;
    cin>>shm_key>>size;
}
void solve_DESTROY_Shm(){
    int shm_key;
    cin>>shm_key;
}

void solve_MAP_Shm(){
    int tid,size;
    int shm_key;
    unsigned long long va;
    cin>>shm_key>>tid>>va>>size;
}

void solve_UNMAP_Shm(){
    int tid;
    unsigned long long va;
    cin>>tid>>va;
}

void solve_CREATE_Lock(){
    int tid;
    unsigned long long lock_addr;
    cin>>tid>>lock_addr;
}

void solve_DESTROY_Lock(){
    int tid;
    unsigned long long lock_addr;
    cin>>tid>>lock_addr;
}

// bool cmp(node x,node y){
//     if(x.pid==y.pid) return x.tid<y.tid;
//     return x.pid<y.pid;
// }
void solve_SCHEDULE_OPT(){
    vector<node> tmp;
    for(auto i:pools){
        tmp.push_back(i);
    }
    sort(tmp.begin(),tmp.end());
    for(auto i:tmp){
        cout<<"Process (PID): "<<i.pid<<" "<<"Thread(Tid): "<<i.tid<<" "<<"Load: "<<i.load<<endl;
    }
    cout<<"Contention Cost: 0"<<endl;
    tmp.clear();
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin>>T;
    string s;
    while(T--){
        cin>>s;
        if(s=="CREATE_Proc") solve_CREATE_Proc();
        else if(s=="CREATE_Thread") solve_CREATE_Thread();
        else if(s=="DESTROY_Thread") solve_DESTROY_Thread();
        else if(s=="CREATE_Shm") solve_CREATE_Shm();
        else if(s=="DESTROY_Shm") solve_DESTROY_Shm();
        else if(s=="MAP_Shm") solve_MAP_Shm();
        else if(s=="UNMAP_Shm") solve_UNMAP_Shm();
        else if(s=="CREATE_Lock") solve_CREATE_Lock();
        else if(s=="DESTROY_Lock") solve_DESTROY_Lock();
        else if(s=="SCHEDULE_OPT") solve_SCHEDULE_OPT();
    }
    return 0;
}