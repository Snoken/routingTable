#ifndef IPRANGE_H
#define IPRANGE_H

#include "IpAddress.h"
class IpRange
{
public:
	IpRange(){}
	IpRange(string range, int interface);
	IpRange(IpAddress start, IpAddress end, int interface) : 
		m_start(start), m_end(end), m_interface(interface) {}
	bool inInterface(IpAddress toCheck);

	bool inRange(IpAddress toTest){ return toTest >= m_start && toTest <= m_end; }
	bool combineRanges(IpRange toCombine);

	bool operator==(const IpRange &other) const
	{ 
		return m_start == other.m_start && m_end == other.m_end;
	}
	friend ostream& operator<<(ostream& stream, const IpRange& obj);

	bool operator<= (const IpRange &other) const{ return m_start <= other.m_start; }
	bool operator< (const IpRange &other) const{ return m_start < other.m_start; }
	bool operator>= (const IpRange &other) const{ return m_start >= other.m_start; }
	bool operator > (const IpRange &other) const{ return m_start > other.m_start; }

private:
	IpAddress m_start, m_end;
	int m_interface;
};

#endif