#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

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

	for (int i = 0; i < k - 1; i++)
	{
		v.push_back(v[i]);
	}


	int st = 0;
	int en = k;
	int cur = accumulate(v.begin(), v.begin() + k, 0);
	int ans = cur;
	while (en < n + k-1)
	{
		cur -= v[st];
		cur += v[en];
		st++;
		en++;
		ans = max(ans, cur);
	}
	cout << ans;

	

	return 0;
}