#include "../src/flat_set.cc"
#include <stdlib.h>

int main()
{
    Flat_set<int> int_set = Flat_set<int>();
    std::cout << int_set.empty() << std::endl;
    for (int i = 0; i < 10; i++)
        int_set.insert(rand() % 100);
    std::cout << int_set << std::endl;
    std::cout << int_set.empty() << " " << int_set.size() << std::endl;

    return 0;
}
