#include <bits/stdc++.h>

using namespace std;

string Add(string str1, string str2)
{
	if (!str1.size() && !str2.size())
	{
		return string("0");
	}

	int mxlen = max(str1.length(), str2.length());
	int mnlen = min(str1.length(), str2.length());

	string newstr(mxlen, '\0');

	int carry = 0;
	for (int i = 0; i < mxlen; i++)
	{
		int a, b;
		if (i < str1.length())
			a = str1[str1.length() - i - 1] - '0';
		else
			a = 0;
		if (i < str2.length())
			b = str2[str2.length() - i - 1] - '0';
		else
			b = 0;
		newstr[mxlen - i - 1] = ((a + b + carry) % 10) + '0';
		carry = (a + b + carry) >= 10;
	}
	if (carry)
	{
		newstr.insert(0, 1, (carry + '0'));
	}


	return newstr;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a, b;
	cin >> a >> b;
	cout << Add(a, b);

	return 0;
}