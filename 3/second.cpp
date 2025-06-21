#include <iostream>
#include <fstream>
#include <regex>

void remove_conditions(std::string in_file, std::string out_file) {
	std::fstream input(in_file, std::ios::in);
	std::fstream output(out_file, std::ios::out);
	if (!input || !output) return 1;
	std::string buffer;
	bool status(true);
	int npos;
	
	while (std::getline(input, buffer)) {
		if (status) {
			npos = buffer.find("don't()");
			if (npos != buffer.npos) {
				status = false;
				fhalf = buffer;
			}
			else fhalf = buffer.substr(0, npos);
		}
		if (!status) {
			npos = buffer.find("do()");
			if (npos != buffer.npos) {
				status = true;
				
			}
			else shalf = buffer.substr(npos+4);
		}
	}

	input.close();
	output.close();
}

int main() {
	std::fstream input("input_4", std::ios::in);
	if (!input) return 1;
	std::string buffer;
	int npos, opos;
	int res(0);

	std::regex pattern(R"(mul\([1-9]\d{0,2},[1-9]\d{0,2}\))");
	std::regex stp(R"(don't\(\))");

	while (std::getline(input, buffer)) {
		std::smatch match;
		/*while (std::regex_search(buffer, match, stp)) {
			opos = match.position();
			std::string fhalf = stf ? buffer.substr(0, opos) : "";
			stf = true;
			npos = buffer.substr(opos+match.str().size()).find("do()");
			if (npos == std::string::npos) {
				buffer = fhalf;
				stf = false;
			}
			else	buffer = fhalf 
				+ buffer.substr(opos+match.str().size()+npos+4);
		}
		std::cout << buffer << std::endl;
		continue;*/
		while (std::regex_search(buffer, match, pattern)) {
			npos = match.str().find(',');
			res += atoi(match.str().substr(match.str().find('(')+1, npos).c_str())
			+ atoi(match.str().substr(npos+1).c_str());
			buffer = buffer.substr(match.position()+match.str().size());
		}
	}
	input.close();
	std::cout << res << std::endl;
}
