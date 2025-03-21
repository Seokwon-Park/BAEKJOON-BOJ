#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

pii v[200005];
int room[3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int s, e;
		cin >> s >> e;
		v[i] = { s,e };
	}

	sort(v, v + n, [](auto a, auto b)
		{
			if (a.second == b.second)
			{
				return a.first < b.first;
			}
			return a.second< b.second;
		});

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int rix = -1;
		int cur = -1;
		for (int j = 0; j < k; j++)
		{
			if (room[j] < v[i].first && room[j] > cur)
			{
				rix = j;
				cur = room[j];
			}
		}
		if (rix != -1)
		{
			room[rix] = v[i].second;
			ans++;

		}
	}
	cout << ans;

	return 0;
}



