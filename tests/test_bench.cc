#include "../src/flat_set.hh"
#include <stdlib.h>
#include <sys/time.h>
#include <set>
#include <vector>

#define MAX 200
#define MAXM 500

int main()
{
    struct timeval tbegin,tend;
    double texec=0.;

    Flat_set<int> int_set = Flat_set<int>();
    std::set<int> stl_set = std::set<int>();
    std::vector<int> elts = std::vector<int>();

    for (int i = 0; i < MAX; i++)
    {
        int rd = rand() % MAXM;
        if (int_set.insert(rd))
            elts.push_back(rd);
    }
    for (int i = 0; i < MAX; i++)
        stl_set.insert(rand() % MAXM);


    for (int i = 0; i < 3; i++)
    {
        int pos = rand() % elts.size();
        gettimeofday(&tbegin,NULL);
        for (int i = 0; i < 10000; i++)
            int_set.find(elts[pos]);

        gettimeofday(&tend,NULL);
        std::cout << "\033[1;34mFind " << elts[pos] << " :\033[0m" << std::endl;
        texec=((double)(1000*(tend.tv_sec-tbegin.tv_sec)+((tend.tv_usec-tbegin.tv_usec)/1000)))/1000.;
        texec = texec / MAX;
        std::cout << "\033[32mFlat_set \033[0mExecution time: \033[1;32m"
                  << texec << "\033[0m" << std::endl;

        gettimeofday(&tbegin,NULL);
        for (int i = 0; i < 10000; i++)
            stl_set.find(elts[pos]);

        gettimeofday(&tend,NULL);

        texec=((double)(1000*(tend.tv_sec-tbegin.tv_sec)+((tend.tv_usec-tbegin.tv_usec)/1000)))/1000.;
        texec = texec / MAX;
        std::cout << "\033[31mSTL\033[0m Execution time: \033[31m" << texec << "\033[0m" << std::endl;

    }

    return 0;
}
