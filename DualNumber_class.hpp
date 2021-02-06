#ifndef Dual_class
#define Dual_class
#include<vector>

/* 
Let's build a Dual number class.
The idea is that any variable is represented by a vector, with the first element its value,
and the rest of the elements the 1st, 2nd, etc. derivatives.

Not sure, but we will see if it can be done this way...
*/

#define Dual_Template template<class LD>
#define Dual_Namespace DualNumber<class LD>


Dual_Template
class DualNumber{
    private:
    std::vector<LD> dualN;

    public:
    DualNumber(){}

    DualNumber(LD number){this->dualN.push_back(number);}//just a number
    DualNumber(LD realPart, LD dualPart){
        this->dualN.push_back(realPart);
        this->dualN.push_back(dualPart);
    }//just a number and the first derivative
    
    DualNumber(const std::vector<LD> &dualVector){
        this->dualN=dualVector;
    }// more complicated forms have to be passed as vectors


    DualNumber(const DualNumber &other){
        this->dualN=other.components(); 
    };

    DualNumber& operator=(const DualNumber &other)=default;

    DualNumber operator+(const DualNumber &other){

        std::vector<LD> tmpV=this->components();
        unsigned int len=this->componentsLength();

        if(len>other.componentsLength()){len=other.componentsLength();}
        if(len<other.componentsLength()){tmpV=other.components();}

        for (unsigned int i = 0; i < len; i++){
            tmpV[i]= this->components(i) + other.components(i);
        }
        


        return DualNumber(tmpV);
    }

    //Note: the const (after the parameter list) guarantees that this->dualN will not be modified
    // This allows us to pass it as (const DualNumber &other)
    std::vector<LD>  components() const {return this->dualN;}
    LD  components(unsigned int i) const {return this->dualN[i];}
    unsigned int  componentsLength() const {return this->dualN.size();}
    void resize(unsigned int N) {this->dualN.resize(N,0); }
};


#endif