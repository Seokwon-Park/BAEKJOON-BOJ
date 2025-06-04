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

	vector<int> div;
	for (int i = 1; i*i <= n; i++)
	{
		if (n % i == 0)
		{
			div.push_back(i);
		}
	}

	int mn = INF;
	int a, b, c;
	for (int i = 0; i < div.size(); i++)
	{
		for (int j = 1; j <= n / div[i]; j++)
		{
			if (n / div[i] % j == 0)
			{
				int aa = div[i];
				int bb = j;
				int cc = n / div[i] / j;
				int res = (aa * bb + bb * cc + cc * aa) * 2;
				if (res < mn)
				{
					mn = res;
					a = aa;
					b = bb;
					c = cc;
				}
			}
		}
	}

	cout << a << ' ' << b << ' ' << c;
	

	return 0;
}