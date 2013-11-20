#include "IpRange.h"

IpRange::IpRange(string range, int interface)
{
	size_t loc = range.find("/");
	if (loc == string::npos)
		throw exception("Invalid Range Format");
	/*cout << range.substr(0, loc) << endl;
	cout << range.substr(loc+1) << endl;*/
	try
	{
		m_start = IpAddress(range.substr(0, loc));
		stringstream stream(range.substr(loc + 1));
		uint32_t mask;
		stream >> mask;

		/*
		m_start.applyMask(mask);
		m_end = IpAddress(pow(2, mask)-1) + m_start;
		*/

		m_end = IpAddress(m_start);
		m_end.applyMask(mask);
		m_end = m_end + IpAddress((uint32_t)pow(2.0, (double)32-mask)-1);
	}
	catch (exception &e)
	{
		throw e;
	}
	m_interface = interface;

}

bool IpRange::combineRanges(IpRange toCombine)
{
	//need to combine if overlap and have same next hop
	if (m_interface != toCombine.m_interface)
		return false;
	//if current starts before toCombine and ends within toCombine
	if (m_start <= toCombine.m_start && toCombine.inRange(m_end))
	{
		m_end = toCombine.m_end;
		return true;
	}
	//if current ends after toCombine and starts within toCombine
	else if (m_end >= toCombine.m_end && toCombine.inRange(m_start))
	{
		m_start = toCombine.m_start;
		return true;
	}
	//if current is completely within toCombine
	else if (toCombine.inRange(m_start) && toCombine.inRange(m_start))
	{
		m_start = toCombine.m_start;
		m_end = toCombine.m_end;
		return true;
	}
	//if toCombine is completely within current
	else if (inRange(toCombine.m_start) && inRange(toCombine.m_start))
		return true;

	return false;
}

ostream& operator<<(ostream& stream, const IpRange& obj)
{
	stream << obj.m_start << " - " << obj.m_end << " Next hop: "
		<< obj.m_interface;
	return stream;
}