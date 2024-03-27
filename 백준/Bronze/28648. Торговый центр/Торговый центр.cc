#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	int ans = INT_MAX;
	while (n--)
	{
		int t, l;
		cin >> t >> l;
		ans = min(ans, t + l);
	}
	cout << ans;
	
	return 0;
}