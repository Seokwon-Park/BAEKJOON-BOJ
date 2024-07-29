#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

double q[105];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<double> p(4, 0.0);
	for (int i = 0; i < 4; i++)
	{
		cin >> p[i];
	}

	q[0] = 1 - k;
	for (int i = 1; i <= n; i++)
	{
		q[i] = q[i - 1] * p[0] + (1.0 - q[i - 1]) * p[2];
	}

	cout << round(q[n] * 1000) << '\n';
	cout << round((1.0-q[n]) * 1000) << '\n';


	return 0;
}