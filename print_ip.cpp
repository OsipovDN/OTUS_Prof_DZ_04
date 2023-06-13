#include <iostream>
#include <type_traits>
#include <string>
#include <vector>
#include <list>
#include <bitset>

//Синоним для простого доступа к полю структуры
template <typename T>
static const bool isConteiner_v = isConteiner<T>::value;
//метафункция для определения типа переменной (контейнер или нет)
template <typename T>
struct isConteiner :std::false_type {};
//true- если std::vector
template <typename Alloc>
struct isConteiner <std::vector<int, Alloc>> :std::true_type {};
//true- если std::list
template <typename Alloc>
struct isConteiner <std::list<int, Alloc>> :std::true_type {};

//Функция преобразования из двоичного представления в десятичное
int strToInt(std::string obj) {
	int i = 7;
	int res = 0;
	for (auto it : obj) {
		int val = static_cast<int>(it - '0');
		res += val * static_cast<int>(pow(2, i));
		i--;
	}
	return res;
}

//Шаблон функции преобразования std::string в std::vector <int>- vec {255,255,255,255}
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

}

//Специализация для контейнеров
template <typename T>
typename std::enable_if_t<isConteiner_v<T>, void> print_ip(T& obj) {
	int i = 0;
	for (auto& it : obj) {
		std::cout << it;
		i++;
		if (i != obj.size()) std::cout << ".";
	}
	std::cout << std::endl;
}

//Специализация для целочисленных переменных
template <typename T>
typename std::enable_if_t<std::is_integral_v<T>, void>
print_ip(T& obj) {
	size_t i = 0;
	std::vector<int> temp = transform <T>(obj);
	for (auto& it : temp) {
		std::cout << it;
		i++;
		if (i != temp.size())std::cout << ".";
	}
	std::cout << std::endl;
}

//Шаблон для строковой переменной
template <typename T>
typename std::enable_if_t< std::is_same <T, std::string>::value, void> print_ip(T& obj) {
	std::cout << obj << std::endl;
}

int main() {

	int8_t a = -1;
	int16_t b = 0;
	int32_t c = 2130706433;
	int64_t d = 8875824491850138409;
	//Вывод в консоль для целочисленных значений
	print_ip(a);
	print_ip(b);
	print_ip(c);
	print_ip(d);

	std::string str = { "Hello, World!" };
	//Вывод в консоль для строкового значений
	print_ip(str);

	std::vector <int> vec_ip = { 100,200,300,400 };
	std::list<int> list_ip;
	for (auto i = 0; i < 4; ++i)
		list_ip.emplace_back(400 - i*100);
	//Вывод в консоль для контейнеров std::vector и std::list
	print_ip(vec_ip);
	print_ip(list_ip);

	return 0;
}