#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n / 5; i++)
	{
		cout << 'V';
	}
	for (int i = 0; i < n % 5; i++)
	{
		cout << 'I';
	}

	return 0;
}