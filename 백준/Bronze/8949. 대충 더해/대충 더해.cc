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

	string a, b;
	cin >> a >> b;
	int n = max(a.size(), b.size());
	a = string(n - a.size(), '0') + a;
	b = string(n - b.size(), '0') + b;

	string ans;
	
	for (int i = 0; i < n; i++)
	{
		int ai = a[i] - '0';
		int bi = b[i] - '0';
		ans += to_string(ai + bi);
	}
	cout << ans;

	

	return 0;
}