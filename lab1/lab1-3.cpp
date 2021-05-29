#include <iostream>
inline int  Area(int x,int y) {return(x)*(y);}

int main(){
	double n=Area(3,5.1);
	std::cout << "Area="<<n<<std::endl;
	return 0;
}