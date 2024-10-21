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

	string cur, nxt;
	cin >> cur >> nxt;
	
	if (cur == nxt)
	{
		cout << "24:00:00";
		return 0;
	}

	istringstream iss(cur);
	string tmp;
	vector<int> ct;
	vector<int> nt;
	while (getline(iss, tmp, ':'))
	{
		ct.push_back(stoi(tmp));
	}
	
	istringstream iss2(nxt);
	while (getline(iss2, tmp, ':'))
	{
		nt.push_back(stoi(tmp));
	}

	if (nt[0] == ct[0])
	{
		if (nt[1] == ct[1])
		{
			if (nt[2] < ct[2])
			{
				nt[0] += 24;
			}
		}
		else if(nt[1] < ct[1])
		{
			nt[0] += 24;
		}
	}
	else if (nt[0] < ct[0])
	{
		nt[0] += 24;
	}
	
	int sec = nt[2] - ct[2];
	int carry = 0;
	if (sec < 0)
	{
		sec += 60;
		carry = 1;
	}
	int minute = nt[1] - ct[1] - carry;
	if (minute< 0)
	{
		minute += 60;
		carry = 1;
	}
	else
	{
		carry = 0;
	}
	int hour = nt[0] - ct[0] - carry;

	cout << setw(2) << setfill('0') << hour << ':' <<
		setw(2) << setfill('0') << minute << ':' <<
		setw(2) << setfill('0') << sec;

	

	

	return 0;
}