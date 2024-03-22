#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string a, b;
	cin >> a >> b;
	ll ans = 0;
	for(char ca:a)
		for (char cb : b)
		{
			ans += (ca - '0') * (cb - '0');
		}

	cout << ans;

	return 0;
}