#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll n, k;
	cin >> n >> k;
	if (n == 1)
	{
		cout << 0;
		return 0;
	}
	if (n == k)
	{
		cout << 1;
		return 0;
	}
	if (k == 1)
	{
		cout << -1;
		return 0;
	}

	ll time = 0;
	//최초 찢음
	ll paper = 1;
	n--;
	if (n % (k - 1) == 0)
	{
		cout << n / (k - 1);
	}
	else
		cout << -1;

	return 0;
}