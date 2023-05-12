#include <iostream>
#include <iomanip>
#include <type_traits>
#include <string>
#include <vector>
#include <list>
#include <tuple>
#include <bitset>

//Шаблоны для определения контейнер или нет
template <typename T>
auto isConteiner_v = isConteiner<T>::value;
//false- если не контейнер
template <typename T>
struct isConteiner {
	static const bool value = false;
};
//true- если std::vector
template <>
struct isConteiner <std::vector<int>> {
	static const bool value = true;
};
//true- если std::list
template <>
struct isConteiner <std::list<int>> {
	static const bool value = true;
};

//Шаблон для функции преобразования
template<typename T>
std::vector<int> transform(const T& val) {
	std::bitset <sizeof(T) * 8> bit_obj(val);
	std::vector <int> ip;
	int byte = 0;
	int j = 0;
	for (int i = static_cast<int>((bit_obj.size() - 1)); i >= 0; --i) {
		byte +=static_cast<int>( bit_obj[i] * pow(2, 7 - j));
		if (j == 7) {
			ip.push_back(byte);
			byte = 0;
			j = 0;
			if (i != 0)
				--i;
		}
		j++;
	}
	return ip;
}

//Шаблонная функция print для контейнеров
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
	/*std::vector <int> vec_ip = { 255,255,255,255 };
	std::list<int> list_ip;
	for (auto i = 0; i < 4; ++i)
		list_ip.emplace_back(200 + i);*/

	/*ipPrint(a);
	ipPrint(b);
	ipPrint(c);*/

	/*ipPrint(vec_ip);
	ipPrint(list_ip);*/
	char a = -1;
	//long long b = 8875824491850138409;
	//int c = 2130706433;
	std::vector<int> res;
	res= transform <char>(a);
	for (auto it : res) {
		std::cout << it << " ";
	}



	return 0;
}