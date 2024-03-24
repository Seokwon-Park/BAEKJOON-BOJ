#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<int> split(string str)
{
	istringstream iss(str);
	string tmp;
	vector<int> res;
	while (getline(iss, tmp, ':'))
	{
		res.push_back(stoi(tmp));
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string st, ed;
	cin >> st >> ed;
	if (st == ed)
	{
		cout << "24:00:00";
		return 0;
	}
	vector<int> stime, etime;
	stime = split(st);
	etime = split(ed);
	
	int h, m, s;
	int carry = 0;
	if (etime[2]-stime[2]  < 0)
	{
		s = etime[2] - stime[2] + 60;
		carry = 1;
	}
	else
	{
		s = etime[2] - stime[2];
	}

	if (etime[1] - stime[1] - carry < 0)
	{
		m = etime[1] - stime[1] - carry + 60;
		carry = 1;
	}
	else
	{
		m = etime[1] - stime[1] - carry;
		carry = 0;
	}

	if (etime[0] - stime[0] - carry < 0)
	{
		h = etime[0] - stime[0] - carry + 24;
	}
	else
	{
		h = etime[0] - stime[0] - carry;
	}

	cout << (h < 10 ? '0' + to_string(h) : to_string(h)) << ':' << (m < 10 ? '0' + to_string(m) : to_string(m))
		<< ':' << (s < 10 ? '0' + to_string(s) : to_string(s));


	return 0;
}
