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

	string s;
	cin >> s;
	sort(s.begin(), s.end());
	if (s == "123" || s == "456" || s == "789" || s == "147" || s == "258" || s == "058" || s == "369")
		cout << "Unlocked";
	else
		cout << "Locked";


	return 0;
}