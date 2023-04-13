#include <bits/stdc++.h>
#define ll long long
using namespace std;
int MOD = 1e9 + 7;
const int N = 1e6 + 1;
struct Edge  
{
	int from;
	int to;
	int length;
	Edge(int f, int t, int len)
	{
		from = f;
		to = t;
		length = len;
	}
};
vector<Edge> g;
int M[1000][1000];
vector<pair<int, int>> head[N];
void mainTest()
{
	int n, e;
	cin >> n >> e;
	for (int i = 0; i < e; i++)
	{
		int u, v, c;
		cin >> u >> v;
		g.push_back(Edge(u, v, c));
		g.push_back(Edge(v, u, c));

		M[u][v] = c;
		M[v][u] = c;

		head[u].push_back({v, 0});
		head[v].push_back({u, 0});
	}
	for (int i = 0; i <= n; i++){
		cout<< i << " => ";
		for (int j = 0; j < head[i].size(); j++)
		{
			cout<<head[i][j].first<<" "; 
		}
		cout<<endl;
	}

	for (int i = 0; i < e; i++)
	{
		cout << g[i].from << " " << g[i].to << " " << g[i].length << endl;
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
