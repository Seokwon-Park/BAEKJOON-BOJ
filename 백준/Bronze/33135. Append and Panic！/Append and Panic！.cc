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
	
	string s;
	cin >> s;
	
	int len = 0;
	int ix = s.size() - 1;

	char st = s.back()+1;

	while (s[ix] < st)
	{
		st = s[ix];
		len++;
		ix--;
	}

	cout << s.substr(0, s.size() - len).size();


	return 0;
}