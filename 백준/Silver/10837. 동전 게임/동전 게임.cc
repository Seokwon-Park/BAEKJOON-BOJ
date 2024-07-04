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
	
	int k, c;
	cin >> k >> c;

	for (int i = 0; i < c; i++)
	{
		int m, n;
		cin >> m >> n;

		int tmp = abs(m - n) - (k - max(m, n));

		// m> n인 경우 (m-1, n)인 상태에서 n이 못뽑은 경우의 점수차에서
		//  남은 라운드 (k-m) >= (m-1-n) 이 안에 역전 못하면 땡.
		// 솔직히 먼 개소린지 모르겠다 존나 빡대가리같음.
		if (m > n)
		{
			if (tmp <= 2) cout << 1;
			else cout << 0;
		}
		else if(m < n)
		{
			if (tmp <= 1) cout << 1;
			else cout << 0;
		}
		else
		{
			cout << 1;
		}

		cout << '\n';
	}

	return 0;
}
