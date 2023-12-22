#include "Application.h"

void Application::Run() {
	srand(time(nullptr));
	try {
		bool b = true;
		Rational num1;
		std::cout << "Num1 = " << num1 << std::endl;
		Rational num2;
		std::cout << "Num2 = " << num2 << std::endl;
		do {
			short key;
			std::cout << "\n---------------------------- Test menu ----------------------------\n";
			std::cout << " 1: make new Nums\n 2: add\n 3: subtract\n 4: multipfy\n 5: divide\n 6: check equality\n 7: check greater\n 8: check lesser\n 9: check LongLong's count\n 10: check Rational's count\n 11: clscr \n 12: exit\n";
			std::cin >> key;
			switch (key) {
			case 1: num1.generate(); std::cout << "Num1 = " << num1 << std::endl;
				num2.generate(); std::cout << "Num1 = " << num1 << std::endl;
				break;
			case 2: std::cout << "\nNum1 + Num2 = " << num1 + num2 << std::endl; break;
			case 3: std::cout << "\nNum1 - Num2 = " << num1 - num2 << std::endl; break;
			case 4: std::cout << "\nNum1 * Num2 = " << num1 * num2 << std::endl; break;
			case 5: std::cout << "\nNum1 / Num2 = " << num1 / num2 << std::endl; break;
			case 6: std::cout << "\nNum1 == Num2?  " << (num1 == num2) << std::endl; break;
			case 7: std::cout << "\nNum1 > Num2?  " << (num1 > num2) << std::endl; break;
			case 8: std::cout << "\nNum1 < Num2? " << (num1 < num2) << std::endl; break;
			case 9: std::cout << "\nLongLong's count is equal to " << LongLong::getcount() << std::endl; break;
			case 10: std::cout << "\nRational's count is equal to " << Rational::getcount() << std::endl; break;
			case 11: system("cls"); break;
			case 12: b = false; break;
			default: std::cout << "Error! Entered command doesn't exist!\n";
			}
		} while (b);
	}
	catch (std::exception& error) {
		std::cout << error.what() << std::endl;
	}
	system("pause");
}
