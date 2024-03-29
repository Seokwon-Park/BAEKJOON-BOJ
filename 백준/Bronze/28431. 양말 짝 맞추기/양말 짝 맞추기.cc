#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int socks[10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 5; i++)
	{
		int n;
		cin >> n;
		socks[n]++;
	}

	for (int i =0; i< 10;i++)
	{
		if (socks[i] % 2 == 1)
		{
			cout << i;
			break;
		}
	}

	return 0;
}