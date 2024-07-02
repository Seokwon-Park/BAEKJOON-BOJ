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

	int n;
	cin >> n;

	int hh = 0;
	int mm = 0;
	int ss = 0;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		int m = stoi(str.substr(0, 2));
		int s = stoi(str.substr(3));
		ss += s;
		mm += m;
	}

	mm += ss / 60;
	ss %= 60;
	hh += mm / 60;
	mm %= 60;
	cout << setw(2) << setfill('0') << hh << ':' << setw(2) << setfill('0') << mm << ':' << setw(2) << setfill('0') << ss;


	return 0; 
}