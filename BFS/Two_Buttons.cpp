#include <bits/stdc++.h>
#define ll long long
using namespace std;
int MOD = 1e9 + 7;
const int N = 1e5 + 1;
bool vis[N];
int bfs(int n, int m)
{
	queue<int> q;
	q.push(n);
	int level = 0;
	while (q.size())
	{
		int sz = q.size();
		while (sz--)
		{
			int f = q.front();
			q.pop();
			vis[f] = true;
			// check is end case
			if (f == m)
			{
				return level;
			}
			// push
			if (f <= m and !vis[f * 2])
				q.push(f * 2);
			if (f > 1 and !vis[f - 1])
				q.push(f - 1);
		}
		level++;
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	cout << bfs(n, m) << endl;
	return 0;
}