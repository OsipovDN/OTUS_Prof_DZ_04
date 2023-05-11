#include <iostream>
#include <iomanip>
#include <type_traits>
#include <string>
#include <vector>
#include <list>
#include <tuple>

//Шаблоны для определения контейнер или нет
template <typename T>
auto type_v = isConteiner<T>::value;

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
void ipPrint(const T& obj, typename isConteiner < T >::type_value = 0) {

};


template <typename T>
std::enable_if_t<std::is_floating_point_v <T>, std::string> ipPrint(const T&) {};






int main() {

	char a = -1;
	int b = 2130706433;
	long long c = 8875824491850138409;
	/*std::string f;;*/
	std::vector <int> g = {255,255,255,255 };

	/*ipPrint(a);
	ipPrint(b);
	ipPrint(c);*/

	ipPrint(g);



	return 0;
}