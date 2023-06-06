#include <iostream>
#include <iomanip>
#include <type_traits>
#include <string>
#include <vector>
#include <list>
#include <bitset>

//������� ��� �������� ������� � ���� ���������
template <typename T>
auto isConteiner_v = isConteiner<T>::value;
//false- ���� �� ���������
template <typename T>
struct isConteiner :std::false_type {};
//true- ���� std::vector
template <typename Alloc>
struct isConteiner <std::vector<int, Alloc>> :std::true_type {};
//true- ���� std::list
template <typename Alloc>
struct isConteiner <std::list<int, Alloc>> :std::true_type {};

//������� �������������� �� ��������� ������������� � ����������
int strToInt(std::string obj) {
	int i = 7;	///< ���������� ��� ������� ���������
	int res = 0;
	for (auto it : obj) {
		int val = static_cast<int>(it - '0');
		res += val * (int)(pow(2, i));
		i--;
	}
	return res;
}

//������ ������� �������������� std::string � std::vector <int>- vec {255,255,255,255}
template<typename T>
std::vector<int> transform(T& val) {
	std::vector<int> vec_byte;
	std::string byte;

	std::bitset <sizeof(T) * 8> obj(val);
	std::string bit_pul = obj.to_string();
	std::string::size_type start = 0;
	std::string::size_type stop = bit_pul.size();

	while (start != stop) {
		byte = bit_pul.substr(start, 8);
		vec_byte.push_back(strToInt(byte));
		start += 8;
	}
	return vec_byte;

};

//////��������� ������� print
//template <typename T,bool>
//void ipPrint(const T& obj) {};
//
////������������� ��� �����������
//template <typename T, bool = isConteiner_v<T>>
// void ipPrint <T,true>(const T& obj) {
//	int i = 0;
//	for (auto& it : obj) {
//		std::cout << it;
//		i++;
//		if (i != temp.size()) std::cout << ".";
//	}
//	std::cout << std::endl;
//};

//������������� ��� ������������� ����������
template <typename T>
void ipPrint(T& obj) {
	int i = 0;
	std::vector<int> temp = transform <T>(obj);
	for (auto& it : temp) {
		std::cout << it;
		i++;
		if (i != temp.size())std::cout << ".";
	}
	std::cout << std::endl;
};



int main() {

	char a = -1;
	int b = 2130706433;
	long long c = 8875824491850138409;

	ipPrint(a);
	ipPrint(b);
	ipPrint(c);

	/*std::vector <int> vec_ip = { 255,255,255,255 };
	std::list<int> list_ip;
	for (auto i = 0; i < 4; ++i)
		list_ip.emplace_back(200 + i);

	ipPrint(vec_ip);
	ipPrint(list_ip);*/

	/*std::string f;*/
	/*std::vector<int> res;
	res= transform <char>(a);
	for (auto it : res) {
		std::cout << it << " ";
	}*/



	return 0;
}