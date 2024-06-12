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

	int n, k;
	cin >> n >> k;
	vector<tiii> v;
	for (int i = 0; i < n; i++)
	{
		int ii, c, h;
		cin >> ii >> c >> h;


		v.push_back(tie(ii, c, h));
	}

	sort(v.begin(), v.end(), [](auto a, auto b) {
		ll aii, ac, ah;
		ll bii, bc, bh;
		tie(aii, ac, ah) = a; // ah / ac
		tie(bii, bc, bh) = b; // bh / bc
		ll tmpa = ah * bc;
		ll tmpb = bh * ac;

		if (tmpa == tmpb)
		{
			if (ac == bc)
			{
				return aii < bii;
			}
			return ac < bc;
		}
		return tmpa > tmpb;
		});


	for (int i = 0; i < k; i++)
	{
		int a, b, c;
		tie(a, b, c) = v[i];
		cout << a << '\n';
	}

	return 0;
}