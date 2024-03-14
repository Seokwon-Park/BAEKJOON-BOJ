#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b;
	cin >> a >> b;

	if ((a + b) % 2 == 1 || a < b)
	{
		cout << -1;
		return 0;
	}

	int aa = (a + b) / 2;
	int bb = (a - b) / 2;

	if (bb > aa)
		cout << bb << ' ' << aa;
	else cout << aa << ' ' << bb;

	return 0;
}
