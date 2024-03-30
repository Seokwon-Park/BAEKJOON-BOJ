#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	ll ans = 0;
	string concat;
	while (getline(cin, s))
	{
		concat += s;
	}
	istringstream iss(concat);
	string tmp;
	while (getline(iss, tmp, ','))
	{
		ans += stoll(tmp);
	}
	cout << ans;

	return 0;
}