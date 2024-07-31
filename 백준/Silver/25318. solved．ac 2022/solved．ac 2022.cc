#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int month[13] = { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

double timeToHour(string s)
{
	istringstream iss(s);
	string tmp;
	vector<int> hms;
	while (getline(iss, tmp, ':'))
	{
		hms.push_back(stod(tmp));
	}
	double ret = 0;
	double t = 1;
	for (int i = 0; i <3; i++)
	{
		ret += hms[i] / t;
		t *= 60;
	}
	return ret;
}
vector<int> dateToVec(string s)
{
	istringstream iss(s);
	string tmp;
	vector<int> ymd;
	while (getline(iss, tmp, '/'))
	{
		ymd.push_back(stoi(tmp));
	}
	return ymd;
}

void checkLeap(vector<int>& i, vector<int>& n, bool& includeLeap)
{
	if (i[0] == 2020)
	{
		if (i[1] == 2)
		{
			if (i[1] <= 28)
			{
				includeLeap = true;
			}
		}
		else if (i[1] < 2)
		{
			includeLeap = true;
		}
	}
	else if (i[0] < 2020)
	{
		includeLeap = true;
	}	
	//cout << "not Include\n";
	if (!includeLeap) return;
	if (n[0] == 2020)
	{
		if (n[1] == 2)
		{
			if (n[1] <= 29)
			{
				includeLeap = false;
			}
		}
		else if (n[1] < 2)
		{
			includeLeap = false;
		}
	}
	else if (n[0] < 2020)
	{
		includeLeap = false;
	}
	//cout << (includeLeap ? "Include\n" : "not Include\n");
}

int dateDiff(vector<int> n, vector<int> v)
{
	bool includeLeap = false;
	checkLeap(v, n, includeLeap);

	int dDiff = n[2] - v[2];
	int mDiff = 0;
	int carry = 0;
	if (n[1] >= v[1])
		mDiff += month[n[1]] - month[v[1]];
	else
	{
		mDiff += month[n[1]] + 365 - month[v[1]];
		carry = 1;
	}

	int yDiff = n[0] - v[0] - carry;

	return yDiff*365 + mDiff + dDiff + includeLeap;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	if (n == 0) 
	{
		cout << 0;
		return 0;
	}
	vector<tuple<vector<int>, double, int>> v;
	for (int i = 0; i < n; i++)
	{
		string date;
		string time;
		int diff;
		cin >> date >> time >> diff;
		vector<int> dateVec = dateToVec(date);
		double sec = timeToHour(time);
		v.push_back(tie(dateVec, sec, diff));
	}

	vector<int> date_n;
	double sec_n;
	int diff_n;
	tie(date_n, sec_n, diff_n) = v[n - 1];

	double nume = 0.0;
	double deno = 0.0;
	for (int i = 0; i < n; i++)
	{
		vector<int> date_i;
		double sec_i;
		int diff_i;
		tie(date_i, sec_i, diff_i) = v[i];
		double d = dateDiff(date_n, date_i);
		d += (sec_n-sec_i) / 24.0;
		double p_i = max(pow(0.5, d / 365.0), pow(0.9, n - 1 - i));
		double l_i = diff_i;
		nume += p_i * l_i;
		deno += p_i;
	}

	cout << round(nume / deno);



	return 0;
}