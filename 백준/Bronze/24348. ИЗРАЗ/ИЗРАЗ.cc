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
	
	vector<ll> abc(3);
	cin >> abc[0] >> abc[1] >> abc[2];
	sort(abc.begin(), abc.end(), greater<ll>());
	
	ll res = max(abc[0] * abc[1] + abc[2], abc[0] +abc[1] - abc[2]);
	cout << res;

	return 0;
}
