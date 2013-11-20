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
			int nextHop = atoi(line.substr(loc + 1).c_str());
			map<int, list<IpRange>>::iterator mapLoc = m_rules.find(nextHop);
			if(mapLoc != m_rules.end())
				mapLoc->second.push_back(IpRange(line.substr(0, loc), nextHop));
			else
			{
				list<IpRange> newList;
				newList.push_back(IpRange(line.substr(0, loc), nextHop));
				m_rules.insert(make_pair(nextHop, newList));
			}
			
		}
		catch (runtime_error &e)
		{
			throw e;
		}
		++lineNum;
	}
	for(map<int, list<IpRange>>::iterator itr = m_rules.begin(); itr != m_rules.begin(); ++itr)
		itr->second.sort();
	cout << *this << endl;
}

void ForwardingTable::compare(ForwardingTable f){
	/*compare two*/

}

ostream& operator<<(ostream& stream, const ForwardingTable& obj)
{
	stream << "Rules:" << endl;
	for(map<int, list<IpRange>>::const_iterator mapItr = obj.m_rules.begin(); mapItr != obj.m_rules.end(); ++mapItr)
	{
		for (list<IpRange>::const_iterator itr = mapItr->second.begin(); itr != mapItr->second.end(); ++itr)
			stream << "\t" << *itr << endl;
	}
	return stream;
}