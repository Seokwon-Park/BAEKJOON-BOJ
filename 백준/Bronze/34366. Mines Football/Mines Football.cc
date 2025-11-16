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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m;
	cin >> m;

	int a = 0;
	int b = INF;
	int c = 0;
	int d = INF;
	while (m--)
	{
		int s;
		cin >> s;
		int sum = 0;
		for (int i = 0; i < s; i++)
		{
			int x;
			cin >> x;
			a = max(a, x);
			b = min(b, x);
			sum += x;
		}
		c = max(c, sum);
		d = min(d, sum);
	}
	cout << a << '\n' << b << '\n' << c << '\n' << d;

	return 0;
}