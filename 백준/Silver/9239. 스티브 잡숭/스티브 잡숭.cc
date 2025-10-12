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


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	double x;
	cin >> x;
	ll xl = round(x * 10000);
	ll pow = 1;
	vector<ll> ans;
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			ll a = j * (10000 - pow * xl);
			ll b = xl - 100000;

			if (b == 0) continue;
			if (a * b < 0 || a % b != 0) continue;
			ll r = a / b;
			if (r >= 0 && r < pow)
			{
				ll n = j * pow + r;

				if (i == 1 && r != 0)continue;
				ans.push_back(n);
			}
		}
		pow *= 10;
	}

	if (ans.empty())
	{
		cout << "No solution";
	}
	else
	{
		for (auto i : ans)
		{
			cout << i << '\n';
		}
	}

	return 0;
}