#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	int a, b, c;
	cin >> n >> a >> b >> c;
	a = min(n, a);
	b = min(n, b);
	c = min(n, c);
	cout << a + b + c;

	return 0;
}
