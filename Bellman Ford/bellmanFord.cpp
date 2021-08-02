#include <bits/stdc++.h>
using namespace std;

int BellmanFord(vector<vector<pair<int,int>>>&g,int s,int n)
{
    vector<int>dist(n,INT_MAX);
    vector<int>parent(n,-1);

    dist[s] = 0;

    for(int i=1;i<n;i++)
        for(int j=0;j<n;j++)
            for(auto k=g[j].begin();k!=g[j].end();++k)
                if(dist[j]!=INT_MAX && dist[k->first]>dist[j]+k->second)
                {
                    dist[k->first] = dist[j] + k->second;
                    parent[k->first] = j;
                }

    for(int i=0;i<n;i++)
        for(auto j=g[i].begin();j!=g[i].end();++j)
            if(dist[i]!=INT_MAX && dist[j->first]>dist[i]+j->second)
            {
                cout<<"Bellman Ford Fails Because It is a Negative edge Cycle";
                return -1;
            }

    cout<<"Vertex"<<"\t\t"<<"Distance"<<"\t\t"<<"Parent"<<"\n";
    for(int i=0;i<dist.size();i++)
        cout<<i<<"\t\t"<<dist[i]<<"\t\t"<<parent[i]<<"\n";
}

int main()
{
    int n,e,a,b,c,s;
    cin>>n>>e;
    vector<vector<pair<int,int>>>g(n,vector<pair<int,int>>());

    for(int i=0;i<e;i++)
    {
        cin>>a>>b>>c;
        g[a].push_back(make_pair(b,c));
    }

    cout<<"Enter the source : ";
    cin>>s;

    BellmanFord(g,s,n);

}
