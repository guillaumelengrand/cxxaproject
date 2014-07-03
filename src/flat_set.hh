#ifndef FLAT_SET_HH
# define FLAT_SET_HH

# include <set>
# include <vector>

class Flat_set
{
    public:
        Flat_set();
        ~Flat_set();
    private:
        std::vector<int> container;
};

#endif /* !FLAT_SET_HH */
