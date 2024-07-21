#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

vector<vector<ll>> arr =
{
	{1, 1},
	{1, 0}
};

vector<vector<ll>> multiply(vector<vector<ll>>a, vector<vector<ll>>b)
{
	vector<vector<ll>> res(2, vector<ll>(2, 0));
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for(int k = 0; k< 2;k++)
			{
				res[i][j] += a[i][k] * b[k][j];
				res[i][j] %= 1000000;
			}
		}
	}
	return res;
}

vector<vector<ll>> fast_pow(vector<vector<ll>> v, ll n)
{
	if (n == 1) return v;
	vector<vector<ll>> res = fast_pow(v, n / 2);
	if (n % 2)
		return multiply(multiply(res,res), v);
	else
		return multiply(res, res);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;
	vector<vector<ll>> ans = fast_pow(arr, n);

	cout << ans[1][0];

	return 0;
}