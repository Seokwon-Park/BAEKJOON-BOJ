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

	int tc;
	cin >> tc;
	while (tc--)
	{
		int d, n, s, p;
		cin >> d >> n >> s >> p;
		int pp = d + n * p;
		int np = n * s;
		if (pp == np)
			cout << "does not matter";
		else if (pp < np)
			cout << "parallelize";
		else
			cout << "do not parallelize";
		cout << '\n';
	}

	return 0;
}