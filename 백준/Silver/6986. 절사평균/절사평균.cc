
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
	
	int n, k;
	cin >> n >> k;

	vector<double> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	
	double atotal = 0;
	for (int i = k; i < n - k; i++)
	{
		atotal += v[i];
	}
	double ares = atotal / (n - k * 2);
	cout << fixed << setprecision(2);
	cout << ares + 1e-9 << '\n';


	double btotal = atotal;
	for (int i = 0; i < k; i++)
	{
		btotal += v[k];
		btotal += v[n - k - 1];
	}

	double bres = btotal / n;
	cout << fixed << setprecision(2);
	cout << bres + 1e-9;


	return 0;
}