#include <bits/stdc++.h>
#define ll long long
using namespace std;
int MOD = 1e9 + 7;
const int N = 1e6 + 1;

vector<int> adjList[N];
bool vis[N];
bool per[N];

void bfs(int root);
int dfs(int root)
{
    if (vis[root])
    {
        return 0;
    }

    vis[root] = true;
    int res = 1;

    for (int ne : adjList[root])

        res = max(dfs(ne) + 1, res);

    return res;
}

void mainTest()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        if (m == -1)
            continue;
        adjList[m - 1].push_back(i);
        per[i] = true;
    }
    int ans = 1;
    for (int i = 0; i < n; i++)
        if (!per[i])
            ans = max(ans, dfs(i));

    cout << ans << endl;
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
        mainTest();
    return 0;
}
