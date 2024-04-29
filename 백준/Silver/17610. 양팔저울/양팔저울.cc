#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int v[14];
int isused[14];
int n;
unordered_map<int, int> m;

void func(int k, int num)
{
	if (k > 0) 
	{
		if (m.find(num) != m.end())
		{
			if (m[num] <= k) return;
			m[num] = min(m[num], k);
		}
		else
			m[num] = k;
	}
	if (k == n)
		return;
	for (int i = 0; i < n; i++)
	{
		if (isused[i]) continue;
		isused[i] = true;
		func(k + 1, num + v[i]);
		if (num < v[i])
			func(k + 1, v[i] - num);
		else
			func(k + 1, num - v[i]);
		isused[i] = false;
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		sum += v[i];
	}

	func(0, 0);

	int ans = 0;
	for (int i = 1; i <= sum; i++)
	{
		if (m[i] == 0)
			ans++;
	}

	cout << ans;


	return 0;
}