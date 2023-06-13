#include <iostream>
#include <type_traits>
#include <string>
#include <vector>
#include <list>
#include <cmath>
#include <bitset>


//metafunction for determining the type of variable (container or not)
template <typename T>
struct isConteiner :std::false_type {};
//true- if std::vector
template <typename T,typename Alloc>
struct isConteiner <std::vector<T, Alloc>> :std::true_type {};
//true- if std::list
template <typename T,typename Alloc>
struct isConteiner <std::list<T, Alloc>> :std::true_type {};

//Conversion function from binary representation to decimal
int strToInt(std::string obj) {
	int i = 7;
	int res = 0;
	for (auto it : obj) {
		int val = static_cast<int>(it - '0');
		res += val * static_cast<int>(std::pow(2, i));
		i--;
	}
	return res;
}

//Template of the conversion function std::string in std::vector <int>- vec {255,255,255,255}
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

//Specialization for containers
template <typename T>
typename std::enable_if_t<isConteiner<T>::value> print_ip(T& obj) {
	size_t i = 0;
	for (auto& it : obj) {
		std::cout << it;
		i++;
		if (i != obj.size()) std::cout << ".";
	}
	std::cout << std::endl;
}

//Specialization for integer variables
template <typename T>
typename std::enable_if_t<std::is_integral_v<T>>
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

//Template for a string variable
template <typename T>
typename std::enable_if_t< std::is_same <T, std::string>::value> print_ip(T& obj) {
	std::cout << obj << std::endl;
}

int main() {

	int8_t a = -1;
	int16_t b = 0;
	int32_t c = 2130706433;
	int64_t d = 8875824491850138409;
	//Output to the console for integer values
	print_ip(a);
	print_ip(b);
	print_ip(c);
	print_ip(d);

	std::string str = { "Hello, World!" };
	//Output to the console for string values
	print_ip(str);

	std::vector <int> vec_ip = { 100,200,300,400 };
	std::list<short> list_ip;
	for (auto i = 0; i < 4; ++i)
		list_ip.emplace_back(static_cast <short>(400 - i * 100));
	//Output to the console for std::vector and std::list
	print_ip(vec_ip);
	print_ip(list_ip);

	return 0;
}