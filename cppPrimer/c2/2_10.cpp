//2_10
#include <iostream>
using namespace std;

std::string global_str;

int global_int;

int main() {
	std::cout << "global_str:" << global_str << endl;//�� 
	std::cout << "global_int:" << global_int <<endl;//0
	int local_int;
	cout << "local_int:" << local_int << endl;//0
	std::string local_str;
	cout << "local_str:" << local_str << endl;//�� 
	
	return 0;
}
