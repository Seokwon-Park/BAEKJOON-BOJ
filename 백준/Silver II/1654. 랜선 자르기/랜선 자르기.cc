#include <bits/stdc++.h>


//parametric search
using namespace std;

using ll = long long;

ll arr[10005];
int k, n;


bool solve(ll t)
{
	ll sum = 0;
	for (int i = 0; i < k; i++)
	{
		sum += arr[i] / t;
	}

	return sum >= n;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> n;

	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];
	}

	ll st = 1;
	ll en = INT_MAX;

	while (st < en)
	{
		ll mid = (en + st + 1) / 2;
		if (solve(mid)) st = mid;
		else en = mid - 1;
	}
	cout << st;


	return 0;
}