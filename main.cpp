#include "ForwardingTable.h"
#include <fstream>

#define SUCCESS true
#define FAILURE false

bool testIpAddress()
{
	try
	{
		IpAddress addr("1.2.3.4");
		cout << addr << endl;
		addr.applyMask(16);
		cout << addr << endl;
	}
	catch (runtime_error &e)
	{
		cout << e.what() << endl;
		return false;
	}
	return true;
}

bool testIpRange()
{
	try
	{
		IpRange range("128.153.64.0/18", 1);
		cout << range << endl;
	}
	catch (runtime_error &e)
	{
		cout << e.what() << endl;
		return false;
	}
	return true;
}

int main(int argc, const char* argv [])
{
	//testIpAddress();
	//testIpRange();

	if (argc < 3)
	{
		cout << "Not enough arguments." << endl;
		return -1;
	}

	
	ifstream in2(argv[2]);
	if (!in2)
	{
		cout << argv[2] << ": File not found." << endl;
		return -1;
	}

	try
	{
		ForwardingTable table1(argv[1]);
		ForwardingTable table2(argv[2]);
		cout << table1 << endl << table2 << endl;
	}
	catch (runtime_error &e)
	{
		cout << e.what() << endl;
	}
	
	return 0;
}