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

	double v = 0.0;
	int n;
	cin >> n;
	vector<double> vec(n);
	for (double& i : vec)
	{
		cin >> i;
		v = 1.0 - (1.0 - v)*(1 - i/100.0);
		cout << fixed << setprecision(6)<< v * 100.0 << '\n';
	}

	return 0;
}