#include <cstdlib> 
#include <iostream> 
  
using namespace std; 
  
template<typename T> 
struct __list_node 
{ 
     typedef void*    link_pointer; 
     //typedef __list_node<T>*    link_pointer;  
      
     link_pointer    prev; 
     link_pointer    next; 
     T        data; 

}; 
  
int main(int argc, char *argv[]) 
{ 
     __list_node<int>*    node1 = new __list_node<int>; 
     node1->data = 1; 
      
     __list_node<int>*    node2 = new __list_node<int>; 
     node2->data = 2; 
      
     node1->next = node2;    //如果使用typedef void*    link_pointer; 这里就出问题 
     node2->prev = node1;  
      
     cout<<node1->data<<endl; 
     cout<<node1->next->data<<endl; 
  
     return EXIT_SUCCESS; 
} 
