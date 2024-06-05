#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int k, n;
	cin >> k >> n;
	int curn = n;
	int round = 0;
	for (int i = 0; i < k; i++)
	{
		int rnd;
		cin >> rnd;
		if (curn-rnd >= 0)
		{
			curn -= rnd;
		}
		if (curn == 0)
		{
			round++;
			if(i != k - 1)
				curn = n;
		}
	}

	cout << round << '\n' << curn;


	return 0;
}