#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int as, bs;
	cin >> as >> bs;
	string a, b;
	cin >> a >> b;
	reverse(a.begin(), a.end());
	int t;
	cin >> t;
	
	vector<int> dir(as + bs, 1);
	fill(dir.begin(), dir.begin() + as, -1);
	vector<int> swapped(as + bs, false);
	string sim = a + b;
	while (t--)
	{
		fill(swapped.begin(), swapped.end(), false);
		for (int i = 0; i < as + bs - 1; i++)
		{
			if (dir[i] == -1 && dir[i] != dir[i + 1] && !swapped[i] && !swapped[i+1])
			{
				swapped[i] = true;
				swapped[i + 1] = true;
				swap(sim[i], sim[i + 1]);
				swap(dir[i], dir[i + 1]);
			}
		}
	}
	cout << sim;

	return 0;
}
