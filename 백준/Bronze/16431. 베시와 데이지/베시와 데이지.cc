#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int br, bc;
	cin >> br >> bc;
	int dr, dc;
	cin >> dr >> dc;
	int jr, jc;
	cin >> jr >> jc;

	int daisy = abs(jr - dr) + abs(jc - dc);
	int tmp = min(abs(jr - br), abs(jc - bc));
	int bessie = abs(jr - br) + abs(jc - bc) - tmp;

	if (daisy == bessie)
		cout << "tie";
	else if (daisy < bessie)
		cout << "daisy";
	else
		cout << "bessie";

	return 0;
}
