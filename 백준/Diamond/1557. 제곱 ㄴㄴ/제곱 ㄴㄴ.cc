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

vector<int> mobius;
int k;

bool solve(int x)
{
	int res = 0;
	for (int i = 1; i * i <= x; i++)
	{
		res += mobius[i] * (x / (i * i));
	}
	return res >= k;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> k;

	ll st = 0;
	ll en = 2e9;
	int sz = ceil(sqrt(en));
	mobius.assign(sz+1, 0);
	mobius[1] = 1;
	// 어떤 수의 약수들의 뫼비우스 함수값의 합은 0이 되어야 한다고함
	// 모든 수는 1을 약수로 가지기 때문에 기본적으로 -1로 만들어준다.
	// 2는 1, 2를 약수로 가진다. mobius[1] + mobius[2] = 0;
	// mobius[2] = -1;
	// 4는 1, 2, 4 m[1] + m[2] + m[3] = 0;
	// m[3] = 0;
	// 제곱인수를 가지게 되면 알아서 0이 되기 때문에 따로 소수를 구해놓을 필요가 없다? ㄷㄷ

	for (int i = 1; i <= sz; i++)
	{
		for (int j = i * 2; j <= sz; j += i)
		{
			mobius[j] -= mobius[i];
		}
	}



	while (st + 1 < en)
	{
		int mid = (st + en) / 2;
		if (solve(mid))
		{
			en = mid;
		}
		else
		{
			st = mid;
		}
	}
	cout << en;

	return 0;
}
