#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int n1, n2, n3;
	n1 = n;
	n2 = n + 1;
	n3 = n + 2;

	vector<int> v;
	for (int i = 1; i * i <= n1; i++)
	{
		if (n1 % i == 0)
		{
			if (n1 / i == i)
			{
				v.push_back(i);
			}
			else
			{
				v.push_back(i);
				v.push_back(n1 / i);
			}
		}
	}

	vector<int> v2;
	for (int i = 1; i * i <= n3; i++)
	{
		if (n3 % i == 0)
		{
			if (n3 / i == i)
			{
				v2.push_back(i);
			}
			else
			{
				v2.push_back(i);
				v2.push_back(n3 / i);
			}
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v2.size(); j++)
		{
			int a = v[i];
			int b = v2[j];
			int c = n1 / a;
			int d = -n3 / b;
			if (b * c + a * d == n2)
			{
				cout << a << ' ' << b << ' ' << c << ' ' << d;
				return 0;
			}
		}
	}
	cout << -1;


	return 0;
}