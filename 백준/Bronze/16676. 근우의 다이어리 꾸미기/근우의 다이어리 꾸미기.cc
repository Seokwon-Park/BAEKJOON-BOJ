#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	
	if (n == 0)
	{
		cout << 1;
		return 0;
	}

	int tmp = n;
	int cnt = 0;
	while (tmp)
	{
		cnt++;
		tmp /= 10;
	}

	ll mx = 0;
	for (int i = 0; i < cnt; i++)
	{
		mx = mx * 10 + 1;
	}
	if (mx <= n)
		cout << cnt;
	else
		cout << cnt - 1;




	return 0;
}

