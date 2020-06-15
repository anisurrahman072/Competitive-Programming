#include <bits/stdc++.h>
using namespace std;

int vis[100]={0};
vector <int> vc[100];

void dfsRecursive(int n)
{
    if(vis[n]) return;
    vis[n]=1;
    cout<<n<<endl;
    for(int i=0;i<vc[n].size();i++)
    {
        dfsRecursive(vc[n][i]);
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        vc[a].push_back(b);
        vc[b].push_back(a);
    }

    int startNode;
    cout<<"Enter the node from which  traversing will be started: ";
    cin>>startNode;
    dfsRecursive(startNode);
}

/*

7 7
1 2
1 5
2 5
2 3
5 4
4 3
4 6

*/
