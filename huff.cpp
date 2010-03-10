#include <iostream>
#include "HuffmanTree.h"
#include <map>
#include "BuildTree.h"

int main ()
{
	std::map<std::string, unsigned long> table;
	while (!std::cin.eof())
	{
		std::string value;
		unsigned long frequency;
		std::cin >> frequency;
		std::cin >> value;
		if (value != "")
			table.insert(std::make_pair(value, frequency));
	}
	HuffmanTree tree = BuildTree(table);
	std::cout << tree;
	std::cout << std::flush;
	return 0;
}
