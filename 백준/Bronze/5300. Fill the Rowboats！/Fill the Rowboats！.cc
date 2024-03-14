#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << i << ' ';
		if (i % 6 == 0)
		{
			cout << "Go! ";
		}
	}
	if (n % 6 != 0)
		cout << "Go! ";


	return 0;
}