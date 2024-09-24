#include<bits/stdc++.h>

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

	int tc;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		cout << "Data Set " << i << ":\n";
		int h;
		cin >> h;
		string s;
		cin >> s;
		for (auto c : s)
		{
			if (c == 'c')
				h++;
			else
				h--;
			if (h == 0)break;
		}
		cout << h << "\n\n";
	}

	return 0;
}