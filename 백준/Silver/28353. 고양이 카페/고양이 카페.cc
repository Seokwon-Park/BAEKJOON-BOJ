#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, k;
	cin >> n >> k;
	vector<ll> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	
	sort(v.begin(), v.end());

	int st = 0;
	int en = n - 1;
	int ans = 0;
	while (st < en)
	{
		if (v[st] + v[en] > k)
		{
			en--;
		}
		else
		{
			ans++;
			st++;
			en--;
		}
	}
	cout << ans;


	return 0;
}

