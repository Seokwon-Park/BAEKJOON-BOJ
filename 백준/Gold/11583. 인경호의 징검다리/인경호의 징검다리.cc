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
		int n, k;
		cin >> n >> k;
		vector<int> v(n);
		vector<int> two(n);
		vector<int> five(n);
		vector<int> dptwo(n, INF);
		vector<int> dpfive(n, INF);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
			int tmp = v[i];
			while (tmp % 2 == 0)
			{
				tmp /= 2;
				two[i]++;
			}
			while (tmp % 5 == 0)
			{
				tmp /= 5;
				five[i]++;
			}
		}

		dptwo[0] = two[0];
		dpfive[0] = five[0];

		for (int i = 0; i < n - 1; i++)
		{
			int range = min(n - 1, i + k);
			for (int j = i + 1; j <= range; j++)
			{
				dptwo[j] = min(dptwo[j], dptwo[i] + two[j]);
				dpfive[j] = min(dpfive[j], dpfive[i] + five[j]);
			}
		}

		cout << min(dptwo[n - 1], dpfive[n - 1]) << '\n';
	}


	return 0;
}