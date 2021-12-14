#include "vector.hpp"
#include <vector>
#include <memory>
#include <math.h>


int main ()
{
    vector<int> a(5, 15);
    // a.ptr[0] = 1555.556;
    std::vector<int> b(5 , 15); 
    // int b;
// // std::cout << w.max_size() << std::endl;
// std::cout << a.max_size() << std::endl;
// std::cout << b.max_size() << std::endl;
a.ptr[4] = 20;
b[4] = 20;
b[3] = 19;
b[2] = 18;
b[1] = 17;
b[0] = 16;
std::vector<int>::reverse_iterator it = b.rbegin();
// for (size_t i = 5; i < 5; i++)
// {
    // std::cout << *(++a.rend()) << std::endl;
    std::cout << *(b.rend() - 1) << std::endl;
    /* code */
// }


        // a.push_back(2);
// 
    // for (int i = 0; i < 10; i++)
    // {
        //if( *a.begin() !=  a.end())
        //    std::cout << a.end();
        // it++;
        // std::cout << *it << std::endl;
        // it++;
 
    // }
//         std::cout << a.size() << std::endl;
//         std::cout << a.capacity() << std::endl;
//  it = a.begin();
//             for (int i = 0; i < 10; i++)
//     {
//         std::cout << *it << std::endl;
//         // a.push_back(2);
//         it++;
//         //std::cout << *a.end() << std::endl;
 
//     }
    return (0);
}