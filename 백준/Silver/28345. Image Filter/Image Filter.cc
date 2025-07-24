#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;

pii calc(vector<vector<int>>& v, int r, int c)
{
	vector<int> res;
	res.push_back(abs(v[r][c] - 0));
	int A = c - 1 >= 0 ? v[r][c - 1] : 0;
	int B = r - 1 >= 0 ? v[r - 1][c] : 0;
	int C = (c - 1 >= 0 && r - 1 >= 0) ? v[r - 1][c - 1] : 0;

	res.push_back(v[r][c] - A);
	res.push_back(v[r][c] - B);
	res.push_back(v[r][c] - (A+ B) / 2);
	res.push_back(v[r][c] - (A + B - C));
	int minix = min_element(res.begin(), res.end(), [](auto a, auto b)
		{
			return abs(a) < abs(b);
		}) - res.begin();
	return { minix , res[minix] };
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int r, c;
		cin >> r >> c;
		vector<vector<int>> v(r, vector<int>(c));
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cin >> v[i][j];
			}
		}

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				auto [a, b] = calc(v, i, j);
				cout << a << ' ' << b << ' ';
			}
			cout << '\n';
		}

	}

	return 0;
}