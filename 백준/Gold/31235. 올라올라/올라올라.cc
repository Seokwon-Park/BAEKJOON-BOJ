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

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int st = 0;
	int mx = 0;
	for (int i = 1; i < n; i++)
	{
		if (v[st] <= v[i])
		{
			mx = max(mx, i - st);
			st = i;
		}
	}
	mx = max(mx, n - st);
	cout << mx;


	return 0;
}