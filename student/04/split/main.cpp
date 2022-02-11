#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string const &pilkottava, char const pilkkoja, bool halutaanko_valit = false)
{
     string sana = "";
     vector<string> jonot;
     for (const char c : pilkottava)
     {
         if(c==pilkkoja)
         {
             if(sana.empty() && halutaanko_valit)
             {
                 continue;
             }
             jonot.push_back(sana);
             sana.clear();
         }
         else
         {
             sana += c;
         }
      }
     jonot.push_back(sana);
return jonot;
}







// TODO: Implement split function here
// Do not change main function


int main()
{
    std::string line = "";
    std::cout << "Enter a string: ";
    getline(std::cin, line);
    std::cout << "Enter the separator character: ";
    char separator = getchar();

    std::vector< std::string > parts  = split(line, separator);
    std::cout << "Splitted string including empty parts: " << std::endl;
    for( auto part : parts ) {
        std::cout << part << std::endl;
    }

    std::vector< std::string > parts_no_empty  = split(line, separator, true);
    std::cout << "Splitted string ignoring empty parts: " << std::endl;
    for( auto part : parts_no_empty ) {
        std::cout << part << std::endl;
    }
}
