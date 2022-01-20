// #include "vector.hpp"
#include <vector>
#include <memory>
#include <math.h>
#include <iostream>

int main ()
{
  std::vector<int> myvector(6,6);
  std::vector<int> myvector2(9,9);
  std::cout << myvector2.size() << std::endl;

  myvector2 = myvector;

  std::cout << myvector2.size() << std::endl;

return (0);

  // std::vector<int>::reverse_iterator it;
  myvector.push_back (100);
  myvector.push_back (200);
  myvector.push_back (300);

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

  myvector.clear();
  myvector.push_back (1101);
  myvector.push_back (2202);

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

  return 0;
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