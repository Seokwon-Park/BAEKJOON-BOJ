#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int months[13] = { 0 ,31,28,31,30,31,30,31,31,30,31,30,31 };

bool isLeap(int y)
{
	if (y % 400 == 0)
		return true;
	else
	{
		if (y % 100 == 0) return false;
		else if (y % 4 == 0) return true;
		else return false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;

	int ans = 0;
	int curd = 1; /// 0~6 월 to 일 
	curd = (curd + 12) % 7;
	
	
	for (int i = 2019; i <= n; i++)
	{
		for (int j = 1; j <= 12; j++)
		{
			if (curd == 4) ans++;
			if (j == 2)
			{
				if (isLeap(i))
					curd = (curd + months[j]+1) % 7;
				else
					curd = (curd + months[j]) % 7;
			}
			else
			{
				curd = (curd + months[j]) % 7;
			}
		}
	}

	cout << ans;


	return 0;
}