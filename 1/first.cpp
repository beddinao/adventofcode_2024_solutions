#include <iostream>
#include <fstream>
#include <cmath>
#include <set>

int main() {
	std::fstream	input("input", std::ios::in);
   	if (!input)
        		return 1;
	std::string buffer;
	std::multiset<int> fset;
	std::multiset<int> sset;


	while (std::getline(input, buffer)) {
	      	int mpos = buffer.find(' ');
		fset.insert(atoi(buffer.substr(0, mpos).c_str()));
		sset.insert(atoi(buffer.substr(mpos, buffer.size()).c_str()));
	}
	input.close();

	int res(0);
	std::multiset<int>::iterator fite = fset.begin();
	std::multiset<int>::iterator site = sset.begin();
	
	for (; fite != fset.end() && site != sset.end(); fite++, site++)
        		res += std::abs(*fite - *site);

	std::cout << res << std::endl;	
}
