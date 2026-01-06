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

ll dp[100][4];
bool v[100][4];

// len길이만큼 남았고 지금 6이 cont만큼 연속되었을 때 몇개의 666수가 나올 수 있나?
ll func(int len, int cont)
{
	if (len == 0)
	{
		return dp[len][cont] = (cont == 3) ? 1 : 0; // 남은길이가 0인데 6이 연속 3번이면 666으로 끝남
	}

	if (v[len][cont]) return dp[len][cont];

	ll cnt = 0;
	if (cont == 3) //이미 6이 3번 반복되서 나왔으면
	{
		cnt = 10 * func(len - 1, 3); // 0~9 뭘써도 666수니까 걍 10배 해줌
	}
	else
	{
		cnt += func(len - 1, cont + 1);//6을 사용한경우
		cnt += func(len - 1, 0) * 9; // 6이외의 값을 사용한 경우
	}
	v[len][cont] = 1;
	return dp[len][cont] = cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;

	int len = 0;
	for (int i = 3; i <= 100; i++) {
		ll cnt = 0;
		for (int j = 1; j <= 9; j++) {
			cnt += func(i - 1, (j == 6));
		}

		if (n <= cnt) {
			len = i;
			break;
		}
		else {
			n -= cnt;
		}
	}

	string res = "";
	int cont = 0;

	for (int i = 1; i <= len; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (i == 1 && j == 0) continue;
			int tmp = cont;
			if (j == 6)
				tmp = min(tmp+1, 3);
			else if(cont != 3)
				tmp = 0;

			ll cnt = dp[len - i][tmp];
			if (n <= cnt)
			{
				res += j + '0';
				cont = tmp;
				break;
			}
			else
			{
				n -= cnt;
			}
		}
	}

	cout << res;

	return 0;
}