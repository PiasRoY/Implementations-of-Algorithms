#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

template <typename T>  using orderedSet =
   tree<T, null_type, less<T>,
   rb_tree_tag, tree_order_statistics_node_update>;

orderedSet os;

/*
PBDS performs all the operations as performed by the set data structure in STL in log(n) complexity.
Two additional operations:
1) order_of_key: The number of items in a set that are strictly smaller than k; Complexity: O(LogN)
2) find_by_order: It returns an iterator to the ith largest element; Complexity: O(LogN)
*/

//syntax
os.insert(5);
os.insert(2);

cout << *os.find_by_order(0)<<endl; // 2
cout << *os.find_by_order(1)<<endl; // 5

cout << os.order_of_key(5) << endl;  // 1
cout << os.order_of_key(2) << endl;  // 0


