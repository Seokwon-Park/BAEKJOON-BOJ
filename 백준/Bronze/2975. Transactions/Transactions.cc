#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (1)
	{
		int a, b;
		char c;
		cin >> a >> c >> b;
		if (a == 0 && c == 'W' && b == 0)break;
		if (c == 'W')
		{
			if (a - b < -200)
				cout << "Not allowed";
			else
			{
				a -= b;
				cout << a;
			}
		}
		else
		{
			a += b;
			cout << a;
		}
		cout << '\n';
	}

	return 0;
}
