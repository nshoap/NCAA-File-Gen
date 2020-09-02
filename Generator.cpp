#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include "include/Player.h"

int main(int argc, char** argv)
{
	std::ifstream file("CSV/PlayersExport.csv");	

	if (!file)
	{
		std::cerr << "Something went wrong.\n";
		return 1;
	}

	std::vector<std::string> value_names;
	std::vector<std::vector<std::string>> players;
	std::string line;
	unsigned int line_number = 0;

	std::vector<std::shared_ptr<Player>> team_one_roster;

	// Load .csv
	while (std::getline(file, line))
	{
		players.push_back({});
		std::stringstream parse(line);
		std::string value;

		while (std::getline(parse, value, ','))
		{
			if (line_number != 0)
			{
				players.back().push_back(value);
			}
			else
			{
				value_names.push_back(value);
			}
		}

		if (line_number != 0)
		{
			auto plr = std::make_shared<Player>(value_names, &players.back());
			std::cout << (*plr)[0] << '\n';
			team_one_roster.push_back(plr);
		}

		++line_number;
	}

	std::cout << team_one_roster.size() << '\n';
	auto name_index = 0;

	for (int i = 0; i != value_names.size(); ++i)
	{
		if (value_names.at(i) == "PFNA")
		{
			name_index = i;
			break;
		}
	}

	std::cout << "Team one has a size of: " << team_one_roster.size() << '\n';
	std::cout << "Address we're looking for: " << &players.front() << std::endl;
	auto &player = (*team_one_roster.at(0));
	player.print();
	std::cout << player[name_index] << '\n';

	return 0;
}
