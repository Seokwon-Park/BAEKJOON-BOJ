#include <bits/stdc++.h>

using namespace std;

vector<int> p(200005, -1);
vector<int> sz(200005, 1);

int find(int x)
{
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

void union_(int a, int b)
{
	a = find(a), b = find(b);
	if (a == b) return;
	if (p[a] == p[b]) p[a]--;
	if (p[a] < p[b])
	{
		p[b] = a;
		sz[a] += sz[b];
	}
	else
	{
		p[a] = b;
		sz[b] += sz[a];
	}
}

int get_size(int x)
{
	x = find(x); 
	return sz[x];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;
	while (tc--)
	{
		unordered_map<string, int> um;

		int n;
		cin >> n;
		int ix = 0;
		for (int i = 0; i < n; i++)
		{
			string a, b;
			cin >> a >> b;
			if (um.find(a) == um.end())
			{
				um[a] = ix++;
			}
			if (um.find(b) == um.end())
			{
				um[b] = ix++;
			}
			union_(um[a], um[b]);
			cout << get_size(um[a]) << '\n';
		}
		fill(p.begin(), p.end(), -1);
		fill(sz.begin(), sz.end(), 1);
	}


	return 0;
}