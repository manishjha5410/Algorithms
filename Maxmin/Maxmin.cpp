#include <bits/stdc++.h>
using namespace std;

pair<int,int> MaxMin(int *arr,int low,int high)
{
    pair<int,int> maxmin, mml, mmr;
    int mid;
    if(low==high)
    {
        maxmin.first = arr[low];
        maxmin.second = arr[high];
    }
    else if(high==low+1)
    {
        if(arr[low]>arr[high])
        {
            maxmin.first = arr[high];
            maxmin.second = arr[low];
        }
        else
        {
            maxmin.first = arr[low];
            maxmin.second = arr[high];
        }
    }
    else
    {
        int mid = (low+high)/2;
        mml = MaxMin(arr,low,mid);
        mmr = MaxMin(arr,mid+1,high);

        if(mml.first>mmr.first)
            maxmin.first = mmr.first;
        else
            maxmin.first = mml.first;

        if(mml.second>mmr.second)
            maxmin.second = mml.second;
        else
            maxmin.second = mmr.second;
    }

    return maxmin;
}


int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    pair<int,int>maxmin = MaxMin(a,0,n-1);

    cout<<"Min is "<<maxmin.first<<" Max is "<<maxmin.second;
}
