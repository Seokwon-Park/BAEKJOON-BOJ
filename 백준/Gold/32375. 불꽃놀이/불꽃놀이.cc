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

	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int lb = lower_bound(v.begin(), v.end(),k) - v.begin();
	int ans = n - lb;

	int st = 0;
	int en = lb - 1;

	while (st < en)
	{
		if (v[st] + v[en] < k)
		{
			st++;
		}
		else
		{
			ans++;
			st++;
			en--;
		}
	}
	cout << (ans ? ans : -1);

	return 0;
}