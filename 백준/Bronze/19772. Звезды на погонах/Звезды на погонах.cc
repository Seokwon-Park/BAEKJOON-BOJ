#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

	int rhigh = min(b, c - 1);
	int rlow = max(a, c - d + 1);

	int lhigh = min(b, c - e - 1);
	int llow = a;

	int maximum = 0;
	for(int i = a; i <=b; i++)
	{
		if (i == c - d || i == c - e)continue;
		maximum++;
	}

	cout << max(0, (rhigh - rlow + 1)) + max(0, (lhigh - llow + 1)) << ' ' << maximum;

	return 0;
}
