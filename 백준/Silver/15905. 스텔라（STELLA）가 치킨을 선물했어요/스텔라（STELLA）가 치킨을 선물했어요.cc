#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pii> v;
	for (int i = 0; i < n; i++)
	{
		int s, p;
		cin >> s >> p;
		v.push_back({ s,p });
	}

	sort(v.begin(), v.end(), [](const pii& a, const pii& b) 
		{
			if (a.first == b.first)
			{
				return a.first < b.first;
			}
			return a.first > b.first;
		});

	int ans = 0;
	for (int i = 5; i < n; i++)
	{
		if (v[i].first == v[4].first)
			ans++;
	}
	cout << ans;

	return 0;
}