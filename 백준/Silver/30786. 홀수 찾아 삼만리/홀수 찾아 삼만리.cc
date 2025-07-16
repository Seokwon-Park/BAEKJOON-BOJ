#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v[2];
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[(x + y) % 2].push_back(i);
	}

	if (v[0].empty() || v[1].empty())
	{
		cout << "NO";
	}
	else
	{
		cout << "YES\n";
		for (auto i : v[0])
		{
			cout << i << ' ';
		}
		for (auto i : v[1])
		{
			cout << i << ' ';
		}
	}

	return 0;
}