#include <bits/stdc++.h>
#define ll long long
using namespace std;
int MOD = 1e9 + 7;
const int N = 1e6 + 1;

vector<int> adjList[N];
bool vis[N];

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
        res += dfs(ne);

    return res;
}
void init(int n)
{
    for (int i = 0; i < n + 5; i++)
    {
        adjList[i].clear();
        vis[i] = 0;
    }
}

void mainTest()
{
    int n, m;
    string s;
    while (true)
    {

        cin >> n >> m;
        if (n == 0 && m == 0)
            return;
        init(n);
        map<string, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            mp[s] = i;
        }
        for (int i = 0; i < m; i++)
        {
            string c, v;
            cin >> c >> v;
            adjList[mp[c]].push_back(mp[v]);
            adjList[mp[v]].push_back(mp[c]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                ans = max(ans, dfs(i));
            }
        }
        cout << ans << endl;
    }
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
        mainTest();
    return 0;
}
