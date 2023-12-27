#include <bits/stdc++.h>

using namespace std;

vector<vector<long long>> calc(vector<vector<long long>> aa, vector<vector<long long>> bb)
{
	int n = aa.size();
	vector<vector<long long>> res(n);
	for (int i = 0; i < n; i++)
	{
		res[i].resize(n, 0);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				res[i][j] += (aa[i][k] * bb[k][j]) % 1000;
				res[i][j] %= 1000;
			}
			res[i][j] %= 1000;
		}
	}
	return res;
}

vector<vector<long long>> func(vector<vector<long long>> a, long long b)
{
	if (b == 1)
	{
		return a;
	}
	int n = a.size();
	vector<vector<long long>> c(n);
	for (int i = 0; i < n; i++)
	{
		c[i].resize(n, 0);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				c[i][j] = 1;
		}
	}
	while (b)
	{
		if (b % 2 == 1)
		{
			c = calc(c, a);
		}
		a = calc(a, a);
		b /= 2;
	}
	return c;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n, b;
	cin >> n >> b;

	vector<vector<long long>> a(n);
	for (int i = 0; i < n; i++)
	{
		a[i].resize(n, 0);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	vector<vector<long long>> answer = func(a, b);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << answer[i][j] % 1000 << ' ';
		}
		cout << '\n';
	}

	return 0;
}
