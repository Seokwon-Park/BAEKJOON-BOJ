#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		char gen;
		cin >> gen;
		string mom, dad;
		cin >> mom >> dad;
		int mfeet = stoi(mom.substr(0, 1));
		string tmp = mom.substr(2);
		tmp.pop_back();
		int minch = stoi(tmp) + mfeet * 12;


		int dfeet = stoi(dad.substr(0, 1));
		tmp = dad.substr(2);
		tmp.pop_back();
		int dinch = stoi(tmp) + dfeet * 12;

		int res = minch + dinch + (gen == 'B' ? 5 : -5);
		cout << "Case #" << i << ": ";
		if (res % 2 == 0)
		{
			res /= 2;
			int mn = res - 4;
			int mx = res + 4;
			cout << mn / 12 << '\'' << mn % 12 << "\" to "
				<< mx / 12 << '\'' << mx % 12 << "\"\n";
		}
		else
		{
			res /= 2;
			int mn = res - 3;
			int mx = res + 4;
			cout << mn / 12 << '\'' << mn % 12 << "\" to "
				<< mx / 12 << '\'' << mx % 12 << "\"\n";
		}


	}

	return 0;
}



