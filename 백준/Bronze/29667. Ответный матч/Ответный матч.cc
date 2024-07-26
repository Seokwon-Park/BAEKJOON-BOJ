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

	string ah;
	string bh;
	cin >> ah >> bh;
	int ahome = ah[0] - '0';
	int bhome = bh[0] - '0';
	int aaway = bh[2] - '0';
	int baway = ah[2] - '0';

	if (baway >= aaway && bhome <= ahome)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}