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

	double l;
	int n;
	double t;
	cin >> l >> n >> t;
	bool isDoom = true;
	for (int i = 0; i < n; i++)
	{
		double f, b;
		cin >> f >> b;
		if (l / f + l / b < t)
		{
			isDoom = false;
		}
	}

	cout << (isDoom ? "DOOMED" : "HOPE");

	return 0;
}