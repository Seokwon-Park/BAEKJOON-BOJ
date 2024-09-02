#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

bool isOver(int n)
{
	int res = 0;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			if (i * i == n)
			{
				res += i;
			}
			else
			{
				res += i;
				res += n / i;
			}
		}
	}
	res++;
	return res > n;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		int res = 0;
		bool hasOver = false;
		for (int i = 2; i * i <= n; i++)
		{
			if (n % i == 0)
			{
				if (i * i == n)
				{
					hasOver |= isOver(i);
					res += i;
				}
				else
				{
					res += i;
					res += n / i;
					hasOver |= isOver(i);
					hasOver |= isOver(n/i);
				}
			}
		}
		res += 1; // 1도 약수인데 자기자신은 제외한 약수기때문에 따로
		if (res > n)
		{
			if (!hasOver)
			{
				cout << "Good Bye";
			}
			else
				cout << "BOJ 2022";
		}
		else
		{
			cout << "BOJ 2022";
		}
		cout << '\n';
			
	}
	return 0;
}