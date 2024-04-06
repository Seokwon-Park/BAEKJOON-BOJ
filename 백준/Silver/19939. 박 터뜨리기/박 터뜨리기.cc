#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	int sum = 0;
	vector<int> v(k);
	for (int i = 1; i <= k; i++)
	{
		sum += i;
		v[i-1] = i;
	}
	if (sum > n)
	{
		cout << -1;
		return 0;
	}
	else if (sum == n)
	{
		cout << k - 1;
	}
	else
	{
		n -= sum;
		int ix = k - 1;
		while (n > 0)
		{
			n -= 1;
			v[ix]++;
			ix--;
			if (ix < 0) ix = k - 1;
		}
		cout << v[k - 1] - v[0];
	}

	return 0;
}