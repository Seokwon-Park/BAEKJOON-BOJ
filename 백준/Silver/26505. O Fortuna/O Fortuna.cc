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

int fort[21] = { 0, 0, 5, 7, 13, 23, 17, 19, 23, 37, 61, 67, 61, 71, 47, 107, 59, 61, 109, 89, 103 };
int less_fort[21] = { 0, 0, 3, 7, 11, 13, 17, 29, 23, 43, 41, 73, 59, 47, 89, 67, 73, 107, 89, 101, 127 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

    int n;
    while (cin >> n)
    {
        cout << "N = " << n << " FORTUNATE = " << fort[n] << " LESS = " << less_fort[n] << '\n';
    }

	return 0;
}