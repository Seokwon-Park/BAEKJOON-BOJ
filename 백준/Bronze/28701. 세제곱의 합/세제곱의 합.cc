#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;

	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		res += i;
	}
	cout << res << '\n';
	cout << res * res << '\n';
	res = 0;
	for (int i = 1; i <= n; i++)
	{
		res += (i*i*i);
	}
	cout << res;

	return 0;
}