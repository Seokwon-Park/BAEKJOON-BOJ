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

	string y = "YONSEI";
	string k = "KOREA";

	string s;
	cin >> s;
	int yi = 0;
	int ki = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == y[yi])
		{
			yi++;
		}
		if (s[i] == k[ki])
		{
			ki++;
		}
		if (yi == 6)
		{
			cout << "YONSEI";
			break;
		}
		if (ki == 5)
		{
			cout << "KOREA";
			break;
		}
	}
	

	return 0;
}