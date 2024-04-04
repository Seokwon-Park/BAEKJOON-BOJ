#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll n;
	cin >> n;
	string s;
	while (n)
	{
		s.push_back((n % 2)+'0');
		n /= 2;
	}

	string ans = string(s.rbegin(), s.rend());
	cout << ans;

	return 0;
}
