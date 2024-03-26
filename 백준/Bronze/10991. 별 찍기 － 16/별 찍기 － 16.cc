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
		for (int j = 0; j < n-i-1; j++)
		{
			cout << ' ';
		}
		for (int j = 0; j < 2 * (i+1) - 1; j++)
		{
			if (j % 2 == 0)
				cout << '*';
			else
				cout << ' ';
		}
		cout << '\n';
	}

	return 0;
}