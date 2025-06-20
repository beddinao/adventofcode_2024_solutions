#include <iostream>
#include <fstream>
#include <cmath>
#include <map>
#include <set>

int main() {
	std::fstream	input("input", std::ios::in);
   	if (!input)
        		return 1;
	std::string buffer;
	std::multiset<int> fset;
	std::multiset<int> sset;
	std::map<int, int> fmap;
	int snum;

	while (std::getline(input, buffer)) {
	      	int mpos = buffer.find(' ');
		fset.insert(atoi(buffer.substr(0, mpos).c_str()));
		snum = atoi(buffer.substr(mpos, buffer.size()).c_str());
		sset.insert(snum);
		fmap[snum] = sset.count(snum);
	}
	input.close();

	int res(0);
	std::multiset<int>::iterator fite = fset.begin();
	std::multiset<int>::iterator site = sset.begin();
	
	for (; fite != fset.end(); fite++)
        		res += *fite * fmap[*fite];

	std::cout << res << std::endl;	
}
