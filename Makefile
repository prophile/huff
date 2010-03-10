CXX=clang++
CXXFLAGS=-Os
LDFLAGS=

huff: huff.o BuildTree.o HuffmanTree.o
	$(CXX) $(LDFLAGS) -o $@ $^

huff.o: huff.cpp BuildTree.h HuffmanTree.h
	$(CXX) -c $(CXXFLAGS) -o $@ $<

BuildTree.o: BuildTree.cpp BuildTree.h HuffmanTree.h
	$(CXX) -c $(CXXFLAGS) -o $@ $<

HuffmanTree.o: HuffmanTree.cpp HuffmanTree.h
	$(CXX) -c $(CXXFLAGS) -o $@ $<

clean:
	rm -f huff *.o
