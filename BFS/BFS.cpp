#include <bits/stdc++.h>
using namespace std;
int main()
{
    int node,edge;
    cin>>node>>edge;

    vector <int> edges[100];
    for(int i=0; i<edge; i++)
    {
        int x,y;
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    int start,dest;
    cin>>start>>dest;

    int bit[100]= {0};
    queue <int> bfs;
    bfs.push(start);
    bit[start]=1;

    while(bfs.size())
    {
        int an=bfs.front();
        bfs.pop();
        for(int i=0; i<edges[an].size(); i++)
        {
            if(bit[edges[an][i]] == 0)
            {
                bfs.push(edges[an][i]);
                bit[edges[an][i]] = 1;
            }
        }
        cout<<an<<" ";

    }
}
