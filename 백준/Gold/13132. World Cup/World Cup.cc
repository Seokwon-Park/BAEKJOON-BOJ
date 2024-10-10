#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'009;

int n, m, b;
double bd; // 배팅하는 비율
int win[10];
double margin[10];
double ans;

void func(int k, double cur, double curp)
{
	if (k == n)
	{
		if (cur > 100.0)
		{
			ans += curp;
		}
		return;
	}

	// 배당 성공한 경우
	double wincur = cur * bd * margin[k];
	double losecur = cur - cur * bd;
	func(k + 1, wincur + losecur, curp * (win[k] / 100.0));
	// 배당 실패한 경우
	if (losecur <= 100.0 * (b / 100.0))
	{
		return;
	}
	func(k + 1, losecur, curp * ((100 - win[k]) / 100.0));


}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> b;
	bd = m / 100.0;
	for (int i = 0; i < n; i++)
	{
		cin >> win[i] >> margin[i];
	}

	func(0, 100.0, 1.0);// 재산 시작을 100?

	cout << fixed << setprecision(3);
	cout << ans * 100;

	return 0;
}

