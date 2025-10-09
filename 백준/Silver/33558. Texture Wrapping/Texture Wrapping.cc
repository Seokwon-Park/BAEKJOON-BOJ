#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

void clampToEdge(const vector<vector<char>>& tex, vector<vector<char>>& quad)
{
	int u = tex.size(); 
	int v = tex[0].size();
	int n = quad.size();
	int m = quad[0].size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i < u && j < v)
			{
				quad[i][j] = tex[i][j];
			}
			else
			{
				if (i >= u && j >= v)
				{
					quad[i][j] = tex[u - 1][v - 1];
				}
				else if (i >= u)
				{
					quad[i][j] = tex[u - 1][j];
				}
				else
				{
					quad[i][j] = tex[i][v - 1];
				}
			}
		}
	}
}

void repeat(const vector<vector<char>>& tex, vector<vector<char>>& quad)
{
	int u = tex.size();
	int v = tex[0].size();
	int n = quad.size();
	int m = quad[0].size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			quad[i][j] = tex[i % u][j % v];
		}
	}
}

void repeatMirror(const vector<vector<char>>& tex, vector<vector<char>>& quad)
{
	int u = tex.size();
	int v = tex[0].size();
	int n = quad.size();
	int m = quad[0].size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i < u && j < v)
			{
				quad[i][j] = tex[i][j];
			}
			else
			{
				if (i >= u && j >= v)
				{
					quad[i][j] = quad[i - ((i % u) * 2 + 1)][j - ((j % v) * 2 + 1)];
				}
				else if (i >= u)
				{
					quad[i][j] = quad[i - ((i % u) * 2 + 1)][j];
				}
				else
				{
					quad[i][j] = quad[i][j - ((j % v) * 2 + 1)];
				}
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int u, v;
	cin >> u >> v;
	vector<vector<char>> tex(u, vector<char>(v));
	vector<vector<char>> quad(n, vector<char>(m));
	for (int i = 0; i < u; i++)
	{
		for (int j = 0; j < v; j++)
		{
			cin >> tex[i][j];
		}
	}

	string wrap;
	cin >> wrap;

	if (wrap == "clamp-to-edge")
	{
		clampToEdge(tex, quad);
	}
	else if (wrap == "repeat")
	{
		repeat(tex, quad);
	}
	else
	{
		repeatMirror(tex, quad);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << quad[i][j];
		}
		cout << '\n';
	}


	return 0;
}