#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int mxlen = 1e5+5;
map<string,bool> Hashmp;
map<string,int> seed_in_use;
map<string,bool> seed_in_frozen;
map<string,int> complete;
map<string,int> incompele;




struct announce{
    string info_hash;
    string peer_id;
    string IP;
    ll port;
    ll uploaded;
    ll downloaded;
    ll numwant;
    string event;
    bool operator < (const announce& x) const{
        return info_hash<x.info_hash;
    }
};
void print_one_peer(announce x);
map<string,set<announce> > leecher;
map<string,set<announce> > seeder;

ll string_to_ll(string s){
    ll ans = 0;
    for(int i=0;i<s.length();i++){
        ans*=10;
        ans+=s[i]-'0';
    }
    return ans;
}
void print_announce(announce x);

bool cmp_seeders(announce x,announce y){
    if(x.uploaded==y.uploaded){
        return x.peer_id<y.peer_id;
    }

    return x.uploaded>y.uploaded;
}

bool cmp_leechers(announce x,announce y){
    if(x.downloaded==y.downloaded){
        return x.peer_id<y.peer_id;
    }
    return x.downloaded<y.downloaded;
}

void solve_announce(string s){
    string tmp_name="";
    string tmp_value = "";
    bool flag_space = 0;
    bool flag_equal = 0;
    announce x;
    for(int i=0;i<s.size();i++){
        if(s[i]==' ') {
            flag_space = 1;
            if(tmp_name=="announce") {
                tmp_name="";
                tmp_value="";    
                continue;
            }
            else if(tmp_name=="INFO_HASH"){
                x.info_hash = tmp_value;
            }else if(tmp_name=="PEER_ID"){
                x.peer_id=tmp_value;
            }else if(tmp_name=="IP"){
                x.IP = tmp_value;
            }else if(tmp_name=="PORT"){
                x.port = string_to_ll(tmp_value);
            }else if(tmp_name=="UPLOADED"){
                x.uploaded = string_to_ll(tmp_value);
            }else if(tmp_name=="DOWNLOADED"){
                x.downloaded = string_to_ll(tmp_value);
            }else if(tmp_name=="NUMWANT"){
                x.numwant = string_to_ll(tmp_value);
            }else if(tmp_name=="EVENT"){
                x.event = tmp_value;
            }
            flag_equal = 0;
            tmp_name="";
            tmp_value="";
            continue;
        }
        
        if(s[i]=='='){
            flag_equal = 1;
            continue;
        }
        if(!flag_equal) tmp_name+=s[i];
        if(flag_equal) tmp_value+=s[i]; 
    }
    x.event = tmp_value;
    //print_announce(x);
    if(Hashmp[x.info_hash]==0){
        cout<<"ERROR: Invalid info_hash"<<endl;
        return ;
    }
    if(seed_in_frozen[x.info_hash]){
        cout<<"ERROR: Torrent frozen"<<endl;
        return ;
    }
    if(x.event=="started"){
        // change user to leecher
        seed_in_use[x.info_hash]++;
        leecher[x.info_hash].insert(x);   
        incompele[x.info_hash]++;     
    }else if(x.event=="completed"){
        if(seed_in_use[x.info_hash]>0)seed_in_use[x.info_hash]--;
        // change user to seeder
        seeder[x.info_hash].insert(x);
        complete[x.info_hash]++;
        incompele[x.info_hash]--;
    }else if(x.event=="stopped"){
        if(seed_in_use[x.info_hash]>0)seed_in_use[x.info_hash]--;
        // delete user from leecher and seeder
        leecher[x.info_hash].erase(x);
        seeder[x.info_hash].erase(x);
    }else if(x.event=="empty"){
        // no need to change user
    }

    // if user still exists, update seed's uploaded and downloaded

    // finally return peers list depended on user's status
    
    cout<<"OK: ";
    cout<<"COMPLETE="<<complete[x.info_hash]<<" ";
    cout<<"INCOMPLETE="<<incompele[x.info_hash]<<" ";
    vector<announce> temp_seeder;
    vector<announce> temp_leecher;
    if(leecher[x.info_hash].find(x)!=leecher[x.info_hash].end()){
        if(x.numwant<=seeder[x.info_hash].size()){
            int cnt = 0;
            for(auto i:seeder[x.info_hash]){
                temp_seeder.push_back(i);
                cnt++;
                if(cnt>=x.numwant) break;
            }
            sort(temp_seeder.begin(),temp_seeder.end(),cmp_seeders);
        }else if(x.numwant<=seeder[x.info_hash].size()+leecher[x.info_hash].size()){
            for(auto i:seeder[x.info_hash]){
                temp_seeder.push_back(i);
            }
            int still_need = x.numwant - seeder[x.info_hash].size();
            int cnt = 0;
            for(auto i:leecher[x.info_hash]){
                temp_leecher.push_back(i);
                cnt++;
                if(cnt>=still_need) break;
            }
            sort(temp_seeder.begin(),temp_seeder.end(),cmp_seeders);
            sort(temp_leecher.begin(),temp_leecher.end(),cmp_leechers);
        }else {
             for(auto i:seeder[x.info_hash]){
                temp_seeder.push_back(i);
            }
            for(auto i:leecher[x.info_hash]){
                temp_leecher.push_back(i);
            }
            sort(temp_seeder.begin(),temp_seeder.end(),cmp_seeders);
            sort(temp_leecher.begin(),temp_leecher.end(),cmp_leechers);
        }
        cout<<"PEERS=[";
        bool flag = 0;
        if(temp_seeder.size()){
            int cnt = 0;
            for(auto i:temp_seeder){
                print_one_peer(i);
                cnt++;
                if(cnt!=temp_seeder.size()) cout<<",";
            }
            flag = 1;
        }
        if(temp_leecher.size()){
            if(flag) cout<<",";
            int cnt = 0;
            for(auto i:temp_leecher){
                print_one_peer(i);
                cnt++;
                if(cnt!=temp_leecher.size())cout<<",";
            }
        }

        cout<<"]"<<endl;
    }else if(seeder[x.info_hash].find(x)!=seeder[x.info_hash].end()){
            if(x.numwant<=leecher[x.info_hash].size()){
            int cnt = 0;
            for(auto i:leecher[x.info_hash]){
                temp_leecher.push_back(i);
                cnt++;
                if(cnt>=x.numwant) break;
            }
            sort(temp_leecher.begin(),temp_leecher.end(),cmp_leechers);
        }else if(x.numwant<=leecher[x.info_hash].size()+seeder[x.info_hash].size()){
            for(auto i:leecher[x.info_hash]){
                temp_leecher.push_back(i);
            }
            sort(temp_leecher.begin(),temp_leecher.end(),cmp_leechers);
        }
        cout<<"PEERS=[";
        bool flag = 0;
        if(temp_leecher.size()){
            int cnt = 0;
            for(auto i:temp_leecher){
                print_one_peer(i);
                cnt++;
                if(cnt!=temp_leecher.size()) cout<<",";
            }
            flag = 1;
        }
        if(temp_seeder.size()){
            if(flag) cout<<",";
            int cnt = 0;
            for(auto i:temp_seeder){
                print_one_peer(i);
                cnt++;
                if(cnt!=temp_seeder.size())cout<<",";
            }
        }

        cout<<"]"<<endl;
    }else {
        cout<<"PEERS=[]"<<endl;
    }


}

