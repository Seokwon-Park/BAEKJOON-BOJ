#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

// 허접이 생각 못해낸 풀이
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, a, b;
	cin >> n >> a >> b;

	if (a != b) // shift가 안되니까 그냥 틀린 답을 강제로 넣음
		n = 5;

	ll n1 = n;
	n1 |= (n1 * 2);
	n1 &= (n1 * 2);
	ll n2 = n;
	n2 &= (n2 * 2);
	n2 |= (n2 * 2);

	if (n1 == n * 2 || n2 == n * 2) // and or 연산 순서에 상관없이 쉬프트에 성공한게 있으면 정답 ㄷㄷ
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}

	return 0;
}