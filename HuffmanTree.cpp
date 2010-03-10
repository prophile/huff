#include "HuffmanTree.h"
#include <stdlib.h>

HuffmanTree::HuffmanTree(HuffmanTree* left, HuffmanTree* right)
: _frequency(left->_frequency + right->_frequency),
  _isLeaf(false),
  _value("")
{
	if (rand() % 2 == 0)
	{
		_left = left;
		_right = right;
	}
	else
	{
		_left = right;
		_right = left;
	}
}

HuffmanTree::HuffmanTree(unsigned long frequency, const std::string& value)
: _frequency(frequency),
  _isLeaf(true),
  _value(value),
  _left(0),
  _right(0)
{
}

HuffmanTree::HuffmanTree(const HuffmanTree& otherTree)
: _frequency(otherTree._frequency),
  _isLeaf(otherTree._isLeaf),
  _value(otherTree._value),
  _left(0),
  _right(0)
{
	if (otherTree._left)
		_left = new HuffmanTree(*(otherTree._left));
	else
		_left = NULL;
	if (otherTree._right)
		_right = new HuffmanTree(*(otherTree._right));
	else
		_left = NULL;
}

HuffmanTree::~HuffmanTree()
{
	delete _left;
	delete _right;
}

void HuffmanTree::Print(std::ostream& stream, const std::string& base) const
{
	if (IsLeaf())
	{
		stream << base << "\t" << Value() << "\n";
	}
	else
	{
		_left->Print(stream, base + "0");
		_right->Print(stream, base + "1");
	}
}
