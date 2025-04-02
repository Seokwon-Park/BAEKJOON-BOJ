#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int k, d;
	cin >> k >> d;
	int l = k;
	int total = 0;
	int book = 0;
	while (total + l <= d)
	{
		total += l;
		book++;
		l *= 2;
	}
	cout << book;

	return 0;
}