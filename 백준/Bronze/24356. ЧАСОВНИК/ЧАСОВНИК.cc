#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t1, t2, m1, m2;
	cin >> t1 >> m1 >> t2 >> m2;
	int res = 0;
	int carry = 0;
	if (m2 - m1 < 0)
	{
		res += m2 - m1 + 60;
		carry = 1;
	}
	else
	{
		res += m2 - m1;
	}

	if (t2 - t1 - carry < 0)
	{
		res += (t2 - t1 - carry + 24) * 60;
	}
	else
	{
		res += (t2 - t1 - carry) * 60;
	}
	cout << res << ' ' << res / 30;

	return 0;
}