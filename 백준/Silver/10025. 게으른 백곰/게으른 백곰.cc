#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	vector<int> v(1000005);
	for (int i = 0; i < n; i++)
	{
		int g, x;
		cin >> g >> x;

		v[x] = g;
	}

	int st = 0;
	int en = min((int)v.size(), k * 2);
	
	int cur = 0;
	for (int i = st; i <= en; i++)
	{
		cur += v[i];
	}

	int ans = cur;
	while (en + 1 < v.size())
	{
		cur -= v[st];
		st++;
		en++;
		cur += v[en];
		ans = max(ans, cur);
	}

	cout << ans;

	return 0;
}