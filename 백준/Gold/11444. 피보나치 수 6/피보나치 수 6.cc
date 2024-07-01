#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

vector<vector<ll>> a =
{
	{1,1},
	{1,0}
};

vector<vector<ll>>multiply(vector<vector<ll>> a, vector<vector<ll>> b)
{
	vector<vector<ll>> ret(2, vector<ll>(2,0));
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			ll res = 0;
			for (int k = 0; k < 2; k++)
			{
				res += (a[i][k] % 1000000007) * (b[j][k] % 1000000007);
			}
			ret[i][j] = res % 1000000007;
		}
	}
	return ret;
}

vector<vector<ll>> fast_pow(vector<vector<ll>> c, ll n)
{
	if (n == 1)
		return c;
	vector<vector<ll>> res = fast_pow(c, n/2);
	if (n % 2 == 0)
	{
		res = multiply(res, res);
	}
	else
	{
		res = multiply(multiply(res, res), c);
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;
	if (n == 1)
	{
		cout << 1;
		return 0;
	}
	 
	vector<vector<ll>> fp = fast_pow(a, n-1);

	cout << fp[0][0];
	



	return 0;
}