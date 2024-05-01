#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

// 이해한 내용.
const ull base = 1e13; // 0이 최대 8개 나올 수 있다.
// 그러면 뒤에 0 제거 했을때 5자리는 남길 수 있어야 
// non-zero 맨 끝 5자리를 구하는 다음 연산으로 이어갈 수 있다.
// 1e12는 틀려야 할것 같지만. 대충 우연이 맞아서 어쩌구저쩌구 해결됨.

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	ull res = 1;

	/*cout << base << '\n';
	ull tmp= 1000000LL * 9999999999999LL;
	cout << tmp << '\n';*/
	for (int i = 1; i <= n; i++)
	{
		res *= i;
		while (res % 10 == 0)
			res /= 10;
		res %= base;
		assert(res > 0);
	}
	cout << setw(5) << setfill('0') << res%100000 << '\n';

	return 0;
}
