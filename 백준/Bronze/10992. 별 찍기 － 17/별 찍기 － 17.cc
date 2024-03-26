#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			for (int j = 0; j < n - 1; j++)
				cout << ' ';
			cout << '*';
		}
		else if (i == n - 1)
		{
			for (int j = 0; j < n*2-1; j++)
				cout << '*';
		}
		else
		{
			for (int j = 0; j < n - i -1; j++)
				cout << ' ';
			cout << '*';
			for (int j = 0; j < i * 2 - 1; j++)
				cout << ' ';
			cout << '*';

		}
		cout << '\n';
	}

	return 0;
}