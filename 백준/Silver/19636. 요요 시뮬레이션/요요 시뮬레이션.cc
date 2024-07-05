#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int w, l0, t; // 체중, 에너지 섭취 및 기초대사량, 역치.
	cin >> w >> l0 >> t;

	int d, l, a; // 기간, 기간내 일일 에너지 섭취량, 활동 대사량,
	cin >> d >> l >> a;

	int ww = w;
	int ll0 = l0;
	bool isDanger = false;
	for (int i = 0; i < d; i++)
	{
		// 에너지 소비량 = 기초대사량 + 활동 대사량
		int consume = ll0 + a;
		// 체중변화 = 기간 내 일일 에너지 섭취량 - 에너지 소비량
		int diff = l - consume;
		// 체중 = 체중 + 체중변화;
		ww += diff;
		if (ww <= 0)
		{
			isDanger = true;
			break;
		}
		// if 체중변화 절댓값 > 역치 => 기초대사량 + 체중변화/2 (처음 경우에는 고려하지 않음)
	}
	if (isDanger)
	{
		cout << "Danger Diet";
	}
	else
	{
		cout << ww << ' ' << ll0;
	}
	cout << '\n';

	ww = w;
	ll0 = l0;
	isDanger = false;
	for (int i = 0; i < d; i++)
	{
		// 에너지 소비량 = 기초대사량 + 활동 대사량
		int consume = ll0 + a;
		// 체중변화 = 기간 내 일일 에너지 섭취량 - 에너지 소비량
		int diff = l - consume;
		// 체중 = 체중 + 체중변화;
		ww += diff;
		if (ww <= 0)
		{
			isDanger = true;
			break;
		}
		// if 체중변화 절댓값 > 역치 => 기초대사량 + 체중변화/2
		if (abs(diff) > t)
		{
			ll0 = ll0 + (int)floor((double)diff / (double)2);
		}
		if (ll0 <= 0)
		{
			isDanger = true;
			break;
		}
	}
	if (isDanger)
	{
		cout << "Danger Diet";
	}
	else
	{
		cout << ww << ' ' << ll0 << ' ';
		if (l0 - ll0 > 0)
			cout << "YOYO";
		else
			cout << "NO";
	}


	return 0;
}