void solve_add(string s){
    string tmp_name="";
    string tmp_value = "";
    bool flag_space = 0;
    bool flag_equal = 0;
    announce x;
    for(int i=0;i<s.size();i++){
        if(s[i]==' ') {
            flag_space = 1;
            if(tmp_name=="add") {
                tmp_name="";
                tmp_value="";    
                continue;
            }
            else if(tmp_name=="INFO_HASH"){
                x.info_hash = tmp_value;
            }
            flag_equal = 0;
            tmp_name="";
            tmp_value="";
            continue;
        }
        
        if(s[i]=='='){
            flag_equal = 1;
            continue;
        }
        if(!flag_equal) tmp_name+=s[i];
        if(flag_equal) tmp_value+=s[i]; 
    }
    if(Hashmp[tmp_value]==1){
        cout<<"ERROR"<<endl;
    }else {
        cout<<"OK"<<endl;
        Hashmp[tmp_value] = 1;
    }
}
void solve_del(string s){
     string tmp_name="";
    string tmp_value = "";
    bool flag_space = 0;
    bool flag_equal = 0;
    announce x;
    for(int i=0;i<s.size();i++){
        if(s[i]==' ') {
            flag_space = 1;
            if(tmp_name=="add") {
                tmp_name="";
                tmp_value="";    
                continue;
            }
            else if(tmp_name=="INFO_HASH"){
                x.info_hash = tmp_value;
            }
            flag_equal = 0;
            tmp_name="";
            tmp_value="";
            continue;
        }
        
        if(s[i]=='='){
            flag_equal = 1;
            continue;
        }
        if(!flag_equal) tmp_name+=s[i];
        if(flag_equal) tmp_value+=s[i]; 
    }
    if(!Hashmp[tmp_value]){
        cout<<"ERROR"<<endl;
        return;
    }
    if(seed_in_use[tmp_value]){
        cout<<"FROZEN"<<endl;
        seed_in_frozen[tmp_value] = 1;
        return ;
    }
    Hashmp[tmp_value] = 0;
    cout<<"OK"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    while(getline(cin,s)&&s!=""){
        string tmp = s.substr(0,3);
        if(tmp=="ann") solve_announce(s);
        else if(tmp=="add") solve_add(s);
        else if(tmp=="del") solve_del(s);
    }
    return 0;
}


void print_one_peer(announce x){
    cout<<"(";
    cout<<x.peer_id<<","<<x.IP<<","<<x.port;
    cout<<")";
}



void print_announce(announce x){

    cout<<"info_hash: "<<x.info_hash<<endl;
    cout<<"peer_id: "<<x.peer_id<<endl;
    cout<<"IP: "<<x.IP<<endl;
    cout<<"port: "<<x.port<<endl;
    cout<<"uploaded: "<<x.uploaded<<endl;
    cout<<"downloaded: "<<x.downloaded<<endl;
    cout<<"numwant: "<<x.numwant<<endl;
    cout<<"event: "<<x.event<<endl;
}