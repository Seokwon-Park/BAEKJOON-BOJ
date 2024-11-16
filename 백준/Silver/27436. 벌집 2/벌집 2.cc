#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

ull n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	if (n == 1)
	{
		cout << 1;
		return 0;
	}

	// 1에서 x개의 방을 지나야 도착할 수 있는 방의 번호의 최댓값은
	// 1 + (1+2+...+x)*6
	// 따라서
	// n <= 1 + x(x+1)/2 * 6 
	// n-1 <= x(x+1)*3

	ull st = 1;
	ull en = 3'000'000'000;

	while (st < en)
	{
		ull x = (st + en) / 2;
		//ull res = st * (st + 1) * 3LL + 1;
		if (n - 1 <= x * (x + 1) * 3)
		{
			en = x;
		}
		else
		{
			st = x+1;
		}
	}

	//cout << st * (st + 1) * 3LL + 1 << '\n';
	//시작하는 1번 방도 지나가는 방이므로 방 개수 +1
	cout << st + 1;


	return 0;
}
