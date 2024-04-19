#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

ll gcd(ll a, ll b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll a, b;
	cin >> a >> b;
	int res = gcd(a, b);
	string ans = "";
	for(int i = 0; i< res;i ++)
	{
		ans += '1';
	}
	cout << ans;

	return 0;
}
