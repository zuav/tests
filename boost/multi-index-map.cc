#include <string>
#include <iostream>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/member.hpp>

struct Elem {
    int ind_int;
    std::string ind_str;
    std::string value;
};

std::ostream& operator<<(std::ostream& os, Elem e)
{
    os << "'" << e.ind_int << ", " << e.ind_str << ", " << e.value;
}

typedef boost::multi_index::ordered_unique<boost::multi_index::member<Elem, int,&Elem::ind_int> > Int_i;
typedef boost::multi_index::ordered_unique<boost::multi_index::member<Elem, std::string,&Elem::ind_str> > String_i;

typedef boost::multi_index_container<Elem, boost::multi_index::indexed_by<Int_i, String_i> > Numbers_map;

typedef Numbers_map::nth_index<0>::type Elem_by_int;
typedef Numbers_map::nth_index<1>::type Elem_by_string;


int main()
{
    Elem elem[10] = {
        {0, "zero",  "element 0"},
        {1, "one",   "element 1"},
        {2, "two",   "element 2"},
        {3, "three", "element 3"},
        {4, "four",  "element 4"},
        {5, "five",  "element 5"},
        {6, "six",   "element 6"},
        {7, "seven", "element 7"},
        {8, "eight", "element 8"},
        {9, "nine",  "element 9"},
    };

    Numbers_map map;

    for (int i=9; i>=0; --i)
        map.insert(elem[i]);

    std::cout << "multi_map[5]       = '" << map.get<0>().find(1)->value << "'" << std::endl
              << "multi_map[\"seven\"] = '" << map.get<1>().find("seven")->value << "'" << std::endl
              << std::endl;

    std::cout << "map sorted by int: " << std::endl;

    const Elem_by_int& int_index = map.get<0>();
    std::copy(int_index.begin(), int_index.end(), std::ostream_iterator<Elem>(std::cout, "\n"));
    std::cout << std::endl;

    std::cout << "map sorted by string: " << std::endl;

    const Elem_by_string& str_index = map.get<1>();
    std::copy(str_index.begin(), str_index.end(), std::ostream_iterator<Elem>(std::cout, "\n"));
    std::cout << std::endl;

    Elem_by_int& remove_index = map.get<0>();
    typedef Elem_by_int::iterator IT;
    for (IT i=remove_index.begin(), iend=remove_index.end(); i!=iend; ) {
        IT tmp = i++;
        if ((tmp->ind_int % 2) == 0)
            remove_index.erase(tmp);
    }

    std::cout << "map with only odd elements (sorted by int): " << std::endl;

    const Elem_by_int& int_index2 = map.get<0>();
    std::copy(int_index2.begin(), int_index2.end(), std::ostream_iterator<Elem>(std::cout, "\n"));
    std::cout << std::endl;

    Elem_by_string& clear_index = map.get<1>();
    std::cout << "map size (sorted by string): " << clear_index.size() << std::endl;

    clear_index.clear();

    std::cout << "map size (sorted by string) after clear(): " << clear_index.size() << std::endl;


    const Elem_by_int& cleare_int_index = map.get<0>();
    std::cout << "map size (sorted by int) after clear(): " << cleare_int_index.size() << std::endl;

    std::cout << "map content after cleat() sorted by int: " << std::endl;
    std::copy(cleare_int_index.begin(), cleare_int_index.end(), std::ostream_iterator<Elem>(std::cout, "\n"));
    std::cout << std::endl;


    for (int i=9; i>=0; --i)
        map.insert(elem[i]);

    const Elem_by_int& index1 = map.get<0>();
    std::cout << "map size (sorted by int) after refilling: " << index1.size() << std::endl;

    map = Numbers_map();

    const Elem_by_int& index2 = map.get<0>();
    std::cout << "map size (sorted by int) after clearing by assignment: " << index2.size() << std::endl;

    return 0;
}
