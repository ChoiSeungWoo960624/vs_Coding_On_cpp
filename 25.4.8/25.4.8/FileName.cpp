/*
#include <iostream>
#include <string>
#include <tyeinpor>
using namespace std;

	bool isCheck(string s) 
	{
 	for (char c : s) 
	{
 		if (!isdigit(c)) 
		{
 			return false;
 		}
 	}
 	return true;

int main()
{
	string s1 = "hello";
	string s2 = "world";

	cout << s1 + s2 << endl;
	cout << (s1 < s2) << endl;

	string sentence;
	cout << "������ �Է��ϼ���: ";
	getline(cin, sentence); //getline - ������ ����ؼ� ���ڸ� �� �� �ִ�.
	cout << "����� �Է��� ������: " << sentence << endl;

	// string �Լ�
	cout << "s1.at(2): " << s1.at(2) << endl;
	cout << "s2.at(2): " << s2.at(2) << endl;

	cout << "s1[4]: " << s1[4] << endl;
	cout << "s2[2]: " << s2[2] << endl;

	cout << "s1.back(): " << s1.back() << endl;
	cout << "s1.front(): " << s1.front() << endl;

	cout << "s2.back(): " << s2.back() << endl;
	cout << "s2.front(): " << s2.front() << endl;

	cout << "s1.length(): " << s1.length() << endl;
	cout << "s1.size(): " << s1.size() << endl;

	s1.resize(10);
	cout << s1 << endl;
	cout << "s1.length(): " << s1.length() << endl;

	s1.resize(11, 'a');
	cout << "s1.resize(11, 'a') : " << s1 << endl;
	cout << s1.length() << s1.length() << endl;

	string s3 = "";
	cout << "s3.empty() : " << s3.empty() << endl; // �ƹ��͵� ������ "����" 1 ���´�

	string s4 = "Ȯ�ο�";
	s3.append(s4);
	cout << "s3 : " << s3 << endl;

	s3.append(s4, 3, 4);  // �����ڵ� �ε��� ����
	cout << "s3.append(s4, 3, 4) : " << s3 << endl;

	s3.insert(1, s4);
	cout << "s3.append(1, s4) : " << s3 << endl;

	s3.replace(1, 3, s4);
	cout << "s3.replace(1, 3, s4) : " << s3 << endl;

	s3.clear();
	cout << "s3.clear() : " << s3 << endl;

	s3.erase(1, 2);
	cout << "s3.erase(1, 2) : " << s3 << endl;

	s3 += s4;
	cout << "s3 :" << s3 << endl;

	string s5 = "!";
	cout << "s3.find(!) : " << s3.find(s5) << endl;
	cout << "s3.find(!, 6) : " << s3.find(s5, 6) << endl;
	
	size_t pos = s3.find(s5);
	// ���ڿ��� ã���� ����
	// ��ã���� npos�� ���� ����
	if (pos != string::npos) 
	{
		cout << "ã�� ���ڿ� ù �ε���: " << pos << endl;
	}

	cout << "s3.substr(3) : " << s3.substr(3) << endl;
	cout << "s3.substr(3, 3) : " << s3.substr(3, 3) << endl;

	string s6 = "ccccc";
	string s7 = "bbbbb";
	cout << "s6.compare(s7) : " << s6.compare(s7) << endl;
	
	cout << "isdigit('5') :" << isdigit('5') << endl;
 	cout << "isdigit('a') :" << isdigit('a') << endl;
 
 	cout << "isalpha('3') :" << isalpha('3') << endl;
 	cout << "isalpha('a') :" << isalpha('a') << endl;
 
 	cout << "toupper('a') :" << char(toupper('a')) << endl;
 	cout << "toupper('C') :" << char(toupper('C')) << endl;
 
 	cout << "tolower('C') :" << char(tolower('C')) << endl;
 	cout << "tolower('b') :" << char(tolower('b')) << endl;
 
 	cout << "stoi('19') :" << typeid(stoi("19")).name() << endl;
 	cout << "stof('19.23') :" << typeid(stof("19.23")).name() << endl;
 
 	cout << "to_string(19.23) :" << typeid(to_string(19.23)).name() << endl;

}

//�ǽ� 1 string����غ���

#include <iostream>
#include <string>

using namespace std;

int main() 
{
	string s = "Police say two people are suspected of trying to create a shortcut for their construction work. The two have been detained and the case is under further investigation. The 38-year-old man and 55-year-old woman were working near the affected area, the 32nd Great Wall.";

	cout << "���ڿ� ����: " << s.length() << endl;

	if (s.length() > 100) 
	{
		cout << "100��° ����: " << s.at(100) << endl;
	}
	else 
	{
		cout << "���ڿ� ���̰� ��.��. !!" << endl;
	}

	size_t firstPos = s.find("two"); // ���
	if (firstPos != string::npos) 
	{
		cout << "\"two\"�� ù ��° ��ġ: " << firstPos << endl;
	}

	size_t secondPos = s.find("two", firstPos + 1);
	if (secondPos != string::npos) 
	{
		cout << "\"two\"�� �� ��° ��ġ: " << secondPos << endl;
	}

	return 0;
}

//�ǽ� 2 string ����غ���
#include <iostream>
#include <string>

using namespace std;

int main() {
	string s = "Codingon";
	cout << s << endl;

	if (s[0] >= 'A' && s[0] <= 'Z') {
		s[0] = s[0] + 32;
	}
	cout << s << endl;

	string sub1 = s.substr(2, 4);
	cout << sub1 << endl;

	s = "c" + string(6, 'o') + "n";
	cout << s << endl;

	s = "con";
	cout << s << endl;

	return 0;
}
*/
// �ǽ�3.string ����غ���
#include <iostream>
#include <string>

using namespace std;

bool is_all_digits(const string& str) {
	for (char ch : str) {
		if (ch < '0' || ch > '9') {
			return false;
		}
	}
	return true;
}

int main() {
	string s1, s2;

	while (true) {
		cout << "ù ��° ���� �Է�: ";
		cin >> s1;

		cout << "�� ��° ���� �Է�: ";
		cin >> s2;

		if (is_all_digits(s1) && is_all_digits(s2)) {
			break;
		}
		else {
			cout << "���ڸ� �Է��ؾ� �մϴ�. �ٽ� �Է��ϼ���.\n";
		}
	}

	string combined = s1 + s2;
	cout << "�̾���� ���: " << combined << endl;

	int num1 = stoi(s1);
	int num2 = stoi(s2);
	cout << "���� ��: " << num1 + num2 << endl;

	return 0;
}
