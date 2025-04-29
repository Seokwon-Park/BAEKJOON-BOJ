#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

bool isUsed[1000005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int e = 0;
	int o = 0;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		e += x % 2 == 0;
		o += x % 2 == 1;
		isUsed[x] = true;
	}
	if (e > o)
	{
		int st = 2;
		while (isUsed[st] == true)
			st += 2;
		cout << st;
	}
	else
	{
		int st = 1;
		while (isUsed[st] == true)
			st += 2;
		cout << st;
	}




	return 0;
}