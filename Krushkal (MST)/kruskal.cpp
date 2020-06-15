#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, w;
};
bool operator < (Edge A, Edge B)
{
    return A.w < B.w;
}

vector <Edge> E;
int p[100]; /// Use this array to store a node's representative. If p[4]=1; then 1 is representative of 4;

// To understand this find function read the blog of shafaet vai (Disjoint set DS)
int find(int x)
{
    if(p[x] == x) return x; /** if find a node which is parent to itself, then the node is representative of a subtree. So, this
    representative will be saved in p[x] in next line. As a result, all node will store it's representative to it.**/
    p[x] = find(p[x]);
    return p[x];
}
int krushkal(int n)
{
    sort(E.begin(), E.end()); /// Sort by weight
    int sz=E.size();
    int ans=0;

    for(int i=1; i<=n; i++)
    {
        p[i]=i; /// Make a node parent to itself
    }

    for(int i=0; i<sz; i++)
    {
        if(find(E[i].u) != find(E[i].v)) /// here find() function will return representative of node u & then representative of node v.
        {
            cout<<E[i].u<<" "<<E[i].v<<endl;
            p[p[E[i].u]] = p[E[i].v];  /// akbar jehetu upore find(E[i].v) run koraia felci, tai ai line a p[E[i].v] run korlei cholbe.
            /** ai line ar meaning hocce ==>> akhane p[E[i].u] indicate korce akta subtree ar representative ke. Abar p[E[i].v] indicate
            korce arekta subtree ar representative ke. Akhn ai line die bujhano hocce je, duita subtree aksathe jukto hoe new
            subtree create hobe jar representative hobe p[E[i].v] **/
            ans += E[i].w;
        }
    }
    cout<<"Hello: "<<p[1]<<endl;
    cout<<"Hello: "<<p[2]<<endl;
    cout<<"Hello: "<<p[3]<<endl;
    cout<<"Hello: "<<p[4]<<endl;
    cout<<"Hello: "<<p[5]<<endl;
    cout<<"Hello: "<<p[6]<<endl;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        Edge get;
        get.u = u;
        get.v = v;
        get.w = w;
        E.push_back(get);
    }
    krushkal(n);
}


/**

7 11
1 2 7
1 4 5
2 3 8
2 4 9
2 5 7
4 5 15
4 6 6
3 5 5
5 6 8
5 7 9
6 7 11

**/
