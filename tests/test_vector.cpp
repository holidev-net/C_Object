/*
** EPITECH PROJECT, 2017
** C_Object
** File description:
** test_vector.cpp
*/

#include <vector>
#include <iostream>

int main()
{
	std::vector<int> vec;

	std::cout << "vec size : " << vec.size() << "  capacity : " << vec.capacity() << std::endl;

	vec.assign(10, 0);
	std::cout << "vec size : " << vec.size() << "  capacity : " << vec.capacity() << std::endl;
	vec.resize(100);
	std::cout << "vec size : " << vec.size() << "  capacity : " << vec.capacity() << std::endl;
	vec.reserve(1000);
	std::cout << "vec size : " << vec.size() << "  capacity : " << vec.capacity() << std::endl;
	vec.reserve(400);
	std::cout << "vec size : " << vec.size() << "  capacity : " << vec.capacity() << std::endl;
	vec.resize(200);
	std::cout << "vec size : " << vec.size() << "  capacity : " << vec.capacity() << std::endl;
	vec.shrink_to_fit();
	std::cout << "vec size : " << vec.size() << "  capacity : " << vec.capacity() << std::endl;
	vec.reserve(0);
	std::cout << "vec size : " << vec.size() << "  capacity : " << vec.capacity() << std::endl;
	std::cout << "clear" << std::endl;
	vec.clear();
	std::cout << "vec size : " << vec.size() << "  capacity : " << vec.capacity() << std::endl;
	vec.resize(0);
	std::cout << "vec size : " << vec.size() << "  capacity : " << vec.capacity() << std::endl;
	vec.reserve(0);
	std::cout << "vec size : " << vec.size() << "  capacity : " << vec.capacity() << std::endl;
	vec.shrink_to_fit();
	std::cout << "vec size : " << vec.size() << "  capacity : " << vec.capacity() << std::endl;
	for (int i = 0; i < 500; ++i) {
		vec.push_back(i);
		std::cout << "vec size : " << vec.size() << "  capacity : " << vec.capacity() << std::endl;
	}
	vec.clear();
	vec.shrink_to_fit();
	vec.assign(40, 0);
	std::cout << "vec size : " << vec.size() << "  capacity : " << vec.capacity() << std::endl;
	for (int i = 0; i < 30; ++i) {
		vec.push_back(i);
		std::cout << "vec size : " << vec.size() << "  capacity : " << vec.capacity() << std::endl;		
	}	
}