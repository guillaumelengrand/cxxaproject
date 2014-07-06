#include "../src/flat_set.cc"
#include <stdlib.h>

int main()
{
    Flat_set<int> int_set = Flat_set<int>();
    for (int i = 0; i < 10; i++)
        int_set.insert(rand() % 100);
    std::cout << int_set << std::endl;

    return 0;
}
