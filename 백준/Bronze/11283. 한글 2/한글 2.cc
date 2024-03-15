#include <bits/stdc++.h>
//#include <Windows.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;

std::string unicodeToUTF8(int unicode) {
	std::string utf8_string;

	//ex) utf-8 => '가'
	// 0xAC00 = 1010 1100 0000 0000 (44032);
	// (>> 12 = 1010)
	// 0xE0 = 1110 0000
	// 1110 1010 = 234 
	
	// (>> 6 = 1010 1100 00) & 0011 1111
	// = 10 1011 0000 & 00 0011 1111 
	// = 00 0011 0000
	// 0x80 = 1000 0000
	// 0011 0000 | 1000 0000
	// = 1011 0000 = 176

	// 1010 1100 0000 0000 & 0000 0000 0011 1111;
	// = 0000 0000 0000 0000;
	// 0x80 | 0000 0000
	// = 1000 0000 = 128
	// utf-8 '가' = 0xEA + 0xB0 + 0x80
	utf8_string += static_cast<char>(0xE0 | (unicode >> 12));
	utf8_string += static_cast<char>(0x80 | ((unicode >> 6) & 0x3F));
	utf8_string += static_cast<char>(0x80 | (unicode & 0x3F));

	return utf8_string;
}

int utf8toUnicode(string str) 
{
	int res = 0;
	res += ((str[0] & 0x0F) << 12);
	res += ((str[1] & 0x3C) << 6);
	int fr = ((str[1] & 0x03));
	int rear = (str[2] & 0x30) >> 4;
	res += (((fr << 2) | rear) << 4);
	res += (str[2] & 0x0F);
	return res;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//::SetConsoleOutputCP(65001);
	//xEAxB0x80
	//string str = "\xEB\x82\x98";
	//string ga = "\xEA\xB0\x80";
	string str;
	cin >> str;
	//cout << unicodeToUTF8(45208) << '\n';
	
	cout << utf8toUnicode(str) - 44031;

	return 0;
}
