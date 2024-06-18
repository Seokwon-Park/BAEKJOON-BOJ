#include <bits/stdc++.h>

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
	
	int k;
	cin >> k;
	int n;
	cin >> n;
	int timer = 210;
	int boom = k;
	for (int i = 0; i < n; i++)
	{
		int t;
		char res;
		cin >> t >> res;
		if (timer >= t)
		{
			if (res == 'T')
			{
				k++;
				if (k > 8)
					k = 1;
			}
			timer -= t;
		}
		else
		{
			boom = k;
		}
	}
	cout << k;

	return 0;
}
