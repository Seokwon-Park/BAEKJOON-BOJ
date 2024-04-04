#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int k = to_string(n).size();
	if (k * n < m)
	{
		for (int i = 0; i < n; i++)
		{
			cout << n;
		}
	}
	else
	{
		for (int i = 0; i < m / k; i++)
		{
			cout << n;
		}
		cout << to_string(n).substr(0, m % k);
	}

	return 0;
}
