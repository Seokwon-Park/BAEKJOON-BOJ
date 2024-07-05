#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int tmp;

void i_sort(vector<int>& a, int k)
{
	for (int i = 1; i < a.size(); i++)
	{
		int loc = i - 1;
		int item = a[i];

		while (0 <= loc && item < a[loc])
		{
			a[loc + 1] = a[loc];
			tmp++;
			if (tmp == k)
			{
				cout << a[loc + 1];
				exit(0);
			}
			loc--;
		}
		if (loc + 1 != i)
		{
			a[loc + 1] = item;
			tmp++;
			if (tmp == k)
			{
				cout << a[loc + 1];
				exit(0);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	i_sort(v, k);

	cout << -1;

	return 0;
}