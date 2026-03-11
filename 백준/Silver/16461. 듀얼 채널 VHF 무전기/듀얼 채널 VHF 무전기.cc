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

int getupdown(int cur, int target)
{
	int upcur = cur;
	int downcur = cur;
	for (int i = 0; i <= 1000; i++)
	{
		if (upcur == target || downcur == target)
		{
			return i;
		}

		upcur += 20;
		if (upcur > 146000)
		{
			upcur = 144000;
		}

		downcur -= 20;
		if (downcur < 144000)
		{
			downcur = 146000;
		}
	}

	return INF;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		double A, B, T;
		char ch;
		cin >> A >> B >> ch >> T;
		int a, b, t;
		a = A * 1000;
		b = B * 1000;
		t = T * 1000;
		// A Channel
		int ares = 6; // 6번 눌러서 바로 만들기
		ares = min(ares, getupdown(a, t));
		int bres = 6; // 6번 눌러서 바로 만들기
		bres = min(bres, getupdown(b, t));

		if (ch == 'A')
		{
			bres++;
		}
		else
		{
			ares++;
		}

		cout << min(ares, bres) << '\n';
	}

	return 0;
}