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

	while (1)
	{
		int mn = 1;
		int mx = 10;
		bool isHonest = true;
		while (1)
		{
			int x;
			cin >> x;
			cin.ignore();
			if (x == 0)return 0;
			string ans;
			getline(cin, ans);
			if (ans == "right on")
			{
				if (!(x >= mn && x <= mx))
				{
					isHonest = false;
				}
				break;
			}
			else if (ans == "too high")
			{
				mx = min(mx, x - 1);
			}
			else
			{
				mn = max(mn,x + 1);		
			}
		}
		if (isHonest && mn <= mx)
		{
			cout << "Stan may be honest\n";
		}
		else
		{
			cout << "Stan is dishonest\n";
		}
	}



	return 0;
}



