#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/* immigrant.cpp
 *
 * An advice list posted on the Internet in order to shame you
 * or make you feel good depending, on which side your on.
 * I, on the other hand, just like to screw things around. :-)
 *
 * Marc St-Jacques <marc@geekchef.com>
 *
 * Read file COPYING before usage.
*/

int main(int argc, char **argv)
{
	bool shuffle = false;

	if (argc == 2)
	{	
		if (argv[1][0] == '-' && argv[1][1] == 's')
			shuffle = true;
		else
		{
			std::cerr << "Usage: immigrant    for the original list."
				<< std::endl
				<< "Usage: immigrant -s the the shuffled list."
				<< std::endl;

			return 1;
		}
	}
		
	std::srand(time(NULL));

	std::vector<std::string> items { "car", "vodka", "pizza", "kebab", "democracy", "coffee", "movies", "tea", "shirt", "oil", "electronics", "numbers", "letters" };
	std::vector<std::string> nations { "German", "Russian", "Italian", "Turkish", "Greek", "Brazilian", "American", "Tamil", "Indian", "Saudi Arabian", "Chinese",  "Arabic", "Latin" };

	if (shuffle)	
		std::random_shuffle( nations.begin(), nations.end() );

	for (size_t i=0; i < items.size(); i++)
	   std::cout << "Your " << items[i] << ((items[i][items[i].size()-1] == 's') ? " are " : " is ") << nations[i] << "." << std::endl;

	std::cout << std::endl << "And you complain that your neighbor is an immigrant?" << std::endl
		<< std::endl
		<< "Pull yourself together."
		<< std::endl;

	return 0;
}
