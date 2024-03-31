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
		int v, e;
		cin >> v >> e;
		cout << 2 - v + e << '\n';
	}

	return 0;
}