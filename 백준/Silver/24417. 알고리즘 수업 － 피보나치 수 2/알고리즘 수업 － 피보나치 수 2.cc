#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

vector<vector<ll>> v
{
	{1,1},
	{1,0}
};

vector<vector<ll>> multiply(vector<vector<ll>> a, vector<vector<ll>> b)
{
	vector<vector<ll>> res(2, vector<ll>(2,0));
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			ll tmp = 0;
			for (int k = 0; k < 2; k++)
			{
				tmp += a[i][k] * b[k][j];
				tmp %= MOD;
			}
			res[i][j] = tmp;
		}
	}
	return res;
}

vector<vector<ll>> fast_pow(ll n)
{
	if (n == 1)
	{
		return v;
	}
	vector<vector<ll>> res(2, vector<ll>(2, 0));
	res = fast_pow(n / 2);
	if (n % 2 == 0)
	{
		return multiply(res, res);
	}
	else
	{
		return multiply(multiply(res, res), v);
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;

	ll noRecur = (n - 2) % MOD;

	

	//f1 = 1 f2 = 1 f3 3 f4 5;
	//=>f1 1 f2 =1 f3 =2
	cout << fast_pow(n)[1][0] << ' ' << noRecur;


	return 0;
}