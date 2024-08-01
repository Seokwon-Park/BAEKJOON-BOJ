#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	string s;
	cin >> n >> s;

	// 비트연산의 세계는 차갑다...
	// ~k+1 = -k(2's complement)
	// k & -k => 비트값 1이 나오는 가장 작은 자리
	// k - (k& -k) // 따라서 k의 1이 나오는 자리수 만큼 연산을 해주면 0이된다.
	int ans = 0;
	for (auto c : s)
	{
		if (c == '1')
			ans++;
	}

	cout << ans;


	return 0;
}