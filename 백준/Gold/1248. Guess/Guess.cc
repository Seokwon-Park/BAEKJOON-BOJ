#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;

int n;
char b[11][11];
int v[11];
int pfsum[11];

bool checker(int range)
{
	for (int i = 1; i <= range; i++)
	{
		for (int j = i; j <= range; j++)
		{
			if (b[i][j] == '+')
			{
				if (pfsum[j] - pfsum[i - 1] <= 0)
				{
					return false;
				}
			}
			else if (b[i][j] == '-')
			{
				if (pfsum[j] - pfsum[i - 1] >= 0)
				{
					return false;
				}
			}
			else
			{
				if (pfsum[j] - pfsum[i - 1] != 0)
					return false;
			}
		}
	}
	return true;
}

void func(int k)
{
	if (k > n)
	{
		for (int i = 1; i <= n; i++)
		{
			cout << v[i] << ' ';
		}
		exit(0);
	}
	// 초기값 선택부터 하고 그안에서 조건을 맞춰보기.
	if (b[k][k] == '-')
	{
		for (int i = 1; i <= 10; i++)
		{
			pfsum[k] = pfsum[k - 1] - i;
			if (!checker(k))continue;
			v[k] = -i;
			func(k + 1);
			v[k] = i;
			pfsum[k] += i;
		}
	}
	else if (b[k][k] == '+')
	{
		for (int i = 1; i <= 10; i++)
		{
			pfsum[k] = pfsum[k - 1] + i;
			if (!checker(k))continue;
			v[k] = i;
			func(k + 1);
			v[k] = -i;
			pfsum[k] -= i;
		}
	}
	else
	{
		pfsum[k] = pfsum[k - 1];
		if (!checker(k)) return;
		func(k + 1);
		pfsum[k] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			char c;
			cin >> c;
			b[i][j] = c;
		}
	}

	func(1);


	return 0;
}
