#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int cnt[100005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int > v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int st = 0;
	int ed = 0;
	int len = 0;
	int ans = INT_MIN;
	while (ed<n)
	{
		int ins = v[ed];
		if (cnt[v[ed]] < k)
		{
			cnt[v[ed]]++;
			ed++;
			len++;
		}
		else
		{
			cnt[v[st]]--;
			st++;
			len--;
		}
		ans = max(ans, len);
	}
	cout << ans;

	return 0;
}