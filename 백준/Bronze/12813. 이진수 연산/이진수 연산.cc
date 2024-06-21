#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	bitset<100000> a;
	bitset<100000> b;

	cin >> a >> b;
	cout << (a & b).to_string()<< '\n';
	cout << (a | b).to_string()<< '\n';
	cout << (a ^ b).to_string()<< '\n';
	cout << (~a).to_string() << '\n';
	cout << (~b).to_string() << '\n';

	return 0;
}