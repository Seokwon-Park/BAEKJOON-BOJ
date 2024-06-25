#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

double f[10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	f[0] = 1;
	for (int i = 1; i < 10; i++)
	{
		f[i] = f[i - 1] * (double)i;
	}

	cout << "n e\n";
	cout << "- -----------\n";
	double ans = 0;
	for (int i = 0; i < 10; i++)
	{
		ans += 1.0 / f[i];
		if(i > 2)
			cout << fixed << setprecision(9);
		cout << i << ' ' << ans << '\n';
	}

	return 0;
}