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
using hashmap = unordered_map<key, value>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int a, b;
		cin >> a >> b;
		int inner, outer;
		if (a < b)
		{
			inner = b - a;
			outer = a - 201 +  243 - b + 1;
		}
		else
		{
			inner = 243 - a + b - 201+ 1;
			outer = a - b;
		}

		if (inner < outer)
		{
			cout << "Inner circle line";
		}
		else
		{
			cout << "Outer circle line";
		}
		cout << '\n';
	}


	return 0;
}