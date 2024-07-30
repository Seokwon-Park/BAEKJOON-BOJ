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
	vector<tiii> v;
	for (int i = 0; i < n; i++)
	{
		int b, p, q, r;
		cin >> b >> p >> q >> r;
		v.push_back({ p * q * r, p+q+r,b });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < 3; i++)
	{
		cout << get<2>(v[i]) << ' ';
	}
	return 0;
}