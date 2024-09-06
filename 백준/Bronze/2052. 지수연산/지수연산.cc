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

	int n;
	cin >> n;

	stringstream ss;
	ss << fixed << setprecision(300) << pow(0.5, n);
	string res = ss.str();

	while (res.back() == '0')
		res.pop_back();
	cout << res;

	return 0;
}