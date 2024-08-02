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

	int tc;
	cin >> tc;
	while (tc--)
	{
		string s;
		cin >> s;
		ll n = stoll(s);

		// 대충 풀이 : 두 수가 비슷한 수일수록 큰 값이 된다. 그니까 둣 수의 갭을 최소로 해야함.
		// 해보면 예를 들면 3자리일때 455 544 여기가 최대 지점이라는걸 위의 논리를 적용하자.
		string mxs = '4' + string(s.size() - 1, '9');
		string mxRev = '5' + string(s.size() - 1, '0');
		ll mx = stoll(mxs);
		ll rev = stoll(mxRev);

		if (n >= mx)
		{
			cout << mx * rev;
		}
		else
		{
			string rev = "";
			for (int i = 0; i < s.size(); i++)
			{
				int tmp = s[i] - '0';
				rev += 9 - tmp + '0';
			}
			ll fs = stoll(rev);
			cout << fs * n;
		}
		cout << '\n';
	}

	return 0;
}