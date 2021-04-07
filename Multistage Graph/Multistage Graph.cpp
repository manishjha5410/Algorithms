#include <bits/stdc++.h>
using namespace std;
#define INFINITY 9999

int multiStage(vector<vector<pair<int,int>>>&g)
{
    vector<int>dist(g.size(),INFINITY);
    dist[g.size()-1]=0;

    for(int i=g.size()-2;i>=0;i--)
    {
        dist[i]=INFINITY;
        for (auto j=g[i].begin();j!=g[i].end();++j)
        {
            dist[i]=min(dist[i],j->second+dist[j->first]);
        }
    }


    return dist[0];
}

int main()
{
    int n,e,a,b,c;
    cin>>n>>e;
    vector<vector<pair<int,int>>>g(n, vector<pair<int,int>>());

    for(int i=0;i<e;i++)
    {
        cin>>a>>b>>c;
        g[a].push_back(make_pair(b,c));
    }

    cout<<"The shortest distance between source and distance is "<<multiStage(g);
}
