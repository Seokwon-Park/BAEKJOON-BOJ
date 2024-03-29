#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b;
	cin >> a >> b;
	int res = a + b * 7;
	if (res > 30)
		cout << 0;
	else
		cout << 1;

	return 0;
}