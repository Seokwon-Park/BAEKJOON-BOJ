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

	int n;
	cin >> n;
	vector<int> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= n; i++)cin >> b[i];
	vector<int> v(n + 1);
	v[0] = INT_MAX;
	for (int i = 1; i <= n; i++)
	{
		int gap = a[i] - b[i];
		if (v[i - 1] > gap)
		{
			v[i] = gap;
		}
		else
		{
			v[i] = v[i - 1];
		}
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int x;
		cin >> x;
		int ix = upper_bound(v.begin(), v.end(), x, greater<int>()) - v.begin();
		cout << ix-1;
		cout << '\n';
	}

	return 0;
}