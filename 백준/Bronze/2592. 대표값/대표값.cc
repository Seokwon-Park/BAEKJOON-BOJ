#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int t[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int mx = INT_MIN;
	int sum = 0;
	
	for (int i = 0; i < 10; i++)
	{
		int n;
		cin >> n;
		sum += n;
		t[n]++;
		mx = max(mx, n);
	}

	cout << sum / 10 << '\n'
		<< max_element(t, t + mx + 1)-t;
	

	return 0;
}