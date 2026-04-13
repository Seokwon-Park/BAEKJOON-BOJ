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


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, a, b;
	cin >> n >> a >> b;

	// 하나는 <<2 하고 AND
	// 하나는 <<2 하고 OR
	// 얘네를 1번씩 써보면 사실상 2진법으로 1비트가 왼쪽으로 밀린값
	// A == B가 성립해야 n * 2^k 꼴로 나타낼 수 있음
	// 근데 만약 어떤1과 1의 사이 0의 길이가 1칸인게 하나라도 있으면 OR->AND를 써도 복구가 안됨
	// 예) 101 | 1010 = 1111  1111 & 11110 = 1110
	// AND를 먼저 써보면 0이되서 마찬가지로 불가능
	// 근데 AND->OR로 복구되는 경우가 있음 바로 모든 연속된 1이 2개이상이면 AND->OR로 복구가 된다.
	// 예) 11011 & 110110 = 10010 / 10010 | 100100 = 110110

	if (a != b)
	{
		cout << "NO";
	}
	else
	{
		//끝의 0은 관련이 없기 때문에 전처리
		while (n % 2 == 0)
		{
			n /= 2;
		}
		bool checkzero = false; // 0이 1번 반복되는 구간이 있는지
		int mincont = INF; // 1이 반복되는 구간의 최소길이
		int cur = -1;
		int cont = 0;
		while (n)
		{
			int nxt = n % 2;
			if (nxt != cur)
			{
				if (cur == 0)
				{
					if (cont == 1)
					{
						checkzero = 1;
					}
				}
				else if (cur == 1)
				{
					mincont = min(cont, mincont);
				}
				cur = nxt;
				cont = 1;
			}
			else
			{
				cont++;
			}
			n /= 2;
		}

		if (cur == 1)
		{
			mincont = min(cont, mincont);
		}

		if (checkzero && mincont == 1)
		{
			cout << "NO";
		}
		else
		{
			cout << "YES";
		}
	}

	return 0;
}