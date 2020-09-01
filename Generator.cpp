#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>

int main(int argc, char** argv)
{
	std::ifstream file("CSV/PlayersExport.csv");	

	if (!file)
	{
		std::cerr << "Something went wrong.\n";
		return 1;
	}

	std::vector<std::vector<std::string>> players;

	std::string line;
	unsigned int line_number = 0;

	while (std::getline(file, line))
	{
		players.push_back({});
		if (line_number != 0)
		{
			std::stringstream parse(line);
			std::string value;
		
			while (std::getline(parse, value, ','))
			{
				players.back().push_back(value);
			}
		}
		++line_number;
	}

	return 0;
}
