#include "../src/flat_set.hh"
#include <stdlib.h>
#include <sys/time.h>
#include <vector>

#define MAX 10
#define MAXM 100

int main()
{
    std::cout << "\033[1;32mTest add elements in the flat_set:\033[0m" << std::endl;
    Flat_set<int> int_set = Flat_set<int>();
    std::vector<int> elts = std::vector<int>();
    for (int i = 0; i < MAX; i++)
    {
        int r = rand() % MAXM;
        std::cout << "\033[1;34mAdd \033[0m" << r << "\033[1;34m in the set => \033[0m";
        if (int_set.insert(r))
        {
            int_set.draw();
            elts.push_back(r);
        }
        else
            std::cout << "\033[1;31mElement already in the set.\033[0m" << std::endl;
    }

    std::cout << std::endl << "\033[1;32mTest size of the set: \033[0m" << int_set.size() << std::endl;

    std::cout << std::endl << "\033[1;32mTest max_size of the set: \033[0m"
              << int_set.max_size() << std::endl;


    std::cout << std::endl << "\033[1;32mTest find an element in the set: \033[0m" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        int pos = rand() % int_set.size();
        std::cout << "\033[1;34mFind \033[0m" << elts[pos] << " "
                << (int_set.find(elts[pos]) ? "\033[32mTrue\033[0m" : "\033[31mFalse\033[0m")
                << std::endl;
    }
    for (int i = 0; i < 4; i++)
    {
        int pos = rand() % int_set.size();
        std::cout << "\033[1;34mFind \033[0m" << elts[pos] % 50 << " "
                << (int_set.find(elts[pos] % 50) ? "\033[32mTrue\033[0m" : "\033[31mFalse\033[0m")
                << std::endl;
    }

    int_set.clear();
    std::cout << std::endl << "\033[1;32mTest clean of the set: \033[0m"
              << "Size = " << int_set.size()  << std::endl;

    return 0;
}
