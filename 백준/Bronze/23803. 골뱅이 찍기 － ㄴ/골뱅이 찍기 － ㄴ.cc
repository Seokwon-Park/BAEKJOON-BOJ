#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < 4*n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << '@';
		}
		cout << '\n';
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5*n; j++)
		{
			cout << '@';
		}
		cout << '\n';
	}
	

	return 0;
}