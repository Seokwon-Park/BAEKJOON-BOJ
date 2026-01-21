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
using hashmap = unordered_map<key, value>;

int x[10] = { 1,0,1,2,0,1,2,0,1,2 };
int y[10] = { 3,0,0,0,1,1,1,2,2,2 };

pii func(int h, int m)
{
	int res = INF;
	int resh = 0;
	int resm = 0;
	for (int i = h; i < 100; i += 24)
	{
		for (int j = m; j < 100; j += 60)
		{
			int tmp = 0;
			vector<int> v = { i / 10, i % 10, j / 10, j % 10 };
			for (int k = 0; k < 3; k++)
			{
				tmp += abs(x[v[k + 1]] - x[v[k]]) + abs(y[v[k + 1]] - y[v[k]]);
			}
			if (tmp < res)
			{
				res = tmp;
				resh = i;
				resm = j;
			}
		}
	}
	return { resh , resm };
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int h, m;
	char c;
	cin >> h >> c >> m;

	auto [hh, mm] = func(h, m);
	cout << setw(2) << setfill('0') << hh  << ':' << setw(2) << mm;


	return 0;
}
