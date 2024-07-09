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

	string st;
	getline(cin, st);

	int q = 0;
	string cmd;
	while (1)
	{
		getline(cin, cmd);
		if (cmd == "고무오리 디버깅 끝") break;
		if (cmd == "문제")q++;
		if (cmd == "고무오리")
		{
			if (q > 0)q--;
			else
				q += 2;
		}
	}
	if (q == 0)
		cout << "고무오리야 사랑해";
	else
		cout << "힝구";


	return 0;
}
