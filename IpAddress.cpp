#include "IpAddress.h"

IpAddress::IpAddress(string addr){
	stringstream stream(addr);
	m_addr = 0;
	for (uint8_t i = 1; i <= 4; ++i)
	{
		uint32_t currOct = 0;
		streamsize avail = stream.rdbuf()->in_avail();
		stream >> currOct;
		if (avail == stream.rdbuf()->in_avail())
			throw runtime_error("Invalid IP Format");
		currOct <<= 8 * (4-i);
		m_addr += currOct;
		stream.get();
	}
}

string IpAddress::getString() const
{
	string addr;
	for (uint8_t i = 1; i <= 4; ++i)
	{
		uint8_t oct = m_addr >> 8 * (4 - i);
		#ifdef WIN32
		//This is to clear an error on VS2010, not an issue in VS2012
		addr.append(helpers::to_string((long double)oct));
		#else
		addr.append(helpers::to_string(oct));
		#endif
		if (i != 4)
			addr.append(".");
	}
	return addr;
}

void IpAddress::applyMask(uint32_t mask) 
{ 
	mask = (INT32_MAX << (32-mask));
	m_addr = m_addr & mask;  
}

ostream& operator<<(ostream& stream, const IpAddress& obj)
{
	stream << obj.getString();
	return stream;
}
