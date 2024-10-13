struct node{
    int id;
    int indegree;
    bool operator < (const node& x) const {
        if(indegree == x.indegree) return id > x.id;
        return indegree > x.indegree;
    }
};