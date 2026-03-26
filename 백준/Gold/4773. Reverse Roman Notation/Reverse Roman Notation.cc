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

int m[256];
map<int, string> rom;

int rtoi(string roman)
{
	int prev = m[roman.back()];
	int res = prev;
	roman.pop_back();
	while (!roman.empty())
	{
		char c = roman.back();
		roman.pop_back();
		int tmp = m[c];
		if (tmp >= prev)
		{
			res += tmp;
		}
		else
		{
			res -= tmp;
		}
		prev = tmp;
	}
	return res;
}

string itor(int num)
{
	string res(num / 1000, 'M');
	num %= 1000;
	int a, b, c;
	a = num / 100 * 100;
	num %= 100;
	b = num / 10 * 10;
	num %= 10;
	c = num;

	res += rom[a];
	res += rom[b];
	res += rom[c];
	
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	m['I'] = 1;
	m['V'] = 5;
	m['X'] = 10;
	m['L'] = 50;
	m['C'] = 100;
	m['D'] = 500;
	m['M'] = 1000;

	rom[1] = "I";
	rom[2] = "II";
	rom[3] = "III";
	rom[4] = "IV";
	rom[5] = "V";
	rom[6] = "VI";
	rom[7] = "VII";
	rom[8] = "VIII";
	rom[9] = "IX";
	rom[10] = "X";
	rom[20] = "XX";
	rom[30] = "XXX";
	rom[40] = "XL";
	rom[50] = "L";
	rom[60] = "LX";
	rom[70] = "LXX";
	rom[80] = "LXXX";
	rom[90] = "XC";
	rom[100] = "C";
	rom[200] = "CC";
	rom[300] = "CCC";
	rom[400] = "CD";
	rom[500] = "D";
	rom[600] = "DC";
	rom[700] = "DCC";
	rom[800] = "DCCC";
	rom[900] = "CM";

	stack<int> st;
	string s;
	while (cin >> s)
	{
		if (s == "+" || s == "-" || s == "/" || s == "*")
		{
			if (st.size() < 2)
			{
				cout << "stack underflow\n";
				continue;
			}
			int a = st.top(); st.pop();
			int b = st.top(); st.pop();
			char op = s.back();
			switch (op)
			{
			case'+':
				st.push(a + b);
				break;
			case'-':
				st.push(b - a);
				break;
			case'*':
				st.push(a * b);
				break;
			case'/':
				if (a == 0)
				{
					cout << "division by zero exception\n";
					st.push(b);
					continue;
				}
				st.push(b / a);
				break;
			default:
				break;
			}
		}
		else if (s == "=")
		{
			if (st.empty())
			{
				cout << "stack underflow\n";
				continue;
			}
			else if (st.top() <= 0 || st.top() >= 5000)
			{
				cout << "out of range exception\n";
				continue;
			}
			cout << itor(st.top()) << '\n';
		}
		else
		{
			st.push(rtoi(s));
		}
	}

	return 0;
}