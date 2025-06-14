#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	ll total = 0;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int f;
		cin >> f;
		v.push_back(f);
		total += f;
	}

	int bossIndex = 0;
	for (int i = 0; i < n; i++)
	{
		if (total - v[i] == v[i])
		{
			bossIndex = i;
			break;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (i == bossIndex) continue;
		cout << v[i] << ' ';
	}
	cout << v[bossIndex];

	return 0;
}