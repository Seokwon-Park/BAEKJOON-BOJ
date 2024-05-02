#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	vector<int> belt(n*2);
	vector<bool> robots(n*2);
	for (int i = 0; i < n*2; i++)
	{
		cin >> belt[i];
	}

	int zerocnt= 0;
	int t = 0;
	while (zerocnt < k)
	{
		//한칸 회 전
		int belttmp = belt[belt.size() - 1];
		int robottmp= robots[robots.size() - 1];
		for (int i = 2 * n - 1; i > 0; i--)
		{
			belt[i] = belt[i - 1];
			robots[i] = robots[i - 1];
		}
		belt[0] = belttmp;
		robots[0] = robottmp;
		robots[n - 1] = false; // n번칸은 무조건 내려

		for (int i = n-2; i >=0; i--)
		{
			if (robots[i] && !robots[i+1] && belt[i+1] > 0)
			{
				robots[i + 1] = robots[i];
				robots[i] = false;
				belt[i + 1]--;
				if (belt[i + 1] == 0)
					zerocnt++;
			}
		}
		robots[n - 1] = false; // n번칸은 무조건 내려

		if (belt[0] > 0) // 로봇 올릴 수 있으면 올림
		{
			robots[0] = true;
			belt[0]--; // 내구도 감소
			if (belt[0] == 0)
				zerocnt++;
		}

		t++;
	}

	cout << t;
	

	return 0;
}