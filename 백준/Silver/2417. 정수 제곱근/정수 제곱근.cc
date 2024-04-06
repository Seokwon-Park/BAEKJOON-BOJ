#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ull n;
	cin >> n;
	ull res = sqrt(n);
	if (res * res == n)
		cout << res;
	else
	{
		while (res * res <= n)
			res++;
		cout << res;
	}
		

	return 0;
}