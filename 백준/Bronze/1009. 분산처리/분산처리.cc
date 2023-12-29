#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int a, b;
		cin >> a >> b;
		int v = 1;
		for (int i = 0; i < b; i++)
		{
			v *= a;
			v %= 10;
		}
		if (v == 0)
			cout << 10 << '\n';
		else
			cout << v << '\n';
	}

	return 0;
}
