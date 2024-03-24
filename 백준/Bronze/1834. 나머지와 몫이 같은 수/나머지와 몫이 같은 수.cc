#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll n;
	cin >> n;
	ll sum = 0;
	for (int i = 1; i < n; i++)
	{
		sum += i * n + i;
	}
	cout << sum;

	return 0;
}