#include<iostream>
#include<list>
#include<queue>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;
public:
Graph(int V){
    this->V=V;
    adj=new list<int>[V];
}
void addEgde(int v,int w){
    adj[v-1].push_back(w-1);
    adj[w-1].push_back(v-1);
}
void BFS(int a){
    int component=1;
    bool visited[V];
    for(int i=0;i<V;i++){
        visited[i]=false;
    }
    list<int> queue;

    visited[a]=true;
    queue.push_back(a);
    list<int>::iterator i;

    while(!queue.empty()){
        a=queue.front();
        queue.pop_front();
        if(adj[a].empty()){
            visited[a]=true;
        }else{
            for(i=adj[a].begin();i!=adj[a].end();i++){
                if(!visited[*i]){
                    queue.push_back(*i);
                    visited[*i]=true;
                }
            }
        }
        if(queue.empty()==true){
            for(int j=0;j<V;j++){
                if(visited[j]==false){
                    queue.push_back(j);
                    component++;
                    break;
                }
            }
        }
    }
    cout<<component;
}
};

int main(){
    int n,m;
    cin>>n>>m;
    int v,w;
    Graph g(n);
    for(int y=0;y<m;y++){
        cin>>v>>w;
        g.addEgde(v,w);
    }
    g.BFS(v);
    return 0;
}