#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int MAX=0x7f7f7f;
int n,m,dist[1005][1005];
vector<pair<int,int> >adj[1005];
void dijkstra(int start){
    for(int i=1;i<=n;i++){
        dist[start][i]=MAX;
    }
    dist[start][start]=0;

    //{distanceToStart,vertex}
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,start});

    while(!pq.empty()){
        auto[d,u]=pq.top();
        pq.pop();

        if(d>dist[start][u]){continue;}//经过之前循环中的处理后，现在存储的堆顶元素的d和dist[start][u]比，d已经太大了

        for(auto[v,w]: adj[u]){
            if(dist[start][v]>dist[start][u]+w){//从start到v的距离 > start->u->v的距离时，更新
                dist[start][v]=dist[start][u]+w;
                pq.push({dist[start][v],v});
            }
        }
    }
}
int main()
{  
    cin>>n>>m;
    int u,v,w;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        // arr[u][v]=(arr[u][v]==0?w:(min(arr[u][v],w)));
        // arr[v][u]=(arr[v][u]==0?w:(min(arr[v][u],w)));
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
    }
    for(int i=1;i<=n;i++){
        dijkstra(i);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(dist[i][j]!=MAX)cout<<dist[i][j];
            else cout<<-1;
            cout<<' ';
        }
        if(dist[i][i]!=MAX)cout<<dist[i][i];
        else cout<<-1;
        cout<<'\n';
    }
    return 0;
}
