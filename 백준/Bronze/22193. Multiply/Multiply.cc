#include <bits/stdc++.h>

using namespace std;

using ll = long long;

string Add(string str1, string str2)
{
	if (!str1.size() && !str2.size()) return "0";

	int N = max(str1.size(), str2.size());

	if (N <= 8)
	{
		string result = to_string(stoll(str1) + stoll(str2));
		return result;
	}

	str1 = string(N - str1.size(), '0') + str1;
	str2 = string(N - str2.size(), '0') + str2;

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
		result = '1' + result;

	return result;
}

string Subtract(string str1, string str2)
{
	if (str1 == str2) return "0";

	int N = max(str1.size(), str2.size());

	if (N <= 8)
	{
		string result = to_string(stoll(str1) - stoll(str2));
		return result;
	}
	str1 = string(N - str1.size(), '0') + str1;
	str2 = string(N - str2.size(), '0') + str2;

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

string KaratsubaHelper(string str1, string str2)
{
	//cout << "Level " << level << " : " << str1 << " x " << str2 << endl;

	int N = max(str1.size(), str2.size());
	str1 = string(N - str1.size(), '0') + str1;
	str2 = string(N - str2.size(), '0') + str2;

	// 한 자리까지 쪼개졌을 때 곱해서 반환
	if (N <= 8)
	{
		string result = to_string(stoll(str1) * stoll(str2));
		return result;
	}

	int mid = N / 2;

	string a = str1.substr(0, mid);
	string b = str1.substr(mid, N - mid);

	string c = str2.substr(0, mid);
	string d = str2.substr(mid, N - mid);

	string ac = KaratsubaHelper(a, c);
	string bd = KaratsubaHelper(b, d);

	string apb = Add(a, b);
	string cpd = Add(c, d);
	// 문자열 뒤에 '0'을 추가해서 10^N를 O(N)으로 처리
	string temp = KaratsubaHelper(apb, cpd);
	temp = Subtract(temp, Add(ac, bd));
	temp.append(string(N - mid, '0'));
	ac.append(string((N - mid) * 2, '0'));
	temp = Add(temp, ac);
	temp = Add(temp, bd);

	return temp; // return result;
}

string Karatsuba(string str1, string str2)
{
	if (!str1.size() || !str2.size()) return "0";

	string result = KaratsubaHelper(str1, str2);

	// 불필요한 '0' 제거
	int i = 0;
	while (result[i] == '0') i += 1;
	if (i == result.size())
		return "0";
	else
		result = result.substr(i, result.size() - i);

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
		str1 = string(N - str1.size(), '0') + str1;
		str2 = string(N - str2.size(), '0') + str2;

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
	
	int n, m;
	cin >> n >> m;
	string a, b;
	cin >> a >> b;

	cout << Karatsuba(a, b);

	//int N = max(a.size(), b.size());
	//a.insert(0, string(N - a.size(), '0'));
	//b.insert(0, string(N - b.size(), '0'));

	//vector<ll> aa, bb;
	//for (int i = N-1; N)
	//{
	//	for(int j = 0; i <)
	//}


	return 0;
}
