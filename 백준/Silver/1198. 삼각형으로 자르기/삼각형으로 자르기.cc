#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'009;

pii operator-(pii A, pii B)
{
	return make_pair(A.first - B.first, A.second - B.second);
}

int dot(pii A, pii B)
{
	return A.first * B.second - A.second * B.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pii> v(n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[i] = make_pair(x, y);
	}

	vector<bool> c(n);
	fill(c.begin(), c.begin() + 3, true);

	double ans = 0;
	do
	{
		vector<pii> abc;
		for (int i = 0; i < n; i++)
		{
			if (c[i])
				abc.push_back(v[i]);
		}

		pii BA = abc[0] - abc[1];
		pii BC = abc[2] - abc[1];

		ans = max(ans, dot(BA, BC) * 0.5);

	} while (prev_permutation(c.begin(), c.end()));

	cout << fixed << setprecision(1);
	cout << ans;

	return 0;
}

