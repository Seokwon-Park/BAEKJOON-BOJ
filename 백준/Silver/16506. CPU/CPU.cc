#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

map<string, string> m;

string toBin(int k, int sz)
{
	string ret(sz, '0');

	int n = ret.size();
	for (int i = n - 1; k; i--)
	{
		ret[i] = k % 2 + '0';
		k /= 2;
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	m["ADD"] = "0000";
	m["SUB"] = "0001";
	m["MOV"] = "0010";
	m["AND"] = "0011";
	m["OR"] = "0100";
	m["NOT"] = "0101";
	m["MULT"] = "0110";
	m["LSFTL"] = "0111";
	m["LSFTR"] = "1000";
	m["ASFTR"] = "1001";
	m["RL"] = "1010";
	m["RR"] = "1011";

	int n;
	cin >> n;
	while (n--)
	{
		string res = "";
		string op;
		cin >> op;
		int d, a, b;
		cin >> d >> a >> b;
		bool useC = false;
		if (op[op.size() - 1] == 'C')
		{
			op.pop_back();
			useC = true;
		}
		res += m[op]; // 0~3
		res += (useC ? '1' : '0'); //4
		res += '0'; // 5
		res += toBin(d, 3);
		res += toBin(a, 3);
		if (useC)
		{
			res += toBin(b, 4);
		}
		else
		{
			res += toBin(b, 3);
			res += '0';
		}


		cout << res << '\n';
	}


	return 0;
}