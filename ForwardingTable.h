#ifndef FORWARDINGTABLE_H
#define FORWARDINGTABLE_H
#include <list>
#include <map>
#include <fstream>
#include "IpRange.h"

class ForwardingTable
{
public:
	ForwardingTable();
	ForwardingTable(const char* infile);
	void compare(ForwardingTable f);
	friend ostream& operator<<(ostream& stream, const ForwardingTable& obj);
private:
	map<int, list<IpRange>> m_rules;
};

#endif
