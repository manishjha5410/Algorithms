#include <bits/stdc++.h>
#define INFINITY 9999

using namespace std;

int findMin(vector<int>sptSet,vector<int>dist)
{
    int Min=dist[0],index=0;
    for(int i=0;i<sptSet.size();i++)
    {
        if(Min>dist[i] || Min==0 && sptSet[i]==INFINITY)
        {
            Min=dist[i];
            index=i;
        }
    }

    return index;
}

int Dijasktra(vector<vector<pair<int,int>>>&g,int s)
{
    vector<int>sptSet(g.size(),INFINITY);
    vector<int>dist(g.size(),INFINITY);
    dist[s] = 0;
    int m = s;

    while(*max_element(sptSet.begin(),sptSet.end())==INFINITY)
    {
        for(auto i=g[m].begin();i!=g[m].end();++i)
            if(sptSet[i->first]==INFINITY && dist[i->first]==INFINITY)
                dist[i->first] = min(dist[i->first],dist[m]+i->second);
        m = findMin(sptSet,dist);
        sptSet[m] = 0;
    }

    for(int i=0;i<dist.size();i++)
        cout<<i<<"\t"<<dist[i]<<"\n";
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

    Dijasktra(g,s);
}
