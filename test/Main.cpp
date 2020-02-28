#include "pch.hpp"
#include "UAV/uavOS.hpp"
int main(int argc, char** argv){
	for(int i = 0; i < argc; i++){
		std::cout << argv[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}