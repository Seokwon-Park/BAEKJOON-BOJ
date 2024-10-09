#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// 1 = 2
	// 2 = 4;
	// 3 = 16; 1
	// 4 = 256; 1
	// 5 = 65536; 1
	// 대충 a mod 3 * a mod 3인데 1층이후로 a mod 3 은 1이기 때문에 1*1mod 3이라서 걍 계속 1인듯?

	string num;
	cin >> num;
	if (num == "1")
		cout << 2;
	else
		cout << 1;


	return 0;
}