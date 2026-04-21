#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int n, t;
int v[10005];

bool solve(int x)
{
	ll res = 0;

	priority_queue<ll, vector<ll>, greater<ll>> pq;

	for (int i = 0; i < x; i++)
	{
		pq.push(v[i]);
	}

	for (int i = x; i < n; i++)
	{
		ll en = pq.top();
		pq.pop();

		pq.push(en + v[i]);
	}

	while (!pq.empty())
	{
		res = pq.top(); pq.pop();
	}

	return res <= t;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);


	cin >> n >> t;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int st = 1;
	int en = n;

	while (st + 1 < en)
	{
		int mid = (st + en) / 2;
		if (solve(mid))
		{
			en = mid;
		}
		else
		{
			st = mid;
		}
	}

	cout << en;


	return 0;
}