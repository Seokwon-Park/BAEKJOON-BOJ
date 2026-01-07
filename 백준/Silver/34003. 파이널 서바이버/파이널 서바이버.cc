#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

char v[8][8];
int safe[8][8];

double combination(int n, int r)
{
	double res = 1;
	for (int i = 1; i <= r; i++)
	{
		res *= (n + 1 - i);
		res /= i;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int cnt = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cin >> v[i][j];
			if (v[i][j] == 'O')
			{
				safe[i][j]++;
				if (i - 1 >= 0) safe[i - 1][j]++;
				if (j - 1 >= 0) safe[i][j - 1]++;
				if (i - 1 >= 0 && j - 1 >= 0) safe[i - 1][j - 1]++;
				cnt++;
			}
		}
	}

	int mx = 0;
	int r = 0;
	int c = 0;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (safe[i][j] > mx)
			{
				r = i;
				c = j;
				mx = safe[i][j];
			}
		}
	}

	double x = 0.0;
	double total = combination(cnt, cnt - 4);
	if (cnt - mx - 4 >= 0)
		x = combination(cnt - mx, cnt - mx - 4);

	cout << r + 1 << ' ' << c + 1 << '\n';
	cout << fixed << setprecision(6) << 1 - (x / total);

	return 0;
}