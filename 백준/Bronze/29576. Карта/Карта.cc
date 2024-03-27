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
	paper *= k;
	time++;
	while (paper < n)
	{
		paper = paper + (k - 1);
		time++;
	}
	if (paper == n)
		cout << time;
	else
		cout << -1;

	return 0;
}