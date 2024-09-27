#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int res[256][256];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	char ml, mr, tl, tr;
	cin >> ml >> mr >> tl >> tr;
	
	res['R']['R'] = 2;
	res['R']['S'] = 0;
	res['R']['P'] = 1;
	res['S']['R'] = 1;
	res['S']['S'] = 2;
	res['S']['P'] = 0;
	res['P']['R'] = 0;
	res['P']['S'] = 1;
	res['P']['P'] = 2;

	if (res[ml][tl] == 0 && res[ml][tr] == 0)
		cout << "MS";
	else if (res[mr][tl] == 0 && res[mr][tr] == 0)
		cout << "MS";
	else if (res[ml][tl] == 1 && res[mr][tl] == 1)
		cout << "TK";
	else if (res[ml][tr] == 1 && res[mr][tr] == 1)
		cout << "TK";
	else
		cout << "?";

	return 0;
}

