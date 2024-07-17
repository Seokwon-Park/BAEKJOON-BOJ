#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<vector<int>> v(n, vector<int>(3));
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[i] = { a,b,c };
	}

	sort(v.begin(), v.end(), [](auto a, auto b)
		{
			return a[0] + a[1] > b[0] + b[1];
		});

	int ab = 0;
	int bc = 0;
	int ca = 0;
	for (int i = 0; i < k; i++)
	{
		ab += v[i][0] + v[i][1];
	}

	sort(v.begin(), v.end(), [](auto a, auto b)
		{
			return a[1] + a[2] > b[1] + b[2];
		});
	for (int i = 0; i < k; i++)
	{
		bc += v[i][1] + v[i][2];
	}

	sort(v.begin(), v.end(), [](auto a, auto b)
		{
			return a[0] + a[2] > b[0] + b[2];
		});
	for (int i = 0; i < k; i++)
	{
		ca += v[i][0] + v[i][2];
	}

	cout << max({ ab,bc,ca });


	return 0;
}