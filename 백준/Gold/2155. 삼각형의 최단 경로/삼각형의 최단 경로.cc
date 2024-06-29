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
	
	int a, b;
	cin >> a >> b;

	if (a > b)
		swap(a, b);

	int alv = 1;
	while (a > alv * alv)
	{
		alv++;
	}
	int ax = -(alv-1);

	while (a != ax+(alv-1)*(alv-1)+alv)
	{
		ax++;
	}

	int blv = 1;
	while (b > blv * blv)
	{
		blv++;
	}
	int bx = -(blv - 1);

	while (b != bx + (blv - 1) * (blv - 1)+ blv)
	{
		bx++;
	}

	int ans = 0;
	while (alv != blv)
	{
		if (alv % 2)
		{
			if (ax % 2)
			{
				if (ax < bx && ax <= alv - 1)
				{
					a++;
					ax++;
				}
				else
				{
					a--;
					ax--;
				}
			}
			else
			{
				a += alv * 2;
				alv++;
				
			}
		}
		else
		{
			if (ax % 2)
			{
				a += alv * 2;
				alv++;
			}
			else
			{
				if (ax < bx && ax <= alv - 1)
				{
					a++;
					ax++;
				}
				else
				{
					a--;
					ax--;
				}
			}
		}
		ans++;
	}

	ans += abs(a - b);

	cout << ans;
	
	return 0;
}