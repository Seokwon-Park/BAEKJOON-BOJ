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
	
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		string s;
		string str;
		while (getline(cin, s))
		{
			if (s.empty())break;
			str += s;
		}

		int uk = 0;
		for (auto c : str)
		{
			if (c == '#')
				uk++;
		}

		double result = (double)(str.size() - uk) / str.size() * 1000.0;
		int rounded = round(result);
		if (rounded % 10 == 0)
		{
			cout << "Efficiency ratio is " << rounded/10 << "%.\n";
		}
		else
		{
			cout << "Efficiency ratio is " << rounded / 10.0 << "%.\n";
		}
	}
	
}