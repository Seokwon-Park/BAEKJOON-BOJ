#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int n, k;
int v[10];
bool isused[10];
int cur;
int ans;

void func(int d)
{
	if (d == n)
	{
		ans++;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (isused[i]) continue;
		if (cur + v[i] - k < 500) continue;
		isused[i] = true;
		cur = cur + v[i] - k;
		func(d + 1);
		cur = cur - v[i] + k;
		isused[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> k;
	cur = 500;
	for(int i = 0; i< n;i ++)
		cin >> v[i];

	func(0);
	
	cout << ans;
	
	return 0;
}