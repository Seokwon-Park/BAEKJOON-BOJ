#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int n, w, t, k;
int ans;

void func(int tt, int cur, vector<int> f, int m)
{

	//불관리
	vector<int> dec(n, 0);
	for (int j = 0; j < n; j++)
	{
		if (j == m) continue;
		int ff = 0;//인접 모닥불 수
		if (j - 1 >= 0)
		{
			if (f[j - 1] > 0)
			{
				ff++;
			}
		}
		if (j + 1 < n)
		{
			if (f[j + 1] > 0)
			{
				ff++;
			}
		}
		if (ff == 0) dec[j] += 3;
		else if (ff == 1) dec[j] += 2;
		else dec[j] += 1;
	}
	for (int j = 0; j < n; j++)
	{
		f[j] -= dec[j];
		f[j] = max(f[j], 0);
	}

	if (tt == t-1)
	{
		if (count_if(f.begin(), f.end(), [](auto a) {return a > 0; }) < k)return;
		ans++;
		return;
	}

	func(tt+1, cur, f, cur);

	if (cur > 0)
	{
		func(tt + 1, cur-1, f, cur-1);
	}

	if (cur < n-1)
	{
		func(tt + 1, cur+1, f, cur+1);
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> w >> t >> k;
	vector<int> f(n);
	for (int i = 0; i < n; i++)
	{
		cin >> f[i];
	}

	func(0, w, f, -1);

	cout << ans;
		
	return 0;
}
