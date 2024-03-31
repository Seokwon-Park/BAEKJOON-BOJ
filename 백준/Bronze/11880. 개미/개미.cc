#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		ll ab = a + b;
		ll bc = b + c;
		ll ca = a + c;

		cout << min({a*a+bc*bc, b*b + ca*ca, c*c + ab*ab}) << '\n';
	}

	return 0;
}