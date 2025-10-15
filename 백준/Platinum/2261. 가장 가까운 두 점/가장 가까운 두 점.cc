#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
//const int MOD = 1'000'000'007;
const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int n;
pii v[100005];

ll dist(pii a, pii b)
{
	ll x = a.first - b.first;
	ll y = a.second - b.second;
	return x * x + y * y;
}

int func(int st, int en)
{
	if (en - st <= 2)
	{
		ll ret = INF;
		for (int i = st; i < en; i++)
		{
			for (int j = i + 1; j <= en; j++)
			{
				ret = min(ret, dist(v[i], v[j]));
			}
		}
		return ret;
	}
	ll mid = (en + st) / 2;
	ll ret = min(func(st, mid - 1), func(mid + 1, en));

	vector<pii> temp = { v[mid] };
	for (int i = mid - 1; i >= st; i--)
	{
		if (dist({ v[mid].first, 0 }, { v[i].first, 0 }) >= ret) break;
		temp.push_back(v[i]);
	}
	
	for (int i = mid + 1; i <= en; i++)
	{
		if (dist({ v[mid].first, 0 }, { v[i].first, 0 }) >= ret) break;
		temp.push_back(v[i]);
	}

	sort(temp.begin(), temp.end(), [](auto& a, auto& b)
		{
			if (a.second == b.second)
			{
				return a.first < b.first;
			}
			return a.second < b.second;
		});

	for (int i = 0; i < temp.size(); i++)
	{
		for (int j = i + 1; j < temp.size(); j++)
		{
			if (dist({ 0, temp[j].second }, { 0, temp[i].second }) >= ret) break;
			ret = min(ret, dist(temp[i], temp[j]));
		}
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[i] = { x, y };
	}
	sort(v, v + n);

	cout << func(0, n - 1);

	return 0;
}