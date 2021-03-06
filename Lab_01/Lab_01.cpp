#include <iostream>
#include <cmath>
#include <cstdlib>
#include "TRIANGLE.h"
#include "HEXAGON.h"
#include "OCTAGON.h"
// 6-угольник, 8-угольник, 3-угольник

int main(){
	std::cout << "Figure? \n 1 - Triangle,2 - Hexagon,3 - Octagon,4 - End programm" << std::endl;
	int fig;
	std::cin >> fig;
	if (fig == 4) {
		return 0;
	}
	if (fig == 1) {
		std::cout << "Enter sides sizes of triangle" << std::endl;
		//FIGURE *tri = new TRIANGLE (std::cin);
		int a, b, c;
		std::cout << "a?" << std::endl;
		std::cin >> a;
		std::cout << "b?" << std::endl;
		std::cin >> b;
		std::cout << "c?" << std::endl;
		std::cin >> c;
		FIGURE *tri = new TRIANGLE(a, b, c);
		tri->PRINT();
		std::cout << "Square of your triangle is " << tri->SQUARE() << std::endl;
		delete tri;
	}
	if (fig == 2) {
		std::cout << "Enter side size of regular hexagon" << std::endl;
		//FIGURE *hex = new HEXAGON(std::cin);
		int a;
		std::cout << "a?" << std::endl;
		std::cin >> a;
		FIGURE *hex = new HEXAGON(a);
		hex->PRINT();
		std::cout << "Square of your regular hexagon is " << hex->SQUARE() << std::endl;
		delete hex;
	}
	if (fig == 3) {
		std::cout << "Enter side size of regular octagon" << std::endl;
		//FIGURE *oct = new OCTAGON(std::cin);
		int a;
		std::cout << "a?" << std::endl;
		std::cin >> a;
		FIGURE *oct = new OCTAGON(a);
		oct->PRINT();
		std::cout << "Square of your regular octagon is " << oct->SQUARE() << std::endl;
		delete oct;
	}	
	std::cout << "Enter any symbol to end programm" << std::endl;
	std::cin >> fig;
	return 0;
}