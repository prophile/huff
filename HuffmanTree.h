#ifndef __HUFFMAN_TREE__
#define __HUFFMAN_TREE__

#include <string>
#include <ostream>

class HuffmanTree
{
private:
	unsigned long _frequency;
	bool _isLeaf;
	std::string _value;
	HuffmanTree* _left;
	HuffmanTree* _right;
public:
	HuffmanTree(HuffmanTree* left, HuffmanTree* right);
	HuffmanTree(unsigned long frequency, const std::string& value);
	HuffmanTree(const HuffmanTree& otherTree);
	~HuffmanTree();

	bool IsLeaf() const
		{ return _isLeaf; }
	std::string Value() const
		{ return _value; }
	unsigned long Frequency() const
		{ return _frequency; }
	const HuffmanTree& LeftSubtree() const
		{ return *_left; }
	const HuffmanTree& RightSubtree() const
		{ return *_right; }

	void Print(std::ostream& stream, const std::string& base = "") const;
};

static inline std::ostream& operator<<(std::ostream& stream, const HuffmanTree& tree)
	{ tree.Print(stream); return stream; }

#endif
