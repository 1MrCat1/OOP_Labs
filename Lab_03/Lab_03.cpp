#include <iostream>
#include <memory>
#include "List.h"
#include "ListItem.h"
#include "Hexagon.h"
#include "Triangle.h"
#include "Octagon.h"

int main(){
	List list;
	int digit = 0;
	int fig = 0;
	int thing;
	int side_b;
	int side_c;
	while (1) {
		std::cout << std::endl << "What would you like to do?" << std::endl;
		std::cout << "1.Add new figure to list|2.Extract figure from list|";
		std::cout << "3.Remove figure from list|4.Print list|5.End programm" << std::endl;
		std::cin >> digit;
		if (digit == 1) {
			std::cout << "Which figure would you like to add?" << std::endl;
			std::cout << "1-Triangle, 2-Hexagon, 3-Octagon." << std::endl;
			std::cin >> fig;
			switch (fig){
			case (1):
				std::cout << "Enter size of sides of new triangle" << std::endl;
				std::cin >> thing >> side_b >> side_c;
				list.Add_Triangle(std::shared_ptr<Triangle>(new Triangle(thing, side_b, side_c)));
				std::cout << "New element added" << std::endl;
				break;
			case (2):
				std::cout << "Enter size of side of new hexagon" << std::endl;
				std::cin >> thing;
				list.Add_Hexagon(std::shared_ptr<Hexagon>(new Hexagon(thing)));
				std::cout << "New element added" << std::endl;
				break;
			case (3):
				std::cout << "Enter size of side of new octagon" << std::endl;
				std::cin >> thing;
				list.Add_Octagon(std::shared_ptr<Octagon>(new Octagon(thing)));
				std::cout << "New element added" << std::endl;
				break;
			default:
				std::cout << "Wrong figure" << std::endl;
				break;
			}
		}
		if (digit == 2) {
			std::cout << "Chose position of element to extract" << std::endl;
			std::cin >> thing;
			if (list.GetSize() < thing) {
				std::cout << "Wrong position of element" << std::endl;
			}
			else {
				if (list.Extract_triangle(thing) != nullptr) {
					std::cout << *list.Extract_triangle(thing) << std::endl;
				}
				if (list.Extract_hexagon(thing) != nullptr) {
					std::cout << *list.Extract_hexagon(thing) << std::endl;
				}
				if (list.Extract_octagon(thing) != nullptr) {
					std::cout << *list.Extract_octagon(thing) << std::endl;
				}
			}
		}
		if (digit == 3) {
			std::cout << "Which figure would you like to remove?" << std::endl;
			std::cout << "1-Triangle, 2-Hexagon, 3-Octagon." << std::endl;
			std::cin >> fig;
			switch (fig) {
			case (1):
				std::cout << "Enter size of sides of triangle" << std::endl;
				std::cin >> thing >> side_b >> side_c;
				list.Remove_triangle(Triangle(thing, side_b, side_c));
				//std::cout << "Element deleted" << std::endl;
				break;
			case (2):
				std::cout << "Enter size of side of hexagon" << std::endl;
				std::cin >> thing;
				list.Remove_hexagon(Hexagon(thing));
				//std::cout << "Element deleted" << std::endl;
				break;
			case (3):
				std::cout << "Enter size of side of octagon" << std::endl;
				std::cin >> thing;
				list.Remove_octagon(Octagon(thing));
				//std::cout << "Element deleted" << std::endl;
				break;
			default:
				std::cout << "Wrong figure" << std::endl;
				break;
			}
		}
		if (digit == 4) {
			std::cout << list;
		}
		if (digit == 5) {
			break;
		}
		if ((digit<1)||(digit > 5)) {
			std::cout << "Wrong command" << std::endl;
		}
	}
}
