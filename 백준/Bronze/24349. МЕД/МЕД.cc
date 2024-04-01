#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	int a, b, c;
	cin >> n >> a >> b >> c;
	// 토끼 - 부엉이 a
	// 토끼 - 당나귀 b
	// 부엉이 - 당나귀 c
	// 토, 부, 당 0, 1, 2
	// 시작은 토끼네 집에서
	int cur = 0;
	int honey = 1;
	int moved = 0;
	while (honey < n)
	{
		if (cur == 0)
		{
			if (a < b)
			{
				cur = 1;
				moved += a;
			}
			else
			{
				cur = 2;
				moved += b;
			}
		}
		else if (cur == 1)
		{
			if (a < c)
			{
				cur = 0;
				moved += a;
			}
			else
			{
				cur = 2;
				moved += c;
			}
		}
		else
		{
			if (b < c)
			{
				cur = 0;
				moved += b;
			}
			else
			{
				cur = 1;
				moved += c;
			}
		}
		honey++;
	}

	cout << moved / 100 << ' ' << moved %100;


	return 0;
}