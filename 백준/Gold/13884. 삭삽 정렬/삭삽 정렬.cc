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

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int k, n;
		cin >> k >> n;
		vector<int> v(n);
		for (auto& i : v) cin >> i;
		vector<int> sorted = v;
		sort(sorted.begin(), sorted.end());
		int cur = -1;
		int len = 0;
		for (int i = 0; i < n; i++)
		{
			int x = sorted[i];
			int ix = 0;
			for (int j = cur+1; j < n; j++)
			{
				if (v[j] == x)
				{
					ix = j;
					break;
				}
			}
			if (ix < cur)
			{
				break;
			}
			else
			{
				cur = ix;
				len++;
			}
		}
		cout << k << ' ' << n - len << '\n';
	}


	return 0;
}