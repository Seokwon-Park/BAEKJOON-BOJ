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
	for (int i = 0; i < n; i++)
	{
		ll m;
		cin >> m;
		ll mcopy = m;
		vector<int> v;
		int cnt = 0;// 켜진 비트 수.
		while (mcopy)
		{
			v.push_back(mcopy % 2);
			cnt += mcopy % 2;
			mcopy /= 2;
		}
		if (cnt == 1)
		{
			if (m == 1) // 1이면 0,0
			{
				cout << 0 << ' ' << 0;
			}
			else // 아닌경우 2^k = 2^k-1 + 2^k-1;
			{
				for (int k= v.size()-1; k >= 0; k--)
				{
					if (v[k] == 1)
					{
						cout << k - 1 << ' ' << k - 1;
						break;
					}
				}
			}
		}
		else if (cnt == 2)
		{
			vector<int> ans;
			for (int k = v.size() - 1; k >= 0; k--)
			{
				if (v[k] == 1)
				{
					ans.push_back(k);
				}
			}
			swap(ans[0], ans[1]);
			for (int k : ans)
				cout << k << ' ';
		}
		else // 1이 3개보다 많으면
		{
			bool checkSecond = false;
			int ix = 0;
			ll tmp = 0;

			int sec = 0;
			for (int k = v.size() - 1; k >= 0; k--)
			{
				if (v[k] == 1)
				{
					if (checkSecond)
					{
						ll u = 1LL << (k + 1);
						ll gt = tmp + u;
						ll gap = abs(m - gt);
						sec = k + 1;
						
						ll d = 1LL << k;
						ll le = tmp + d;
						if (gap >= abs(m - le))
						{
							gap = abs(m - le);
							sec = k;
						}
						break;
					}
					else
					{
						ix = k;
						tmp = 1LL << k;
						checkSecond = true;
					}
				}
			}
			cout << sec << ' ' << ix;
		}
		cout << '\n';
	}

	return 0;
}

