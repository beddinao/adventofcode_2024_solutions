#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

int main() {
	std::fstream input("input", std::ios::in);
   	if (!input) return 1;
	std::string buffer;
	int res(0), npos, num;

	while (std::getline(input, buffer)) {
		bool safe = true;
		std::vector<int> levels;
		while (true) {
			npos = buffer.find(' ');
			if (npos == std::string::npos)
				num = atoi(buffer.c_str());
			else	num = atoi(buffer.substr(0, npos).c_str());
			levels.push_back(num);
			std::cout << num << "::";
			if (npos == std::string::npos)
				break;
			buffer = buffer.substr(npos+1);	
		}
		int direction; 
		for (int i = 0; i < levels.size(); i++) {
			if (!i)
				direction = levels[1] - levels[0];
			else {
				int diff = levels[i] - levels[i-1];
				if (!diff || std::abs(diff) > 3 ||
					(diff < 0 && direction > 0) ||
					(diff > 0 && direction < 0)) {
					safe = false;
					break;
				}
			}
		}
		std::cout << (safe ? "safe" : "unsafe") << std::endl;
		res += safe;
	}
	input.close();

	
	std::cout << res << std::endl;
}
