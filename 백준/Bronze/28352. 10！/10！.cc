#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll week = 7 * 24 * 60 * 60;
	ll factorial = 1;
	int n;
	cin >> n;
	for (ll i = 1; i <= n; i++)
	{
		factorial *= i;
	}
	cout << factorial / week;


	return 0;
}