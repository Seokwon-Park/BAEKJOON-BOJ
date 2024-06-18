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
	
	int n;
	cin >> n;
	string s; 
	cin >> s;
	int ad = 0;
	int br = 0;
	int go = 0;
	string ads = "ABC";
	string brs= "BABC";
	string gos = "CCAABB";

	for (int i = 0; i < n; i++)
	{
		if (ads[i % ads.size()] == s[i])
		{
			ad++;
		}
		if (brs[i % brs.size()] == s[i])
		{
			br++;
		}
		if (gos[i % gos.size()] == s[i])
			go++;
	}

	int mx = max({ ad, br, go });
	cout << mx << '\n';
	if (ad == mx)
		cout << "Adrian\n";
	if (br == mx)
		cout << "Bruno\n";
	if (go == mx)
		cout << "Goran\n";

	return 0;
}