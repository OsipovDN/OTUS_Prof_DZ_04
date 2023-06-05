#include <iostream>
#include <iomanip>
#include <type_traits>
#include <string>
#include <vector>
#include <list>
#include <bitset>

/*! \brief Шаблоны для определения контейнер или нет(alias)

	Алиас для простого доступа к полю структуры
*/
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

//Функция преобразования из двоичного представления в десятичное
int strToInt(std::string obj) {
	int i = 7;	///< Переменная для расчета фкториала
	int res = 0;
	for (auto it : obj) {
		int val = static_cast<int>(it - '0');
		res += val * (int)(pow(2, i));
		i--;
	}
	return res;
}

//Шаблон функции преобразования std::string в std::vector <int>- vec {255,255,255,255}
template<typename T>
std::vector<int> transform(T& val) {
	std::bitset <sizeof(T) * 8> obj(val);
	std::string bit_pul = obj.to_string();
	std::string::size_type start = 0;
	std::string::size_type stop = bit_pul.size();

	std::vector<int> vec_byte;
	std::string byte;

	while (start != stop) {
		byte = bit_pul.substr(start, 8);
		vec_byte.push_back(strToInt(byte));
		start += 8;
	}
	return vec_byte;
}

//Шаблонная функция print для контейнеров
template <typename T, bool = isConteiner_v <T>>
std::enable_if_t<isConteiner_v <T>, void> ipPrint(const T& obj) {};

template <typename T>
std::enable_if_t<true, void> ipPrint(const T& obj) {
	int i = 0;
	for (auto& it : obj) {
		std::cout << it;
		if (i != 3)
			std::cout << ".";
		i++;
	}
	std::cout << std::endl;
};

template <typename T>
std::enable_if_t<false, void> ipPrint(const T& obj) {};


//template <typename T>
//std::enable_if_t<std::is_integral_v <T>, std::string> ipPrint(const T&) {};


int main() {

	/*char a = -1;
	int b = 2130706433;
	long long c = 8875824491850138409;*/

	/*ipPrint(a);
	ipPrint(b);*/
	//ipPrint(c);

	std::vector <int> vec_ip = { 255,255,255,255 };
	std::list<int> list_ip;
	for (auto i = 0; i < 4; ++i)
		list_ip.emplace_back(200 + i);

	ipPrint(vec_ip);
	ipPrint(list_ip);

	/*std::string f;*/
	/*std::vector<int> res;
	res= transform <char>(a);
	for (auto it : res) {
		std::cout << it << " ";
	}*/



	return 0;
}