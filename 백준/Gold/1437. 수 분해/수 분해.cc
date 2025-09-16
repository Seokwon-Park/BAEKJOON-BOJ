#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

//풀이 메모: 3으로 나누어 떨어지는 경우 3의 합으로 분해하는게 최선
//분해합에 1이 포함되면 안됨
//6 = 2 2 2 = 8
//6 = 3 3 = 9

//나머지가 1인경우
// 4 = 1 3 = 3;
// 4 = 2 2 = 4;

// 나머지가 2인경우
// 5 = 2 3 = 6
// 5 = 1 2 2 = 4
// 5 = 1 4 = 4
// 1이 들어가면 안됨

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	ll ans = 1;
	if (n <= 3)
	{
		ans = n;
	}
	else if (n % 3 == 0)
	{
		for (int i = 0; i < n / 3; i++)
		{
			ans = ans * 3 % 10007;
		}
	}
	else if (n % 3 == 1)
	{
		for (int i = 0; i < n / 3 - 1; i++)
		{
			ans = ans * 3 % 10007;
		}
		ans = ans * 4 % 10007;
	}
	else
	{
		for (int i = 0; i < n / 3; i++)
		{
			ans = ans * 3 % 10007;
		}
		ans = ans * 2 % 10007;
	}

	cout << ans;


	return 0;
}