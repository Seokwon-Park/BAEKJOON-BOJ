#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, l;
	cin >> n >> l;
	vector<int>v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int cur = 0;
	int len = 0;
	vector<int> al(n);
	for (int i = 0; i < n; i++)
	{
		if (len < l)
		{
			len++;
			cur += v[i];
		}
		else
		{
			cur += v[i];
			cur -= v[i - l];
		}
		al[i] = cur;
	}
	
	int ans = 0;
	for (auto i : al)
	{
		if (i <= 138 && i >= 129)
		{
			ans++;
		}
	}
	cout << ans;

	return 0;
}