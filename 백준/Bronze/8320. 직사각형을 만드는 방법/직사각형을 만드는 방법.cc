#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			if (i * j <= n)
				cnt++;
		}
	}
	cout << cnt;

	return 0;
}