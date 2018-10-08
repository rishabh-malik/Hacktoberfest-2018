#include <bits/stdc++.h>

using namespace std;

ifstream fin("mfmc.in");
ofstream fout("mfmc.out");

const int INF = numeric_limits<int>::max();

class unit
{
public:
    int cap=0;
    int cost=0;
};

void Bellman(int source,int dest, vector<vector<int>>&path, vector<vector<unit>>&flux,vector<int>&dist)
{
    bitset<355>viz;
    queue<int> q;

    q.push(source);
    dist[source]=0;
    viz[source]=1;

    int current;

    while(!q.empty())
    {
        current=q.front();
        q.pop();
        viz[current]=0;
        for(unsigned i=0;i<path[current].size();i++)
        {
            if(flux[current][path[current][i]].cap > 0 &&
               dist[path[current][i]]>dist[current]+flux[current][path[current][i]].cost)
            {
                dist[path[current][i]]=dist[current]+flux[current][path[current][i]].cost;
                if(!viz[path[current][i]])
                {
                    q.push(path[current][i]);
                    viz[path[current][i]]=1;
                }
            }
        }
    }


}

bool Dijkstra(int source,int dest,vector<vector<int>>&path,vector<vector<unit>>&flux,vector<int>&parent,vector<int>&dist)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    vector<int>dist_d(dist.size(),INF);
    vector<int>dist_u(dist.size(),0);

    int current,cost;

    q.push(make_pair(0,source));
    dist_d[source]=0;
    while(!q.empty())
    {
        tie(cost,current)=q.top();
        q.pop();
        if(cost<=dist_d[current])
        for(unsigned i=0;i<path[current].size();i++)
        {
            if(flux[current][path[current][i]].cap>0)
                if(dist_d[path[current][i]]>dist_d[current]+flux[current][path[current][i]].cost+dist[current]-dist[path[current][i]])
                {
                    dist_d[path[current][i]]=dist_d[current]+flux[current][path[current][i]].cost+dist[current]-dist[path[current][i]];
                    dist_u[path[current][i]]=dist_u[current]+flux[current][path[current][i]].cost;
                    parent[path[current][i]]=current;
                    q.push(make_pair(dist_d[path[current][i]],path[current][i]));
                }
        }
    }

    for(unsigned i=0;i<dist.size();i++)
        dist[i]=dist_u[i];

    if(dist_d[dest]!=INF)
        return true;
    else
        return false;
}

void Update(int &min_cost,int source, int dest, vector<vector<unit>>&flux, vector<int>&dist, vector<int>&parent)
{
    int current=dest,min_flux=flux[parent[current]][current].cap;
    for(current=dest;current!=source;current=parent[current])
    {
        min_flux=min(min_flux,flux[parent[current]][current].cap);
    }

    for(current=dest;current!=source;current=parent[current])
    {
        flux[parent[current]][current].cap-=min_flux;
        flux[current][parent[current]].cap+=min_flux;
    }

    min_cost+=dist[dest]*min_flux;
}


int main()
{
    int n,m,source,dest;
    fin>>n>>m>>source>>dest;
    vector<vector<int>>path(n+1);
    vector<vector<unit>>flux(n+1,vector<unit>(n+1));
    vector<int>dist(n+1,INF);
    vector<int>parent(n+1);

    int x,y,c,z;

    for(;m;m--)
    {
        fin>>x>>y>>c>>z;
        path[x].push_back(y);
        path[y].push_back(x);
        flux[x][y].cap=c;
        flux[x][y].cost=z;
        flux[y][x].cost=-z;
    }

    int min_cost=0;

    Bellman(source,dest,path,flux,dist);

    while(Dijkstra(source,dest,path,flux,parent,dist))
    {
        Update(min_cost,source,dest,flux,dist,parent);
    }

    fout<<min_cost<<'\n';

    return 0;
}
