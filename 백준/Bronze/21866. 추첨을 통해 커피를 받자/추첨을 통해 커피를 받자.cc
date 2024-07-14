#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int total = 0;
	bool isHacker = false;
	for (int i = 0; i < 9; i++)
	{
		int n;
		cin >> n;
		total += n;
		if ((i/2+1) * 100 < n) isHacker = true;
	}
	if (isHacker)
		cout << "hacker";
	else if (total < 100)
		cout << "none";
	else
		cout << "draw";

	return 0;
}