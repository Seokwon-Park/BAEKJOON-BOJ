#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	while (1)
	{
		string a, b;
		cin >> a >> b;
		if (a == "0" && b == "0") break;
		int ans = 0;
		int n = max(a.size(), b.size());
		a = string(n - a.size(), '0') + a;
		b = string(n - b.size(), '0') + b;
		int carry = 0;
		for (int i = n - 1; i >=0; i--)
		{
			int x = a[i] - '0';
			int y = b[i] - '0';
			carry = (x + y + carry) / 10;
			if (carry)ans++;
		}
		cout << ans << '\n';

	}

	return 0;
}