#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

void print_vec(std::vector<int> &levels) {
	std::vector<int>::iterator it = levels.begin();
	for (; it != levels.end(); it++)
		std::cout << *it << ":";
	std::cout << std::endl;
}

bool check_vec(std::vector<int> &levels) {
        int direction = levels[1] - levels[0]; 
        for (int i = 0; i < levels.size()-1; i++) {
	      int diff = levels[i+1] - levels[i];
	      if (!diff || std::abs(diff) > 3 ||
			  (diff < 0 && direction > 0) ||
			  (diff > 0 && direction < 0)) {
		    return false;
	      }
        }
        return true;
}

int main() {
        std::fstream input("input", std::ios::in);
        if (!input) return 1;
        std::string buffer;
        int res(0), npos, num;

        while (std::getline(input, buffer)) {
	      bool safe = false;
	      std::vector<int> levels;
	      while (true) {
		    npos = buffer.find(' ');
		    if (npos == std::string::npos)
			  num = atoi(buffer.c_str());
		    else	num = atoi(buffer.substr(0, npos).c_str());
		    levels.push_back(num);
		    if (npos == std::string::npos)
			  break;
		    buffer = buffer.substr(npos+1);	
	      }
		

		for (int i = 0; i <= levels.size(); i++) {
			std::vector<int> slevels(levels.begin(), levels.end());
			if (i)
				slevels.erase(slevels.begin()+(i-1));
			std::cout << i << ", trying: ";
			print_vec(slevels);
			if (check_vec(slevels)) {
				safe = true;
				break;
			}
		}
	      

	
	      std::cout << (safe? "safe" : "unsafe") << std::endl;
	      res += safe;
        }
        input.close();


        std::cout << res << std::endl;
}
