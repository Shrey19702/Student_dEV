#include<bits/stdc++.h>
using namespace std;
#define n 6

class graph{
    private:
        vector<int> adj[n];
        int distance[n];
        bool visited[n];
         
    public:
    void clear_prev(){
        for(int i=0; i<n; i++){
            visited[i]=0;
            distance[i]=0;
        }
    }

    void crt_edge( int p, int q){
        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    void dfs(int s){
        if(visited[s])
            return;
        else
            visited[s]=1;
        cout<<"visiting-"<<s<<endl;
            visited[n]=1;
        for(auto i: adj[s]){
            dfs(i);
        }
    }

    void bfs(int s){
        queue<int> q;

        q.push(s);
        distance[s]=0;
        visited[s]=1;

        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto i: adj[x]){
                if(visited[i])
                    continue;
                
                visited[i]=1;
                cout<<"visiting-"<<i<<endl;
                distance[i]=distance[x]+1;
                q.push(i);
            }
        }
    }
};

int main(){
    graph g;
    g.crt_edge(1,2);
    g.crt_edge(2,3);
    g.crt_edge(3,5);
    g.crt_edge(2,5);
    g.crt_edge(1,4);

    g.bfs(1);
    return 0;
}
