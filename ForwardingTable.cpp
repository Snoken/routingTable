#include "ForwardingTable.h"

ForwardingTable::ForwardingTable(const char* infile)
{
	ifstream in(infile);
	if (!in)
	{
		string error = infile + string(": File not found.");
		throw runtime_error(error.c_str());
	}
	int lineNum = 1;
	while (in.good())
	{
		string line;
		getline(in, line);
		if (line.empty())
			continue;
		size_t loc = line.find('\t');
		if (loc == string::npos)
		{
			string error = string("Input format invalid in ") + 
				infile + string(":") + std::to_string((long double)lineNum);
			throw runtime_error(error.c_str());
		}
		try
		{
			IpRange rule(line.substr(0, loc), atoi(line.substr(loc + 1).c_str()));
			m_rules.push_back(rule);
		}
		catch (runtime_error &e)
		{
			throw e;
		}
		++lineNum;
	}
	m_rules.sort();
	//cout << *this << endl;
	//IpRange prev = *m_rules.begin();
	//list<IpRange>::iterator itr = ++(m_rules.begin());
	////doesn't work, maybe go through all with same next hop and find lowest of all that overlap
	//while (itr != m_rules.end())
	//{
	//	if (prev.combineRanges(*itr))
	//	{
	//		prev = *itr;
	//		m_rules.erase(itr++);
	//		continue;
	//	}
	//	if (itr != m_rules.end())
	//		prev = *itr++;
	//}
}

ostream& operator<<(ostream& stream, const ForwardingTable& obj)
{
	stream << "Rules:" << endl;
	for (list<IpRange>::const_iterator itr = obj.m_rules.begin(); itr != obj.m_rules.end(); ++itr)
		stream << "\t" << *itr << endl;
	return stream;
}