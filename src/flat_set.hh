#ifndef FLAT_SET_HH
# define FLAT_SET_HH

# include <vector>
# include <iostream>

template <class T>
class Flat_set
{
    public:
        typedef T data_type;

        Flat_set();
        ~Flat_set();

        bool insert(T elt);
        bool erase(T elt);
        void clear();

        size_t size();
        size_t max_size();
        bool empty();

        size_t count(T elt);
        bool find(T elt);

        typedef typename std::vector<data_type>::iterator it;
        it begin() { return cnt.begin(); }
        it end() { return cnt.end(); }
        it rbegin() { return cnt.rbegin(); }
        it rend() { return cnt.rend(); }


        void print(std::ostream& os);

    private:
        bool contain(T elt);
        void insert_in_place(T elt);
        std::vector<T> cnt;
};

template <class T>
std::ostream& operator<<(std::ostream& os, Flat_set<T> set);

# include "flat_set.hxx"

#endif /* !FLAT_SET_HH */
