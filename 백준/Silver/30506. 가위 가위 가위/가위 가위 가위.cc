#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x;
	string v(100, '2');
	string ans(100, '0');
	int last = 0;
	cin >> last;
	for (int i = 0; i < 100; i++)
	{
		v[i] = '0'; // 바위
		cout << "? " << v << endl;
		cin >> x;
		if (x > last) // 승수가 더 많아진 경우
		{
			ans[i] = '2';
		}
		else if (x == last)
		{
			ans[i] = '0';
		}
		else
		{
			ans[i] = '5';
		}
		last = x;
	}
	cout << "! " << ans << endl;


	return 0;
}