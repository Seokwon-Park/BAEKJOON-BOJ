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

	int B;
	cin >> B;
	while (B--)
	{
		int s, n, f, m;
		cin >> s >> n >> f >> m;
		int low = n + m;
		int high = n * f + m;
		bool res = s >= low && s <= high;
		cout << (res ? "YES" : "NO") << '\n';
	}

	return 0;
}