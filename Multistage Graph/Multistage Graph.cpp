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


/*
8 12
0 1 1
0 2 2
0 3 5
1 4 4
1 5 11
2 4 9
2 5 5
2 6 16
3 6 2
4 7 18
5 7 13
6 7 2

7 11
0 1 3
0 3 2
0 2 8
1 4 7
1 3 5
2 5 6
3 2 4
3 4 5
3 5 12
4 6 5
5 6 2
*/
