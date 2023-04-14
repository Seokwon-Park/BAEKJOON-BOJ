#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	int mx = max({ a, b, c });
	int mn = min({ a, b, c });
	int md;
	if (a < mx && a >mn)
		md = a;
	else if (b < mx && b >mn)
		md = b;
	else
		md = c;

	cout << mn << ' ' << md << ' ' << mx;

	return 0;
}

