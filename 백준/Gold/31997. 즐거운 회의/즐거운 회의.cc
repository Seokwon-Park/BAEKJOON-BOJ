#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

vector<int> friends[200005];
bool isIn[200005];

vector<int> in[200005];
vector<int> out[200005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, t;
	cin >> n >> m >> t;

	for (int i = 1; i <= n; i++)
	{
		int st, en;
		cin >> st >> en;
		in[st].push_back(i);
		out[en].push_back(i);
	}

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		friends[u].push_back(v);
		friends[v].push_back(u);

	}
	int couple = 0;

	vector<int> ans;
	for (int i = 0; i <= t; i++)
	{
		for (auto num : out[i])
		{
			isIn[num] = false;
			for (int fr : friends[num])
			{
				if (isIn[fr])
					couple--;
			}
		}

		for (auto num : in[i])
		{
			isIn[num] = true;
			for (int fr : friends[num])
			{
				if (isIn[fr])
					couple++;
			}
		}
		if(i != t)
			ans.push_back(couple);
	}

	for (auto i : ans)
	{
		cout << i << '\n';
	}

	
	
	return 0;
}