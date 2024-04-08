#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll x, y;
	cin >> x >> y;
	ll a = y * 100 / x+1;
	if (a == 100 || a == 101)
	{
		cout << -1;
		return 0;
	}
	ll k = (y * 100 - a * x) / (a - 100);
	ll verify = ((y + k) * 100) / (x + k);
	if (verify != a)
		k++;
	
	cout << k;


	return 0;
}