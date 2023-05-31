#include <bits/stdc++.h>

using namespace std;


int calc_sum(string& str)
{
	int tmp = 0;
	for (auto ch : str)
	{
		int ctoi = ch - '0';
		if (ctoi >= 0 && ctoi <= 9)
		{
			tmp += ctoi;
		}
	}
	return tmp;
}

bool cmp(string& a, string& b)
{
	if (a.length() >= b.length())
		if (a.length() == b.length())
		{
			int a_sum = calc_sum(a);
			int b_sum = calc_sum(b);
			if (a_sum > b_sum)
				return false;
			else if (a_sum == b_sum) return a < b;
			else
				return true;
		}
		else
		{
			return false;
		}
	else
		return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<string> str;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		str.push_back(input);
	}

	sort(str.begin(), str.end(), cmp);

	for (auto s : str)
		cout << s << '\n';

	return 0;
}
