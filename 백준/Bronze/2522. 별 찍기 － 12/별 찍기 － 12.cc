#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int k = 1; k <= n - 1; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (i <= n - k)
				cout << ' ';
			else
				cout << '*';
		}
		cout << '\n';
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (i <=  k-1)
				cout << ' ';
			else
				cout << '*';
		}
		cout << '\n';
	}

	return 0;
}