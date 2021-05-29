#include <iostream>
#define Pi 3.1416
#ifndef Pi
#define Pi 3.14159
#endif
int main(){
	std::cout << Pi <<std::endl;
	return 0;
}