#include "flat_set.hh"

#include <string>
#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(flat_set)
{
    class_<Flat_set<std::string>>("Flat_set", init<>())
        .def("insert", &Flat_set<std::string>::insert)
        .def("erase", &Flat_set<std::string>::erase)
        .def("find", &Flat_set<std::string>::find)
        .def("size", &Flat_set<std::string>::size)
        .def("draw", &Flat_set<std::string>::draw);
}

int main()
{
}
