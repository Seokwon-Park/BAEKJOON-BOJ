#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

map<int, bool> isused;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n + 1);
	v[0] = 0;
	isused[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		v[i] = v[i - 1] - i;
		if (v[i] < 0 || isused[v[i]])
		{
			v[i] = v[i - 1] + i;
		}
		isused[v[i]] = 1;
	}

	cout << v[n];


	return 0;
}