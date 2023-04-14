#include <bits/stdc++.h>
#define ll long long
using namespace std;
int MOD = 1e9 + 7;
const int N = 1e6 + 1;

vector<int> head[N];
bool vis[N];

void bfs(int root);
void dfs(int root);
void mainTest()
{
	int n, e;
	cin >> n >> e;
	for (int i = 0; i < e; i++)
	{
		int u, v, c;
		cin >> u >> v;

		head[u].push_back(v);
		head[v].push_back(u);
	}
	dfs(1);
}

int main()
{
	int t = 1;
	// cin >> t;  
	while (t--)
		mainTest();
	return 0;
}
void bfs(int root)
{
	queue<int> q;
	q.push(root);
	while (!q.empty())
	{
		int perant = q.front();
		q.pop();
		vis[perant] = true;
		cout << perant << " ";
		for (int i = 0; i < head[perant].size(); i++)
		{
			int v = head[perant][i];
			if (!vis[v])
				q.push(v);
		}
	}
}
void dfs(int perant)
{
	cout << perant << " ";
	if (vis[perant])
		return;
	vis[perant] = true;

	for (int i = 0; i < head[perant].size(); i++)
	{
		int ne = head[perant][i];
		dfs(ne);
	}
}

/*

6 5
1 2
1 3
1 4
2 5
4 6
DFS(Perant):

	mark Perant is vis

	loop ne of Perant:
		if Perant isNot vis:
			DFS(ne)

========================================
BFS:

queue :

loop queue isNot empty:
	Perant = get top queue { 1 }
	mark Perant is vis

	loop ne of Perant:
		if Perant isNot vis:
			push ne

	print Perant

	remove top

output: 1 2 3 4 5 8
*/
