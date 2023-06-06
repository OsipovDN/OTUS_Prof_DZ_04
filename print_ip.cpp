#include <iostream>
#include <iomanip>
#include <type_traits>
#include <string>
#include <vector>
#include <list>
#include <bitset>

//Синоним для простого доступа к полю структуры
template <typename T>
auto isConteiner_v = isConteiner<T>::value;
//false- если не контейнер
template <typename T>
struct isConteiner :std::false_type {};
//true- если std::vector
template <typename Alloc>
struct isConteiner <std::vector<int,Alloc>>:std::true_type {};
//true- если std::list
template <typename Alloc>
struct isConteiner <std::list<int, Alloc>> :std::true_type {};

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
template <typename T,bool= isConteiner_v <T>>
void ipPrint(const T& obj) {};

template <typename T>
void ipPrint(const T& obj) {
	if (isConteiner_v <T>) {
		int i = 0;
		for (auto& it : obj) {
			std::cout << it;
			if (i != 3)
				std::cout << ".";
			i++;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "hear" << std::endl;
};


//template <typename T>
//std::enable_if_t<std::is_integral_v <T>, std::string> ipPrint(const T&) {};


int main() {

	/*char a = -1;*/
	/*int b = 2130706433;
	long long c = 8875824491850138409;*/

	/*ipPrint(a);*/
	/*ipPrint(b);*/
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