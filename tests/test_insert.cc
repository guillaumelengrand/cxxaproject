#include "../src/flat_set.hh"
#include <stdlib.h>

int main()
{
    Flat_set<int> int_set = Flat_set<int>();
    std::cout << "is empty ? " << int_set.empty() << std::endl;
    int_set.insert(10);
    for (int i = 0; i < 10; i++)
        int_set.insert(rand() % 100);
    std::cout << int_set << std::endl;
    std::cout << "erase 77: " << int_set.erase(77) << std::endl;
    std::cout << int_set << std::endl;
    std::cout << "is empty ? " << int_set.empty() << std::endl <<
            "size: " << int_set.size() <<std::endl <<
            "max_size: " << int_set.max_size() << std::endl;
    std::cout << int_set.find(10) << " " << int_set.count(50) << std::endl;
    std::cout << "first element: " << *(int_set.begin()) << " End elt: "
              << *(int_set.end() - 1)  << std::endl;
    int_set.clear();
    std::cout << "after Clean: " << int_set << " Size: " << int_set.size() << std::endl;

    return 0;
}
