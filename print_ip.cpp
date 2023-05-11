#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <tuple>


template <typename T>
void printIp(T&) {

}

template<>
void printIp <std::vector<int>>(std::vector<int>&) {

}


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