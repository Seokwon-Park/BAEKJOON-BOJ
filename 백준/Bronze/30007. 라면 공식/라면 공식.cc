#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int a, b, x;
		cin >> a >> b >> x;
		cout << a * (x - 1) + b << '\n';
	}
	return 0;
}