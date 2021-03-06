#include <iostream>
#include <memory>
#include <cstdlib>
#include "List.h"

int main() {
	List <ListItem, Triangle, Hexagon, Octagon> list;
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
			switch (fig) {
			case (1):
				std::cout << "Enter size of sides of new triangle" << std::endl;
				std::cin >> thing >> side_b >> side_c;
				list.Add_figure(std::shared_ptr<ListItem<Triangle, Hexagon, Octagon>>(new ListItem<Triangle, Hexagon, Octagon>(std::shared_ptr<Triangle>(new Triangle(thing, side_b, side_c)))));
				std::cout << "New element added" << std::endl;
				break;
			case (2):
				std::cout << "Enter size of side of new hexagon" << std::endl;
				std::cin >> thing;
				list.Add_figure(std::shared_ptr<ListItem<Triangle, Hexagon, Octagon>>(new ListItem<Triangle, Hexagon, Octagon>(std::shared_ptr<Hexagon>(new Hexagon(thing)))));
				std::cout << "New element added" << std::endl;
				break;
			case (3):
				std::cout << "Enter size of side of new octagon" << std::endl;
				std::cin >> thing;
				list.Add_figure(std::shared_ptr<ListItem<Triangle, Hexagon, Octagon>>(new ListItem<Triangle, Hexagon, Octagon>(std::shared_ptr<Octagon>(new Octagon(thing)))));
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
				if (list.Extract_ffigure(thing) != nullptr) {
					std::cout << *list.Extract_ffigure(thing) << std::endl;
				}
				if (list.Extract_sfigure(thing) != nullptr) {
					std::cout << *list.Extract_sfigure(thing) << std::endl;
				}
				if (list.Extract_tfigure(thing) != nullptr) {
					std::cout << *list.Extract_tfigure(thing) << std::endl;
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
				list.Remove_figure(ListItem<Triangle, Hexagon, Octagon>(std::shared_ptr<Triangle>(new Triangle(thing, side_b, side_c))));
				//std::cout << "Element deleted" << std::endl;
				break;
			case (2):
				std::cout << "Enter size of side of hexagon" << std::endl;
				std::cin >> thing;
				list.Remove_figure(ListItem<Triangle, Hexagon, Octagon>(std::shared_ptr<Hexagon>(new Hexagon(thing))));
				//std::cout << "Element deleted" << std::endl;
				break;
			case (3):
				std::cout << "Enter size of side of octagon" << std::endl;
				std::cin >> thing;
				list.Remove_figure(ListItem<Triangle, Hexagon, Octagon>(std::shared_ptr<Octagon>(new Octagon(thing))));
				//std::cout << "Element deleted" << std::endl;
				break;
			default:
				std::cout << "Wrong figure" << std::endl;
				break;
			}
		}
		if (digit == 4) {
			for (auto i : list) {
				std::cout << *i << std::endl;
			}
		}
		if (digit == 5) {
			break;
		}
	}
}