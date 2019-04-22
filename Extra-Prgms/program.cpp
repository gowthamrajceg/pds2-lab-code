/*Word frequency count using maps in C++*/
#include<iostream>
#include<fstream>
#include<map>
using namespace std;
int main()
{
	string data;
	map<string,int> m;
	ifstream file;
	file.open("words.txt");
	while(!file.eof())
	{
		file >> data;
		m[data];
		for(auto it = m.begin();it!=m.end();it++)
		{
			if(data==it->first)
			{
				m[data]=++it->second;
			}
		}
	}
	for(auto it = m.begin();it!=m.end();it++)
	{
		cout << it->first << " "<<it->second<<endl;
	}
	return 0;
}
