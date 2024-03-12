#include <bits/stdc++.h>

using namespace std;

string Add(string str1, string str2)
{
	if (!str1.size() && !str2.size()) return "0";

	int N = max(str1.size(), str2.size());
	str1.insert(0, string(N - str1.size(), '0'));
	str2.insert(0, string(N - str2.size(), '0'));

	string result(N, '0');

	int carry = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		int n1 = str1[i] - '0';
		int n2 = str2[i] - '0';
		int sum = n1 + n2 + carry;
		carry = sum / 10;
		result[i] = sum % 10 + '0';
	}

	if (carry > 0)
		result.insert(0, string(1, carry + '0'));

	return result;
}

string Subtract(string str1, string str2)
{
	if (str1 == str2) return "0";

	int N = max(str1.size(), str2.size());
	str1.insert(0, string(N - str1.size(), '0'));
	str2.insert(0, string(N - str2.size(), '0'));

	string result(N, '0');

	int carry = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		int n1 = str1[i] - '0';
		int n2 = str2[i] - '0';
		int sum = n1 - n2 + carry + 10;
		carry = sum / 10 - 1;
		result[i] = sum % 10 + '0';
	}

	int i = 0;
	while (result[i] == '0') i += 1;
	result = result.substr(i, N - i);

	return result;
}

bool operator<(string str1, string str2)
{
	if (str1.length() != str2.length())
	{
		return str1.length() < str2.length();
	}
	else
	{
		int N = max(str1.size(), str2.size());
		str1.insert(0, string(N - str1.size(), '0'));
		str2.insert(0, string(N - str2.size(), '0'));

		for (int i = 0; i < N; i++)
		{
			if (str1[i] == str2[i]) continue; // 맨 앞자리부터 같은 수면 다음 자리 수 비교
			return str1[i] < str2[i];
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a, b;
	cin >> a >> b;

	bool nega = a[0] == '-';
	bool negb = b[0] == '-';

	int negative = 0;

	if (nega)
	{
		a = a.substr(1);
		negative++;
	}

	if (negb)
	{
		b = b.substr(1);
		negative++;
	}

	//cout << boolalpha;
	//cout << (a < b);
	//a+b;
	if (nega)
	{
		if (negb)
		{
			cout << '-' << Add(a, b) << '\n';
		}
		else
		{
			if (a == b)
				cout << 0 << '\n';
			else if (a < b)
				cout << Subtract(b, a) << '\n';
			else
				cout << "-" << Subtract(a, b) << '\n';
		}
	}
	else
	{
		if (negb)
		{
			if (a == b)
				cout << 0 << '\n';
			else if (a < b)
				cout << '-' << Subtract(b, a) << '\n';
			else
				cout << Subtract(a, b) << '\n';
		}
		else
		{
			cout << Add(a, b) << '\n';
		}
	}

	return 0;
}
