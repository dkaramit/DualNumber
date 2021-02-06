#include<iostream>
#include<vector>

#include"DualNumber.hpp"

#ifndef LONG
#define LONG long
#endif

#define LD LONG double


using std::cout;
using std::endl;
using std::vector;




int main(){
    DualNumber<LD> x1(5); 
    DualNumber<LD> x2(5,2); 
    DualNumber<LD> x3(vector<LD>{0,0,0,0,0,1}); 
    DualNumber<LD> y1(x3); 
    DualNumber<LD> y2;




    y2=x1;
    y2=y2+x3;
    y2=y2+x2;
    y2=x1+y2;
    for(unsigned int i=0; i<y2.componentsLength();++i){
        cout<<y2.components(i)<<endl;
    }


    return 0;
}