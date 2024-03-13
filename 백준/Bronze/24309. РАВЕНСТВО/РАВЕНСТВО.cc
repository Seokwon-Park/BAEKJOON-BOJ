#include <bits/stdc++.h>

using namespace std;

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

string remove_zero(string str)
{
	int ix = 0;
	while (str[ix] == '0')
	{
		ix++;
	}
	if (ix == str.length())
		return "0";
	else
		return str.substr(ix);

}

pair<string, string> Div(string str1, string str2)
{
	int N = str2.size();

	string tmp = "";
	string result = "";
	if (str1 < str2)
		return {"0", str1};
	for (int i = 0; i < str1.size(); i++)
	{
		tmp += str1[i];
		tmp = remove_zero(tmp);
		int res = 0;
		while (str2 < tmp || str2 == tmp)
		{
			tmp = Subtract(tmp, str2);
			res++;
		}
		result.push_back(res + '0');
	}

	int ix = 0;
	while (result[ix] == '0')
	{
		ix++;
	}
	result = result.substr(ix);

	//ix = 0;
	//while(tmp[ix] == '0')
	//{
	//	ix++;
	//}
	//if (ix == tmp.length())
	//	tmp = "0";
	//else
	//	tmp = tmp.substr(ix);

	return { result, tmp };
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a, b, c;
	cin >> a >> b >> c;
	cout << Div(Subtract(b, c),a).first;

	return 0;
}