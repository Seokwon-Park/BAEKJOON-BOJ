#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;


 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 1; i < n; i++)
	{
		int tmp = i;
		while (tmp)
		{
			if (tmp % 100 == 50)
			{
				cnt++;
				break;
			}
			tmp /= 10;
		}
		cnt++;
	}
	cout << cnt+1;

	return 0;
}
