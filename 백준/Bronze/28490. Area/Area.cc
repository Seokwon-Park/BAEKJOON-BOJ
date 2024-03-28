#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int a[26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int mx = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		int h, w;
		cin >> h >> w;
		mx = max(h * w, mx);
	}
	cout << mx;

	return 0;
}