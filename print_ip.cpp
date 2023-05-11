#include <iostream>
#include <iomanip>
#include <type_traits>
#include <string>
#include <vector>
#include <list>
#include <tuple>

//������� ��� ����������� ��������� ��� ���
template <typename T>
auto isConteiner_v = isConteiner<T>::value;
//false- ���� �� ���������
template <typename T>
struct isConteiner {
	static const bool value = false;
};
//true- ���� std::vector
template <>
struct isConteiner <std::vector<int>> {
	static const bool value = true;
};
//true- ���� std::list
template <>
struct isConteiner <std::list<int>> {
	static const bool value = true;
};


//��������� ������� print ��� �����������
template <typename T>
void ipPrint(const T& obj, bool d = isConteiner_v <T>) {
	if (d) {
		int i = 0;
		for (auto& it:obj) {
			std::cout << it;
			if (i != 3)
				std::cout << ".";
			i++;
		}
		std::cout << std::endl;
	}
	else {
		
	}
};


//template <typename T>
//std::enable_if_t<std::is_floating_point_v <T>, std::string> ipPrint(const T&) {};






int main() {

	/*char a = -1;
	int b = 2130706433;
	long long c = 8875824491850138409;*/
	/*std::string f;;*/
	std::vector <int> vec_ip = { 255,255,255,255 };
	std::list<int> list_ip;
	for (auto i = 0; i < 4; ++i)
		list_ip.emplace_back(200 + i);

	/*ipPrint(a);
	ipPrint(b);
	ipPrint(c);*/

	ipPrint(vec_ip);
	ipPrint(list_ip);



	return 0;
}