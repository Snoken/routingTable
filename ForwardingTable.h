#ifndef FORWARDINGTABLE_H
#define FORWARDINGTABLE_H
#include <list>
#include <fstream>
#include "IpRange.h"

class ForwardingTable
{
public:
	ForwardingTable();
	ForwardingTable(const char* infile);
	friend ostream& operator<<(ostream& stream, const ForwardingTable& obj);
private:
	list<IpRange> m_rules;
};

#endif