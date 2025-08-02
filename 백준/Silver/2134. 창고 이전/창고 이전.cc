#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;
template <typename key, typename value>
using hashm = unordered_map<key, value>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	priority_queue<pair<ll,ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

	for (int i = 0; i < n; i++)
	{
		ll x;
		cin >> x;
		pq.push({ i + 1 , x });
	}

	ll moved = 0;
	ll cost = 0;
	for (int i = 0; i < m; i++)
	{
		ll x;
		cin >> x;
		while (x > 0 && !pq.empty())
		{
			auto [a, b] = pq.top();
			pq.pop();
			if (b > x)
			{
				b -= x;
				moved += x;
				cost += a * x + (i + 1) * x;
				x = 0;
				pq.push({ a,b });
			}
			else
			{
				x -= b;
				moved += b;
				cost += a * b + (i + 1) * b;
			}

		}
	}

	cout << moved << ' ' << cost;



	return 0;
}