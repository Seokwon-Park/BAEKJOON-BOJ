#include <bits/stdc++.h>

using namespace std;

vector<int> split(string str)
{
	istringstream iss(str);
	string token;
	vector<int> time;
	while (getline(iss, token, ':'))
	{
		time.push_back(stoi(token));
	}
	return time;
}


int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0);

	string st, ed;
	cin >> st >> ed;
	vector<int> stv = split(st);
	vector<int> edv = split(ed);

	int sec = 3600;
	int stt = 0;
	int edt = 0;
	for (int i = 0; i < 3; i++)
	{
		stt += stv[i] * sec;
		edt += edv[i] * sec;
		sec /= 60;
	}

	int day = 3600 * 24;
	int res = edt - stt < 0 ? edt - stt + day : edt - stt;

	int h, m, s;
	h = res / 3600;
	res %= 3600;
	m = res / 60;
	res %= 60;
	s = res;

	cout.width(2);
	cout.fill('0');
	cout << h;
	cout << ':';
	cout.width(2);
	cout.fill('0');
	cout << m;
	cout << ':'; 
	cout.width(2);
	cout.fill('0');
	cout << s << '\n';

	return 0;
}