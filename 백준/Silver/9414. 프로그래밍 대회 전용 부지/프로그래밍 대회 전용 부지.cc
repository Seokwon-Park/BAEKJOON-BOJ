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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int l;
		vector<int> v;
		while (cin >> l)
		{
			if (l == 0) break;
			v.push_back(l);
		}
		sort(v.begin(), v.end(), greater<int>());
		ll ans = 0;
		for (int i = 0; i < v.size(); i++)
		{
			int price = 2;
			for (int j = 0; j < i + 1; j++)
			{
				price *= v[i];
			}
			ans += price;
			if (ans > 5 * 1000000)
			{
				ans = -1;
				break;
			}
		}
		cout << (ans == -1 ? "Too expensive" : to_string(ans)) << '\n';
	}


	return 0;
}
