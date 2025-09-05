#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

vector<string> group[105];
Hash<string, ll> price;
Hash<string, ll> stock;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, m, q;
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++)
	{
		int g, p;
		string h;
		cin >> g >> h >> p;
		group[g].push_back(h);
		price[h] = p;
	}
	
	for (int i = 0; i < q; i++)
	{
		int cmd;
		cin >> cmd;
		string a;
		ll b, c, d, e;
		switch (cmd)
		{
		case 1:
		{
			cin >> a >> b;
			if (price[a] * b <= m)
			{
				m -= price[a] * b;
				stock[a] += b;
			}
			break;
		}
		case 2:
		{
			cin >> a >> b;
			if (stock[a] > 0)
			{
				int sell = min(stock[a], b);
				stock[a] -= sell;
				m += sell * price[a];
			}
			break;
		}
		case 3:
		{
			cin >> a >> c;
			price[a] += c;
			break;
		}
		case 4:
		{
			cin >> d >> c;
			for (int i = 0; i < group[d].size(); i++)
			{
				price[group[d][i]] += c;
			}
			break;
		}
		case 5:
		{
			cin >> d >> e;
			ll rate = 100 + e;
			for (int i = 0; i < group[d].size(); i++)
			{
				price[group[d][i]] = price[group[d][i]] * rate / 100;
				price[group[d][i]] = price[group[d][i]] / 10 * 10;
			}
			break;
		}
		case 6:
		{
			cout << m << '\n';
			break;
		}
		case 7:
		{
			ll result = 0;
			for (auto [name, num] : stock)
			{
				result += price[name] * num;
			}
			cout << m + result << '\n';
			break;
		}
		default:
			break;
		}
	}

	return 0;
}