#include <bits/stdc++.h>
#define ll long long
using namespace std;
int MOD = 1e9 + 7;
const int N = 1e9 + 1;

map<int, vector<int>> adjList;
map<int,bool> vis;

void dfs(int root)
{
    if (vis[root])
        return;
    vis[root] = true;
    for (int ne : adjList[root])
    {
        dfs(ne);
    }
    cout << root << " ";
}

void mainTest()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    for (auto it : adjList)
    {
        if (it.second.size()==1)
        {
            dfs(it.first);
            break;
        }
    }

    cout << endl;
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
        mainTest();
    return 0;
}
