#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int v[1100];
int lv[1100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int sz = (1 << n) - 1;
	for (int i = 0; i < sz; i++)
	{
		cin >> v[i];
	}

	for (int i = 0; i < n; i++)
	{
		int gap = 1 << (i + 1);
		for (int j = (1 << i)-1; j < sz; j += gap)
		{
			lv[j] = (i+1);
		}
	}

	for(int i = n; i >= 1; i--)
	{
		for (int j = 0; j < sz; j++)
		{
			if (lv[j] == i)
				cout << v[j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}