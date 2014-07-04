#include "../src/flat_set.cc"

int main()
{
    Flat_set<int> int_set = Flat_set<int>();
    int_set.insert(2);
    std::cout << int_set << std::endl;

    return 0;
}
