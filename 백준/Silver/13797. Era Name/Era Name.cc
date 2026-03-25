
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



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	while (cin >> n >> q)
	{
		if (n == 0 && q == 0) break;
		vector<pii> v(n);
		vector<string> year(n);
		for (int i = 0; i < n; i++)
		{
			cin >> year[i];
			int x, y;
			cin >> x >> y;
			v[i] = { y - x, y };
		}

		for (int i = 0; i < q; i++)
		{
			int x;
			cin >> x;
			bool find = false;
			for (int j = 0; j < n; j++)
			{
				auto [st, en] = v[j];
				if (x > st && x <= en)
				{
					cout << year[j] << ' ' << x - v[j].first;
					find = true;
					break;
				}
			}
			if (!find)
			{
				cout << "Unknown";
			}
			cout << '\n';
		}

	}


	return 0;
}