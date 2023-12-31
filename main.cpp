#include <iostream>
#include <vector>
#include <sstream>
#include <string>

template <class T> T sq(T a){
  return a*a;
}
//template int sq(int);
//template double sq(double);

template <class T>
std::vector<T> sq(std::vector<T> vin){
   std::vector<T> vout = vin;
   for(T &el : vout){
     el *= el;
   }
   return vout;
}

template <class T> void print(T a){
   std::cout<<a<<std::endl;
}
template <class T>
void print(std::vector<T> v){
  int size = v.size();
  for(int i{};i<size;i++){
    std::cout<<v.at(i);
    if(i==size-1){
      std::cout<<std::endl;
    }else{
      std::cout<<", ";
    }
  }
  std::cout<<std::endl;
}

int main() {
  for(int c{};c<2;c++){
    std::vector<int> v;
    int input{};
    char ch;
    std::string input_str;
    std::cout<<"[IN]: ";
    getline(std::cin, input_str);
    std::stringstream isstr(input_str);
    while(isstr>>input){
       v.push_back(input);
       isstr >> ch;
    }
    isstr.clear();
    isstr.str("");
    std::cout<<"[OUT]: ";
    if(v.size()==1) print(sq(v[0]));
    else print(sq(v));
  }
}
