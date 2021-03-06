#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>  using orderedSet =
   tree<T, null_type, less<T>,
   rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>  using orderedMultiSet =
   tree<T, null_type, less_equal<T>,
   rb_tree_tag, tree_order_statistics_node_update>;

orderedSet <int> os;
orderedMultiSet <int> oms;

/*Alternative of unordered_map is gp_hash_table (x6 times faster):
	#include <ext/pb_ds/assoc_container.hpp>
	using namespace __gnu_pbds;
	gp_hash_table <int, int> table;

	//how to use 'pairs' as key:
	struct hash_pair {
		ll operator() (pair<ll, pll> x) const {
			return x.ff*63 + x.ss.ff*31 + x.ss.ss;
		}
	};
	gp_hash_table <pair<ll, pll>, ll, hash_pair> dp;
*/

/*
PBDS performs all the operations as performed by the set data structure in STL in log(n) complexity.
Two additional operations:
1) order_of_key: The number of items in a set that are strictly smaller than k; Complexity: O(LogN)
2) find_by_order: It returns an iterator to the ith largest element; Complexity: O(LogN)

After using less_equal instead of less for multiset, lower_bound works like upper_bound function
and upper_bound works like lower_bound.
*/

//syntax
int main()
{
	cout<<"Set:"<<endl;
	os.insert(2);
	os.insert(5);
	os.insert(2);

	cout<<os.size()<<endl;
	cout<<"0: "<<*os.find_by_order(0)<<endl; //2
	cout<<"1: "<<*os.find_by_order(1)<<endl; //5
	cout<<endl;
	cout<<"5: "<<os.order_of_key(5) << endl; //1
	cout<<"2: "<<os.order_of_key(2) << endl; //0


	cout<<"Multiset: "<<endl;
	oms.insert(2);
	oms.insert(5);
	oms.insert(2);

	cout<<oms.size()<<endl;
	cout<<"0: "<<*oms.find_by_order(0)<<endl; //2
	cout<<"1: "<<*oms.find_by_order(1)<<endl; //2
	cout<<"2: "<<*oms.find_by_order(2)<<endl; //5
	cout<<endl;
	cout <<"5: "<<oms.order_of_key(5) << endl;  //2
	cout <<"2: "<<oms.order_of_key(2) << endl;  //0

}

