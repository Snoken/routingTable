#ifndef IPADDRESS_H
#define IPADDRESS_H
#include <string>
#include <stdint.h>
#include <iostream>
#include <sstream>
#include <bitset>
#include <stdexcept>
#include "helpers.h"

using namespace std;

class IpAddress
{
public:
	IpAddress(){ m_addr = 0; }
	IpAddress(string addr);
	IpAddress(uint32_t addr) : m_addr(addr) {}
	
	void setAddress();
	string getString() const;
	void applyMask(uint32_t mask);

	bool operator==(const IpAddress &other) const{ return m_addr == other.m_addr; }
	bool operator<= (const IpAddress &other) const{ return m_addr <= other.m_addr; }
	bool operator< (const IpAddress &other) const{ return m_addr < other.m_addr; }
	bool operator> (const IpAddress &other) const{ return m_addr > other.m_addr; }
	bool operator>= (const IpAddress &other) const{ return m_addr >= other.m_addr; }
	IpAddress operator+ (const IpAddress &other) const{ return IpAddress(m_addr + other.m_addr); }

	friend ostream& operator<<(ostream& stream, const IpAddress& obj);
private:
	uint32_t m_addr;
};

#endif