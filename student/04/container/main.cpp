#include <cstdlib>
#include <iostream>
#include <vector>


void read_integers(std::vector< int >& ints, int count)
{

    int new_integer = 0;
    for(int i = 0; i < count; ++i)
    {
        std::cin >> new_integer;
        ints.push_back(new_integer);
     }
}
bool same_values(std::vector< int >& ints)
{
    bool onko = false;
    if(ints.size()<=1)
    {
        return true;
    }
    for (unsigned long i= 0; i < ints.size()-1;++i )
        if(ints.at(i) == ints.at(i+1))
        {
            onko = true;
        }
    else if(ints.at(i) != ints.at(i+1) )
        {
            onko = false;
            break;
        }

     {
      return onko;
}
}







bool is_ordered_non_strict_ascending(std::vector< int >& ints)
{
    if(ints.size()<=1)
    {
        return true;
    }
    bool onko_sama_tai_isompi = false;
    for (unsigned long i= 0; i < ints.size()-1;++i )
    {

        if(ints.at(i) < ints.at(i+1))
        {
            onko_sama_tai_isompi = true;
        }
        else if (ints.at(i) == ints.at(i+1))
        {
            onko_sama_tai_isompi = true;
        }
        else
        {
            onko_sama_tai_isompi = false;
            break;
        }
    }

    return onko_sama_tai_isompi;
}

bool is_arithmetic_series(std::vector< int >& ints)
{
    if(ints.size()<=1)
    {
        return true;
    }
    bool aritmeettinen = false;
    int valimatka = ints.at(0)-ints.at(1);
    for (unsigned long i= 0; i < ints.size()-1;++i )
    {
        if(ints.at(i)-ints.at(i+1) == valimatka)
        {
            aritmeettinen = true;
        }
        else
        {
            aritmeettinen = false;
            break;
        }

    }
    return aritmeettinen;



}

bool is_geometric_series(std::vector< int >& ints)
{
    if(ints.size()<=1)
    {
        return true;
    }

  bool  geometrinen = false;
  for (unsigned long i= 0; i < ints.size()-1;++i )
  {
      if(ints.at(i)== 0)
      {
          geometrinen= false;
          break;

      }
      int suhde = ints.at(1)/ints.at(0);
      if(ints.at(i)*suhde== ints.at(i+1))
      {
          geometrinen = true;
      }
      else
      {
          geometrinen = false;
          break;
      }
  }
  return geometrinen;
}



int main()
{
    std::cout << "How many integers are there? ";
    int how_many = 0;
    std::cin >> how_many;

    std::cout << "Enter the integers: ";
    std::vector<int> integers;
    read_integers(integers, how_many);


    if(same_values(integers))
        std::cout << "All the integers are the same" << std::endl;
    else
        std::cout << "All the integers are not the same" << std::endl;

    if(is_ordered_non_strict_ascending(integers))
        std::cout << "The integers are in a non-strict ascending order" << std::endl;
    else
        std::cout << "The integers are not in a non-strict ascending order" << std::endl;

    if(is_arithmetic_series(integers))
        std::cout << "The integers form an arithmetic series" << std::endl;
    else
        std::cout << "The integers do not form an arithmetic series" << std::endl;

    if(is_geometric_series(integers))
        std::cout << "The integers form a geometric series" << std::endl;
    else
        std::cout << "The integers do not form a geometric series" << std::endl;

    return EXIT_SUCCESS;
}
