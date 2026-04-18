#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
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

	int x, y;
	cin >> x >> y;
	int n;
	cin >> n;
	int ansx = 0;
	int ansy = 0;
	int curd = INF;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		int newd = abs(a - x) + abs(b - y);
		if (newd < curd)
		{
			ansx = a;
			ansy = b;
			curd = newd;
		}
	}

	cout << ansx << ' ' << ansy;


	return 0;
}