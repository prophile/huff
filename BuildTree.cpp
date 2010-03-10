#include "BuildTree.h"

#include <queue>

namespace
{

struct TreeComparator
{
	bool operator() (HuffmanTree* lhs, HuffmanTree* rhs)
	{
		return lhs->Frequency() > rhs->Frequency();
	}
};

}

HuffmanTree BuildTree(const std::map<std::string, unsigned long>& frequencyTable)
{
	std::map<std::string, unsigned long>::const_iterator iter;
	std::priority_queue<HuffmanTree*, std::vector<HuffmanTree*>, TreeComparator> forest;
	// build forest
	for (iter = frequencyTable.begin();
	     iter != frequencyTable.end();
	     ++iter)
	{
		forest.push(new HuffmanTree(iter->second, iter->first));
	}
	// run huffman algorithm
	while (forest.size() > 1)
	{
		HuffmanTree* left = forest.top();
		forest.pop();
		HuffmanTree* right = forest.top();
		forest.pop();
		HuffmanTree* parent = new HuffmanTree(left, right);
		forest.push(parent);
	}
	return *(forest.top());
}
