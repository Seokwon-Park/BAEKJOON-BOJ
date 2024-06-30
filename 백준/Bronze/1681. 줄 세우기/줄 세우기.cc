#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

bool cantUse[10];
int cnt;
int res;
int n, l;


void func(int k, int nn)
{
	if (k == nn)
	{
		cnt++;
		if (cnt == n)
		{
			cout << res;
			exit(0);
		}
		return;
	}

	for (int i = 0; i <= 9; i++)
	{
		if (k == 0 && i == 0)continue;
		if (cantUse[i]) continue;
		res = res * 10 + i;
		func(k + 1, nn);
		res /= 10;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> l;

	cantUse[l] = true;

	for (int i = 1; i <= 7; i++)
	{
		func(0, i);
	}

	return 0;
}