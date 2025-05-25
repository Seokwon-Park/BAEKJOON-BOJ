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

	int n;
	cin >> n;
	vector<int> v(n);


	// A1...An 
	double total = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		total += v[i];
	}
	if (n == 1)
	{
		cout << v[0];
		return 0;
	}

	total /= n;

	sort(v.begin(), v.end());

	double an1 = v[n - 2];

	cout << fixed << setprecision(6) << (total > an1 ? total : an1);


	return 0;
}
