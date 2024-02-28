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

string KaratsubaHelper(string str1, string str2, int level) // level은 디버깅용
{
	//cout << "Level " << level << " : " << str1 << " x " << str2 << endl;

	int N = max(str1.size(), str2.size());
	str1.insert(0, string(N - str1.size(), '0'));
	str2.insert(0, string(N - str2.size(), '0'));

	// 한 자리까지 쪼개졌을 때 곱해서 반환
	if (N == 1)
	{
		string result = to_string(stoi(str1) * stoi(str2));
		return result;
	}

	int mid = N / 2;

	string a = str1.substr(0, mid);
	string b = str1.substr(mid, N - mid);

	string c = str2.substr(0, mid);
	string d = str2.substr(mid, N - mid);

	string ac = KaratsubaHelper(a, c, level + 1);
	// TODO:
	string bd = KaratsubaHelper(b, d, level + 1);

	string apb = Add(a, b);
	string cpd = Add(c, d);
	// 문자열 뒤에 '0'을 추가해서 10^N를 O(N)으로 처리
	string temp = KaratsubaHelper(apb, cpd, level + 1);
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

	string result = KaratsubaHelper(str1, str2, 0); // 디버깅용 level을 0에서 시작

	// 불필요한 '0' 제거
	int i = 0;
	while (result[i] == '0') i += 1;
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
	
	// a-b;
	if (nega) //if a is negative
	{
		if (negb)
		{
			if (a == b)
				cout << 0 << '\n';
			else if (a < b) 
				cout << Subtract(b, a) << '\n';
			else
				cout << '-' << Subtract(a, b) << '\n';
		}
		else
		{
			cout << '-' << Add(a, b) << '\n';
		}
	}
	else
	{
		if (negb)
		{
			cout << Add(a, b) << '\n';
		}
		else
		{
			if (a == b)
				cout << 0 << '\n';
			else if ((a < b))
				cout << '-' << Subtract(b, a) << '\n';
			else 
				cout << Subtract(a, b) << '\n';
		}
	}

	// a*b;
	if(negative %2 == 0)
		cout << Karatsuba(a, b) << '\n';
	else
		cout << '-' << Karatsuba(a, b) << '\n';



	return 0;
}
