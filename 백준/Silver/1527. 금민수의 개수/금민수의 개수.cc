#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

ll a, b;
int n;
int ans = 0;

void func(int k, string s)
{
	ll tmp = stoll(s);
	if (tmp >= a && tmp <= b)
	{
		ans++;
	}
	if (k == n)
		return;
	func(k + 1, s + '4');
	func(k + 1, s + '7');
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> a >> b;
	n = to_string(b).length();

	func(0, "0");

	cout << ans;

	return 0;
}