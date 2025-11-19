#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

//스털링 근사라는걸 이용한다고 함
//x의 자리수는 floor(log10(x)) + 1
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	if (n >= 1'000'000)
	{
		cout << n / 5 << ' ' << n / 5 * 4;
	}
	else if( n>=500'000)
	{
		cout << n / 20 * 3 << ' ' << n / 20 * 17;
	}
	else if (n >= 100'000)
	{
		cout << n / 10 << ' ' << n / 10 * 9;
	}
	else
	{
		cout << n / 20 << ' ' << n / 20 * 19;
	}

	return 0;
}