#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll m, k;
	cin >> m >> k;
	
	ll total = 0;
	for (int i = 0; i < k; i++)
	{
		ll st;
		cin >> st;
		total += st;
	}

	if (total % m == 0)
		cout << total / m;
	else
		cout << total / m + 1LL;



	return 0;
}