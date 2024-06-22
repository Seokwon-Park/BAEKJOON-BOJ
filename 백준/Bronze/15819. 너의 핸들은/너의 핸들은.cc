#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, ix;
	cin >> n >> ix;
	vector<string> v(n);
	for (auto& s : v)
		cin >> s;

	sort(v.begin(), v.end());
	cout << v[ix - 1];

	return 0;
}