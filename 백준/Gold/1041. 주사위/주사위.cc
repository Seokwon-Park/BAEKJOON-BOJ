#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<ll> v(6);
	for (int i = 0; i < 6; i++)
	{
		cin >> v[i];
	}

	ll one = *min_element(v.begin(), v.end());
	ll two = INT_MAX;
	ll three = INT_MAX;

	for (int i = 0; i < 6; i++)
	{
		for (int j = i+1; j < 6; j++)
		{
			if ((i == 0 && j == 5) || (i == 1 && j == 4) || (i == 2 && j == 3)) continue;
			two = min(two, v[i] + v[j]);
		}
	}

	three = min(three, v[0] + v[1] + v[2]);
	three = min(three, v[0] + v[1] + v[3]);
	three = min(three, v[0] + v[4] + v[2]);
	three = min(three, v[0] + v[4] + v[3]);
	three = min(three, v[5] + v[1] + v[2]);
	three = min(three, v[5] + v[1] + v[3]);
	three = min(three, v[5] + v[4] + v[2]);
	three = min(three, v[5] + v[4] + v[3]);

	if (n == 1)
	{
		cout << v[0]+v[1]+v[2]+v[3]+v[4]+v[5] - *max_element(v.begin(),v.end());
	}
	else if (n == 2)
	{
		cout << two * 4LL + three * 4LL;
	}
	else
	{
		cout << three * 4LL + (n - 2) * two * 4LL + one * (n - 2) * (n - 2) * 5LL + one * (n - 2) * 4LL + two * (n - 1) * 4LL;
	}
	

	return 0;
}