#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int sh, sm, ss;
	int eh, em, es;
	char dli;
	cin >> sh >> dli >> sm >> dli >> ss;
	cin >> eh >> dli >> em >> dli >> es;

	int ans = 0;
	int carry = 0;
	if (es - ss < 0)
	{
		ans += es - ss + 60;
		carry = 1;
	}
	else
	{
		ans += es - ss;
	}

	if (em - sm - carry < 0)
	{
		ans += (em - sm - carry + 60) * 60;
		carry = 1;
	}
	else
	{
		ans += (em - sm - carry)*60;
		carry = 0;
	}

	if (eh - sh - carry < 0)
	{
		ans += (eh - sh - carry + 24) * 3600;
	}
	else
	{
		ans += (eh - sh - carry) * 3600;
	}
	cout << ans;

	return 0;
}