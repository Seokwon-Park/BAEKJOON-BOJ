#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

ll gcd(ll a, ll b)
{
	if (b == 0)return a;
	return gcd(b, a % b);
}

bool v[2005][2005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int d1, d2;
	cin >> d1 >> d2;
	
	int ans = 0;
	for (int i = d1; i <= d2; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			int g = gcd(i, j);
			int a = j / g;
			int b = i / g;
			if (!v[a][b])
			{
				v[a][b] = true;
				ans++;
			}
		}
	}
	cout << ans;


	return 0;
}