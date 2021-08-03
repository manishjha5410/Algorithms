#include <bits/stdc++.h>

using namespace std;

int flwoydWarshall(vector<vector<pair<int,int>>>g)
{
    vector<vector<pair<int,int>>>d(g.size(),vector<pair<int,int>>());
    int n = g.size();



    for(int i=0;i<n;i++)
    {
        d[i].resize(n);
        for(int j=0;j<n;j++)
                if(g[i][j].second!=0)
                    d[i][j] = g[i][j];
                else
                {
                    d[i][j].first = j;
                    if(i==j)
                        d[i][j].second = 0;
                    else
                        d[i][j].second = INT_MAX;
                }
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                if(d[k][j].second!=INT_MAX && d[i][k].second!=INT_MAX && d[i][j].second>d[i][k].second+d[k][j].second)
                    d[i][j].second=d[i][k].second+d[k][j].second;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            if(d[i][j].second!=INT_MAX)
                cout<<d[i][j].second<<" ";
            else
                cout<<"INF ";
        cout<<"\n";
    }
}

int main()
{
    int n,e,a,b,c;
    cin>>n>>e;
    vector<vector<pair<int,int>>>g(n,vector<pair<int,int>>());

    for(int i=0;i<n;i++)
        g[i].resize(n);

    for(int i=0;i<e;i++)
    {
        cin>>a>>b>>c;
        g[a][b].first=b;
        g[a][b].second = c;
    }

    flwoydWarshall(g);
}