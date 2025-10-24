#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int main()
{ 
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	double sum = 0;
	vector<double> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		sum += v[i];
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (abs(v[i] - (sum / n)) >= 10.0)
		{
			ans++;
		}
	}

	cout << ans;

	return 0;
}