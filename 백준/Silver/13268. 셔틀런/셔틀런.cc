#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;
template <typename key, typename value>
using hashm = unordered_map<key, value>;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	int move = 10;
	while (n >= move)
	{
		n -= move;
		move += 10;
		if (move == 50)
		{
			move = 10;
		}
	}
	
	if (n == 0)
	{
		cout << 0;
	}
	else
	{
		for (int i = 0; i < move/10; i++)
		{
			if (n > i * 5 && n <= (i + 1) * 5)
			{
				cout << i + 1;
				return 0;
			}
		}
		n -= move / 2;
		for (int i = 0; i < move / 10; i++)
		{
			if (n >= i * 5 && n < (i + 1) * 5)
			{
				cout << move/10-i;
				return 0;
			}
		}
	}
	
	
	
	return 0;
}