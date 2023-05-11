#include <iostream>
#include <iomanip>
#include <type_traits>
#include <string>
#include <vector>
#include <list>
#include <tuple>


template <typename T>
std::enable_if_t <std::is_integral_v <T>, std::string> printIp(const T&);

template <typename T>
std::enable_if_t<std::is_floating_point_v <T>, std::string> printIp(const T&);



int main() {

	/*char a = -1;
	short b = 0;
	int c = 2130706433;
	long d = 8875824491850138409;
	std::string f;
	std::vector <int> g;
	std::list <int> h;*/


	return 0;
}