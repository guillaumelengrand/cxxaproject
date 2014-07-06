#ifndef FLAT_SET_HH
# define FLAT_SET_HH

# include <vector>
# include <iostream>

template <class T>
class Flat_set
{
    public:
        Flat_set();
        ~Flat_set();
        bool insert(T elt);

        int size();
        bool empty();

        void print(std::ostream& os);

    private:
        bool contain(T elt);
        void insert_in_place(T elt);
        std::vector<T> cnt;
};

template <class T>
std::ostream& operator<<(std::ostream& os, Flat_set<T> set);

#endif /* !FLAT_SET_HH */
