#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int sab;
	cin >> sab;
	int ma, fab, mb;
	cin >> ma >> fab >> mb;

	fab += ma + mb;

	if (sab > 240 && fab < sab)
	{
		cout << "flight";
	}
	else
	{
		cout << "high speed rail";
	}

	



	return 0;
}