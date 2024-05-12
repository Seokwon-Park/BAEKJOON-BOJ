#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

ll factorial[21];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> v(n);
	
	factorial[0] = 1;
	for (ll i = 1; i <= n; i++)
	{
		factorial[i] = factorial[i - 1] * i;
	}
	
	for (int i = 0; i < n; i++)
	{
		v[i] = i + 1;
	}
	
	int cmd;
	cin >> cmd;
	
	if (cmd == 1)
	{
		ll ix;
		cin >> ix;
	
		ix--;
		for (int i = n - 1; i >= 0; i--)
		{
			cout << v[ix / factorial[i]] << ' ';
			v.erase(v.begin() + ix / factorial[i]);
			ix %= factorial[i];
		}
	}
	else
	{
		ll ans = 0; 
		for (int i = n-1 ; i >= 0; i--)
		{
			ll m;
			cin >> m;
			ll ix = find(v.begin(), v.end(), m)-v.begin();
			ans += ix * factorial[i];
			v.erase(v.begin() + ix);
		}
		cout << ans+1;
	}


	return 0;
}