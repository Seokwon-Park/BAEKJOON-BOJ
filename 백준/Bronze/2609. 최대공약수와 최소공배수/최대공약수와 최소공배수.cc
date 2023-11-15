
#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	cout << gcd(n, m) << '\n' << lcm(n, m);

	return 0;
}