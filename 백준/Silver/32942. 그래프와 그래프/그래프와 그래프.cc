#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

vector<int> adj[15];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	for (int x = 1; x <= 10; x++)
	{
		for (int y = 1; y <= 10; y++)
		{
			if (a * x + b * y == c)
			{
				adj[x].push_back(y);
			}
		}
	}

	for (int i = 1; i <= 10; i++)
	{
		if (adj[i].empty()) 
			cout << 0;
		else
		{
			for (auto x : adj[i])
				cout << x << ' ';
		}
		cout << '\n';
	}


	return 0;
}