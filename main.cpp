#include "vector.hpp"
#include <vector>
#include <memory>
#include <math.h>
#include <map>
#include <iostream>
#include <stdlib.h>

int main ()
{
  // int *ssa;
  // ssa = (int*)malloc(sizeof(int) * 555555555);
  
  // ssa[9999999] = 15;

  // std::cout << ssa[9999999]<< std::endl;

  // return (0);
         std::vector<int> a;
        std::map<int,int> m;        
        m.insert(std::pair<int, int>(10,6));
        m.insert(std::pair<int, int>(8,2));
        m.insert(std::pair<int, int>(12,4));
        m.insert(std::pair<int, int>(11,7));
        m.insert(std::pair<int, int>(14,7));
        std::map<int,int>::iterator it = m.begin();
        for (; it != m.end(); it++)
        {
          std::cout << it->first << " " << it->second << std::endl;
        }
        return (0);
        std::string str, ft_str;
        /*
         * var to store the size and the capacity
         */
        ft::vector<std::string>::size_type s, ft_s;
        ft::vector<std::string>::size_type c, ft_c;
        /*
         * bool to store the comparison
         */
        bool cond;
std::vector<std::string> v1(300, "string");
            std::vector<std::string> v;
            ft::vector<std::string> ft_v;
            v.insert(v.begin(), v1.begin(), v1.end());
            // ft_v.insert(ft_v.begin(), v1.begin(), v1.end());
            // ft_v.begin()->length();

            // s = v.size();
            // ft_s = ft_v.size();
            // c = v.capacity();
            // ft_c = ft_v.capacity();
            // for (size_t i = 0; i < v.size(); ++i)
            //     str += v[i];
            // for (size_t i = 0; i < ft_v.size(); ++i)
            //     ft_str += ft_v[i];
            //cond = ((str == ft_str) && (s == ft_s) && (c == ft_c));


  // myvector.clear();
  // std::cout << myvector.size() << std::endl;
  // std::cout << myvector.capacity() << std::endl;
  // std::cout << myvector[2] << std::endl;

  // myvector = myvector;

  // std::cout << myvector.capacity() << std::endl;

return (0);

  // std::vector<int>::reverse_iterator it;
  // myvector.push_back (100);
  // myvector.push_back (200);
  // myvector.push_back (300);

  // std::cout << "myvector contains:";
  // for (unsigned i=0; i<myvector.size(); i++)
  //   std::cout << ' ' << myvector[i];
  // std::cout << '\n';

  // myvector.clear();
  // myvector.push_back (1101);
  // myvector.push_back (2202);

  // std::cout << "myvector contains:";
  // for (unsigned i=0; i<myvector.size(); i++)
  //   std::cout << ' ' << myvector[i];
  // std::cout << '\n';

  // return 0;
}






























































// int main ()
// {
//     std::vector<int> a1(5, 55);
//     // vector<int> b(5, 15);
//     // vector<int>::iterator it2 = b.begin();
//     a1.resize(12, 800);
//     std::vector<int>::iterator it1 =  a1.begin();
//     *it1 = 600000;
// //      bool d = it < it2;
// // cout << d << endl;
//     std::cout << "size of vector is : " << a1.size() << std::endl;
//     for (size_t i = 0; i < a1.size(); i++)
//     {
//         std::cout << it1[i] << std::endl;
//     }
// std::cout << "\n************ my vec *********\n" << std::endl;

//         vector<int> a2(5, 55);
//     // vector<int> b(5, 15);
//     // vector<int>::iterator it2 = b.begin();
//     a2.resize(12, 800);
//     vector<int>::iterator it2 =  a2.begin();
//     *it2 = 600000;
// //      bool d = it < it2;
// // cout << d << endl;
//     std::cout << "size of vector is : " << a2.size() << std::endl;
//     for (size_t i = 0; i < a2.size(); i++)
//     {
//         std::cout << it2[i] << std::endl;
//     }
    
//     // std::cout << it[16] << std::endl;
//     // std::cout << it[17] << std::endl;
//     //  if (*it > *it2)
//     //  {
//     //     std::cout << "hello" << std::endl;
//     //  }
//     // std::vector<int> b(5 , 15); 
//     // int b;
// // std::cout << w.max_size() << std::endl;
// // std::cout << *it++ << std::endl;
// // std::cout << *it << std::endl;
// // std::cout << *it2 << std::endl;

// // std::cout << a.max_size() << std::endl;
// // std::cout << b.max_size() << std::endl;
// // a.ptr[4] = 20;
// // b[4] = 20;
// // b[3] = 19;
// // b[2] = 18;
// // b[1] = 17;
// // b[0] = 16;
// //std::vector<int>::reverse_iterator it = b.rbegin();
// // for (size_t i = 5; i < 5; i++)
// // {
//     // std::cout << *(++a.rend()) << std::endl;
//     // std::cout << *(b.rend() - 1) << std::endl;
//     /* code */
// // }


//         // a.push_back(2);
// // 
//     // for (int i = 0; i < 10; i++)
//     // {
//         //if( *a.begin() !=  a.end())
//         //    std::cout << a.end();
//         // it++;
//         // std::cout << *it << std::endl;
//         // it++;
 
//     // }
// //         std::cout << a.size() << std::endl;
// //         std::cout << a.capacity() << std::endl;
// //  it = a.begin();
// //             for (int i = 0; i < 10; i++)
// //     {
// //         std::cout << *it << std::endl;
// //         // a.push_back(2);
// //         it++;
// //         //std::cout << *a.end() << std::endl;
 
// //     }
//     return (0);
// }