#include "Hex_List.h"
#include "Hexagon.h"
#include "ListItem.h"
#include <iostream>

int main(){
	int digit = 0;
	int thing;
	Hex_List list;
	//std::cin >> side_size;
	//list.Add(side_size);
	//std::cout << list;
	while (1) {
		std::cout <<std::endl << "What would you like to do?" << std::endl;
		std::cout << "1.Add new hexagon to list|2.Extract hexagon from list|";
		std::cout << "3.Remove hexagon from list|4.Print list|5.End programm" << std::endl;
		std::cin >> digit;
		switch (digit) {
		case (1):
			std::cout << "Enter size of side of new hexagon" << std::endl;
			std::cin >> thing;
			//std::cout << HEXAGON(thing) << thing;
			list.Add(Hexagon(thing));
			std::cout << "New element added" << std::endl;// << list.GetSize() << std::endl;
			break;
		case (2):
			std::cout << "Chose position of element to extract" << std::endl;
			std::cin >> thing;
			if (list.GetSize() < thing) {
				std::cout << "Wrong position of element" << std::endl;
			}
			else {
				std::cout << list.Extract(thing) << std::endl;
			}
			break;
		case (3):
			std::cout << "Enter size of side of hexagon" << std::endl;
			std::cin >> thing;
			if (list.Remove(thing)) {
				std::cout << "Element successefully deleted" << std::endl;
			}
			else {
				std::cout << "No element to delete" << std::endl;
			}
			break;
		case (4):
			std::cout << list;
			break;
		case (5):
			std::cout << "Ending programm..." << std::endl;
			return 0;
			break;
		default:
			std::cout << "Wrong command" << std::endl;
			break;
		}
	}
}

