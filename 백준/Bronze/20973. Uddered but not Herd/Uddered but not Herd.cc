#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;
	

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string cow;
	cin >> cow;
	string hmm;
	cin >> hmm;

	int j = 0;
	int cycle = 0;
	while (j != hmm.size())
	{
		for (int i = 0; i < 26; i++)
		{
			if (cow[i] == hmm[j])j++;
		}
		cycle++;
	}
	cout << cycle;


	return 0;
}