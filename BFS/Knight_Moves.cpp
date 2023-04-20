#include <bits/stdc++.h>
#define ll long long
using namespace std;
int MOD = 1e9 + 7;
const int N = 1e6 + 1;
int sc, sr, ec, er;
int dx[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dy[] = {1, -1, -2, -2, -1, 1, 2, 2};
pair<int, int> s;
bool vis[8][8];
bool check(int r, int c)
{
	return r < 8 and r > -1 and c < 8 and c > -1;
}
int bfs()
{
	queue<pair<int, int>> q;
	vis[s.first][s.second] = true;
	q.push(s);
	int level = 0;
	while (q.size()) // loop on levels
	{
		int sz = q.size();
		while (sz--) // loop on ne for level
		{
			// cout << "* ";
			int r = q.front().first;
			int c = q.front().second;
			q.pop();
			// check is end case
			if (r == er and c == ec)
			{
				return level;
			}
			for (int i = 0; i < 8; i++)
			{
				int newr = r + dy[i];
				int newc = c + dx[i];
				if (check(newr, newc) and !vis[newr][newc])
				{
					// push
					q.push({newr, newc});
					vis[newr][newc] = true;
				}
			}
		}
		level++;
	}
}
int main()
{
	string sp, ep;
	while (cin >> sp >> ep)
	{
		s = {sp[1] - '1', sp[0] - 'a'};
		ec = ep[0] - 'a';
		er = ep[1] - '1';
		memset(vis, false, sizeof(vis));
		cout <<"To get from "<<sp<<" to "<<ep<<" takes "<<bfs()<<" knight moves."  << endl;
	}

	return 0;
}