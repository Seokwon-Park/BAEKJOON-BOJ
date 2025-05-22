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

	vector<int> nxt(3,0);
	vector<int> c(3);
	vector<int>d(3);
	for (int i = 0; i < 3; i++)
	{
		cin >> c[i] >> d[i];
	}

	int hp;
	cin >> hp;
	int t = 0;
	while (true)
	{
		for (int i = 0; i < 3; i++)
		{
			if (nxt[i] == t)
			{
				hp -= d[i];
				nxt[i] += c[i];
			}
			if (hp <= 0)
			{
				cout << t;
				return 0;
			}
		}
		t++;
	}

	
	return 0;
}