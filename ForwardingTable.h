#ifndef FORWARDINGTABLE_H
#define FORWARDINGTABLE_H
#include <list>
#include <map>
#include <fstream>
#include <stdlib.h>
#include "IpRange.h"

class ForwardingTable
{
public:
	ForwardingTable();
	ForwardingTable(const char* infile);
	void compare(ForwardingTable f);
	friend ostream& operator<<(ostream& stream, const ForwardingTable& obj);
private:
	void combineAll();
	map<int, list<IpRange>> m_rules;
};

#endif
