#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, l, h;
	cin >> n >> l >> h;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	double sum = accumulate(v.begin() + l, v.end() - h, 0);
	double k = n - l - h;
	cout << fixed << setprecision(9);
	cout << sum / k;


	return 0;
}
