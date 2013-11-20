all:
	mkdir -p linux
	g++ -std=c++0x $(wildcard *.cpp) -o linux/forwardingTable
	cp $(wildcard file*.txt) linux/
	
clean:
	rm -rf linux
	