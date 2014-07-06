#ifndef FLAT_SET_HXX
# define FLAT_SET_HXX

template <class T>
Flat_set<T>::Flat_set()
{
    cnt = std::vector<T>();
}
template <class T>
Flat_set<T>::~Flat_set()
{
}

template <class T>
size_t Flat_set<T>::count(T elt)
{
    auto it = cnt.begin();
    for (; it != cnt.end() && *it < elt; it++)
        continue;
    if (it != cnt.end() && *it == elt)
        return 1;
    return 0;
}


template <class T>
bool Flat_set<T>::find(T elt)
{
    auto it = cnt.begin();
    for (; it != cnt.end() && *it < elt; it++)
        continue;
    if (it != cnt.end() && *it == elt)
        return true;
    return false;
}

template <class T>
bool Flat_set<T>::insert(T elt)
{
    auto it = cnt.begin();
    for (; it != cnt.end() && *it < elt; it++)
        continue;
    if (it == cnt.end())
        cnt.push_back(elt);
    else if (*it == elt)
        return false;
    else
        cnt.insert(it, elt);
    return true;
}

template <class T>
bool Flat_set<T>::erase(T elt)
{
    auto it = cnt.begin();
    for (; it != cnt.end() && *it < elt; it++)
        continue;
    if (it != cnt.end() && *it == elt)
        cnt.erase(it);
    else
        return false;
    return true;
}

template <class T>
void Flat_set<T>::clear()
{
    cnt.clear();
}

template <class T>
size_t Flat_set<T>::size()
{
    return cnt.size();
}

template <class T>
size_t Flat_set<T>::max_size()
{
    return cnt.max_size();
}

template <class T>
bool Flat_set<T>::empty()
{
    return cnt.empty();
}

template <class T>
typename std::vector<T>::iterator Flat_set<T>::begin()
{
    return cnt.begin();
}

template <class T>
typename std::vector<T>::iterator Flat_set<T>::end()
{
    return cnt.end();
}

template <class T>
typename std::vector<T>::iterator Flat_set<T>::rbegin()
{
    return cnt.rbegin();
}

template <class T>
typename std::vector<T>::iterator Flat_set<T>::rend()
{
    return cnt.rend();
}

template <class T>
void Flat_set<T>::print(std::ostream& os)
{
    for (auto e : cnt)
        os << e << " ";
}

template <class T>
std::ostream& operator<<(std::ostream& os, Flat_set<T> set)
{
    set.print(os);
    return os;
}

#endif /* !FLAT_SET_HXX */
