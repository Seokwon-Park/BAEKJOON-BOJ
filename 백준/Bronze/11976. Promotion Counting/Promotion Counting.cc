#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int bb, ba, sb, sa, gb, ga, pb, pa;
	cin >> bb >> ba >> sb >> sa >> gb >> ga >> pb >> pa;
	int gp = pa - pb;
	gb -= gp;
	int sg = ga - gb;
	sb -= sg;
	int bs = sa - sb;
	bb -= bs;

	cout << bs << '\n' << sg << '\n' << gp;



	return 0;
}