#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int n, m;
int b[18][18];
int flipped[18][18];

//https://blog.naver.com/jinhan814/222540111549
int popcount(unsigned int n)
{
	n = (n >> 1 & 0x55555555) + (n & 0x55555555);
	n = (n >> 2 & 0x33333333) + (n & 0x33333333);
	n = (n >> 4 & 0x0F0F0F0F) + (n & 0x0F0F0F0F);
	n = (n >> 8 & 0x00FF00FF) + (n & 0x00FF00FF);
	n = (n >> 16 & 0x0000FFFF) + (n & 0x0000FFFF);

	return n;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> b[i][j];
		}
	}

	
	int ans = INF;
	for (int i = 0; i < 1 << n; i++)//row를 뒤집는 경우의 수 
	{
		bool poss = true;
		int flipcol = 0;
		int cnt = popcount(i);
		for (int c = 0; c < m; c++)
		{
			int sum = 0;
			for (int r = 0; r < n; r++)
			{
				if (i & (1 << r))
				{
					sum += -b[r][c];
				}
				else
				{
					sum += b[r][c];
				}
			}
			if (sum == 0)
			{
				poss = false;
				break;
			}
			else if (sum < 0)
			{
				flipcol |= (1 << c);
				cnt++;
			}
		}
		if (poss)
		{
			bool chk = true;
			for (int r = 0; r < n; r++)
			{
				int sum = 0;
				for (int c = 0; c < m; c++)
				{
					if ((i & (1 << r)) && (flipcol & (1 << c)))
					{
						sum += b[r][c];
					}
					else if((i & (1 << r)) || (flipcol & (1 << c)))
					{
						sum += -b[r][c];
					}
					else
					{
						sum += b[r][c];
					}
				}
				if (sum <= 0)
				{
					chk = false;
					break;
				}
			}
			if (!chk) continue;
			ans = min(ans, cnt);
		}
	}
	cout << (ans == INF ? -1 : ans);



	return 0;
}