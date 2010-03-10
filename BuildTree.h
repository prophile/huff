#ifndef __BUILD_TREE__
#define __BUILD_TREE__

#include <map>
#include "HuffmanTree.h"

HuffmanTree BuildTree(const std::map<std::string, unsigned long>& frequencyTable);

#endif
