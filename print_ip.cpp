#include <iostream>
#include <iomanip>
#include <type_traits>
#include <string>
#include <vector>
#include <list>
#include <tuple>

//Шаблоны для определения контейнер или нет
template <typename T>
struct isConteiner {
	static const bool type_value = false;
};

template <>
struct isConteiner <std::vector<int>> {
	static const bool type_value = true;
};

template <>
struct isConteiner <std::list<int>> {
	static const bool type_value = true;
};



template <typename T>
void ipPrint(const T&, isConteiner < T >) {

};


template <typename T>
std::enable_if_t<std::is_floating_point_v <T>, std::string> ipPrint(const T&) {};






int main() {

	char a = -1;
	int b = 2130706433;
	long c = 8875824491850138409;
	/*std::string f;
	std::vector <int> g;
	std::list <int> h;*/

	ipPrint(a);
	ipPrint(b);
	ipPrint(c);



	return 0;
}