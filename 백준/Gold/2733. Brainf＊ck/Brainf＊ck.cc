#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

string preprocess(string s)
{
	int cmt = s.find('%');
	if (cmt != string::npos);
	{
		return s.substr(0, cmt);
	}
	return s;
}

bool validation(string s, map<int, int>& pair)
{
	stack<int> st;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '[')
		{
			st.push(i);
		}
		else if (s[i] == ']')
		{
			if (st.empty()) return false;
			int index = st.top();
			st.pop();
			pair[index] = i;
			pair[i] = index;
		}
		else
		{
			continue;
		}
	}
	return st.empty();
}

void process(string s, map<int, int> p, string byte)
{
	int ptr = 0;
	for (int i = 0; i < s.size(); i++)
	{
		switch (s[i])
		{
		case '>':
			ptr = (ptr + 1) % 32768;
			break;
		case '<':
			ptr = (ptr + 32767) % 32768;
			break;
		case '+':
			byte[ptr] = (byte[ptr] + 1) % 256;
			break;
		case '-':
			byte[ptr] = (byte[ptr] + 255) % 256;
			break;
		case '.':
			cout << byte[ptr];
			break;
		case '[':
			if (byte[ptr] == 0)
			{
				i = p[i];
			}
			break;
		case ']':
			if (byte[ptr] != 0)
			{
				i = p[i];
			}
			break;
		default:
			continue;
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	cin.ignore();
	for (int i = 1; i <= t; i++)
	{
		string byte(32768, 0);
		map<int, int> p;
		int ptr = 0;
		string s;
		string command;
		while (getline(cin, s))
		{
			if (s == "end") break;
			command += preprocess(s);
		}
		cout << "PROGRAM #" << i << ":\n";
		if (validation(command, p))
		{
			process(command, p, byte);
			cout << '\n';
		}
		else
		{
			cout << "COMPILE ERROR\n";
		}
	}


	return 0;
}
