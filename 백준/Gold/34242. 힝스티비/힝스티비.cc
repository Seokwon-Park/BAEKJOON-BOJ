#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	string tmp;
	int res = 0;
	for (int i = 0; i < s.size(); i++)
	{
		tmp = s.substr(i, 3);
		if (tmp == "+^+")
		{
			res++;
		}
		else if (tmp == "-^-")
		{
			res--;
		}
	}

	//잠재적으로 +1 시킬 수 있는 조합을 찾아본다.
	int a = s.find("+-^+");
	int b = s.find("+^-+");
	int c = s.find("+^^+");
	int d = s.find("-^-");
	int e = s.find("-^-^-");
	if (e != string::npos)
	{
		res += 2;
	}
	else if (a != string::npos || b != string::npos || c != string::npos || d != string::npos)
	{
		res++;
	}

	cout << res;

	return 0;
}