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
	string s;
	cin >> s;
	int sec = 0;
	int big = 0;
	for (int i = 0; i < s.size(); )
	{
		if (s[i] == 's')
		{
			sec++;
			i += 8;
		}
		else
		{
			big++;
			i += 7;
		}
	}

	if (sec == big)
	{
		cout << "bigdata? security!";
	}
	else if (sec < big)
	{
		cout << "bigdata?";
	}
	else
	{
		cout << "security!";
	}




	return 0;
}