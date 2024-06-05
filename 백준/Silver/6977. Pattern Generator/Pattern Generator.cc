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

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, k;
		cin >> n >> k;
		cout << "The bit patterns are\n";
		vector<bool> v(n, 0);
		fill(v.begin(), v.begin() + k, true);
		do
		{
			for(int i = 0; i<n ;i++)
			{
				cout << v[i];
			}
			cout << '\n';
		} while (prev_permutation(v.begin(), v.end()));
		cout << '\n';
	}

	return 0;
}