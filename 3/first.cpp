#include <iostream>
#include <fstream>
#include <regex>


int main() {
	std::fstream input("input", std::ios::in);
	if (!input) return 1;
	std::string buffer;
	int res(0), npos;

	std::regex pattern(R"(mul\([1-9]\d{0,2},[1-9]\d{0,2}\))");

	while (std::getline(input, buffer)) {
		std::smatch match;
		while (std::regex_search(buffer, match, pattern)) {
			npos = match.str().find(',');
			res += atoi(match.str().substr(match.str().find('(')+1, npos).c_str())
			* atoi(match.str().substr(npos+1).c_str());
			buffer = buffer.substr(match.position()+match.str().size());
		}
	}
	input.close();
	std::cout << res << std::endl;
}
