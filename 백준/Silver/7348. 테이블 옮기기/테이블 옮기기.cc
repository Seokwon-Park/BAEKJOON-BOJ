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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<pii> v(n);

		vector<int> corridor(205);
		for (int i = 0; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			if (a > b) swap(a, b);
			int st = (a + 1) / 2;
			int en = (b + 1) / 2;

			corridor[st]++;
			corridor[en + 1]--;
		}

		vector<int> pfsum(205);
		for (int i = 1; i < 200; i++)
		{
			pfsum[i] = pfsum[i - 1] + corridor[i];
		}

		cout << *max_element(pfsum.begin(), pfsum.end()) * 10 << '\n';
	}
	return 0;
}