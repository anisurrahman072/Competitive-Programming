#include <bits/stdc++.h>
using namespace std;
int main()
{
    int node,edge;
    cin>>node>>edge;
    vector <int> edges[100];
    for(int i=0;i<edge;i++)
    {
        int x,y;
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    int edge_id[100]={0};
    int bit[100]={0};
    stack <int> dfs;

    int start;
    cin>>start;
    dfs.push(start);
    while(dfs.size())
    {
        int value=dfs.top();
        cout<<value<<" ";
        dfs.pop();

        while(edge_id[value] < edges[value].size())
        {
            int childValue = edges[value][edge_id[value]];
            edge_id[value]++;
            if(bit[childValue] == 0)
            {
                bit[childValue]=1;
                dfs.push(value);
                dfs.push(childValue);
                break;
            }
        }
    }
}
