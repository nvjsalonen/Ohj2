#include <iostream>
#include <random>
#include <string>

using namespace std;
bool jatketaanko();

void produce_random_numbers(unsigned int lower, unsigned int upper)
{
int seed;
cout<< "Enter a seed value: ";
cin>>seed;
default_random_engine gen(seed);
uniform_int_distribution<int> distr(lower, upper);

cout<<endl;
cout <<"Your drawn random number is "<<distr(gen) <<endl;


while((jatketaanko()) == true)
{
    cout<< endl;
    cout <<"Your drawn random number is "<<distr(gen) <<endl;
}
}
bool jatketaanko()
{
    char jatko;
    cout <<"Press q to quit or any other key to continue: ";
    cin>>jatko;
    if (jatko != 'q')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    unsigned int lower_bound, upper_bound;
    cout << "Enter a lower bound: ";
    cin >> lower_bound;
    cout << "Enter an upper bound: ";
    cin >> upper_bound;

    if(lower_bound >= upper_bound)
    {
        cout << "The upper bound must be strictly greater than the lower bound"
             << endl;
        return EXIT_FAILURE;
    }

    produce_random_numbers(lower_bound, upper_bound);

    return EXIT_SUCCESS;
}
