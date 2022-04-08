
   
#include <iostream>
#include <string>

	#include "map.hpp"
	#include "stack.hpp"
	#include "vector.hpp"


int main()
{
    // vector_tests
    ft::vector<int> myvector;
    for (int i=1; i<=5; i++) myvector.push_back(i);

    std::cout << "myvector contains:";
    for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
    std::cout << ' ' << *it;
    std::cout << '\n';

    // stack_test
    ft::vector<int> myvector1 (3,100);          
    ft::vector<int> myvector2 (2,200);        // vector with 2 elements 
    ft::stack<int> first;                    // empty stack
    ft::stack<int> second (myvector1);         // stack initialized to copy of deque 
    ft::stack<int,ft::vector<int> > third;  // empty stack using vector
    ft::stack<int,ft::vector<int> > fourth (myvector2);    
    std::cout << "size of first: " << first.size() << '\n';
    std::cout << "size of second: " << second.size() << '\n';
    std::cout << "size of third: " << third.size() << '\n';
    std::cout << "size of fourth: " << fourth.size() << '\n';

    for (int i=0; i<5; ++i) third.push(i);    
    std::cout << "Popping out elements...";
    while (!third.empty())
    {
       std::cout << ' ' << third.top();
       third.pop();
    }
    std::cout << '\n';

    // map_test
    ft::map<char,int> map;

    map['a']=10;
    map['b']=30;
    map['c']=50;
    map['d']=70;
    map.insert(ft::pair<char, int>('e', 200));
     for (ft::map<char, int>::iterator it = map.begin() ; it != map.end(); ++it)
    std::cout << ' ' << it->second;
    std::cout << '\n';
    map.erase('c');

    for (ft::map<char, int>::iterator it = map.begin() ; it != map.end(); ++it)
    std::cout << ' ' << it->second;
    std::cout << '\n';

    // map.clear();
    // std::cout << map.size() << std::endl;
    ft::map<char,int> map1 (map.begin(),map.end());

    // ft::map<char,int> third (second);

   // ft::map<char,int,classcomp> fourth;                 // class as Compare

   // bool(*fn_pt)(char,char) = fncomp;
  //  ft::map<char,int,bool(*)(char,char)> fifth (fn_pt);








    return 0;

}