#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string bi = "";
	while (n)
	{
		bi += (n % 2)+'0';
		n /= 2;
	}

	ll res = 0;
	for (int i = bi.size() - 1; i >= 0; i--)
	{
		int num = bi[i] - '0';
		res += num * (1<<(bi.size()-i-1));
	}
	cout << res;

	return 0;
}