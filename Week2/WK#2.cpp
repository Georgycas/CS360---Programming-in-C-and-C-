#include<iostream>
using namespace std;

class Std{
    public: 
        int id;
        float gpa;
        void setup(int i, float g){
            id=i; gpa=g;
        }
        void prt(){
            cout<<"id:"<<id<<"; "<<"gpa:"<<gpa<<"\n";
        }  
};

int main(void){
    Std a;          //a.Std()
    cout<<a.id<<";"<<a.gpa<<"\n";
    a.prt();
    
    a.setup(12345, 3.5);
    a.prt();
    return 0;
}

#include<iostream>
using namespace std;

class Std{
    private: 
        int id;
        float gpa;
    public:
        void setup(int i, float g){
            if(i>0) id=i; 
            else cout<<"id should be greater than 0"<<"\n";
            if(gpa>0 && gpa<4.0) gpa=g;
            else cout<<"gpa is out of range"<<"\n";
        }
        void prt(){
            cout<<"id:"<<id<<"; "<<"gpa:"<<gpa<<"\n";
        }  
};

int main(void){
    Std a;          //a.Std(): construc empty
    a.prt();
    a.setup(12345, 5.5);
    a.prt();
    return 0;
}


#include<iostream>
using namespace std;

struct Std{         //w/o function
    int id;
    float gpa;      
};

int main(void){
    struct Std a;
    a.id = 12334;
    a.gpa = 3.5;
    cout<<"id is "<< a.id <<"; "<<"a.gpa is "<<a.gpa<<"\n";
    
    return 0;
}


#include<iostream>
using namespace std;

int main(void){
    int a=123;
    int *p;      //p points to int dType var
    p=&a;        // p and a share the same val
    //instatement not pointer declaration
    //*p is val
    cout<<"a="<<a<<"; "<<"*p's val="<<*p<<"\n";
    
    //Change a's val
    a=a+1;      //a=124
    cout<<"a="<<a<<"; "<<"*p's val="<<*p<<"\n";
    //change *p's val
    *p=*p+1;      //a=124
    cout<<"a="<<a<<"; "<<"*p's val="<<*p<<"\n";
    
    int b=456;
    p=&b;       //p=b's adr; *p = b
    cout<<"b="<<b<<"; "<<"*p's val="<<*p<<"\n";
    return 0;
}


#include<iostream>
using namespace std;

class Std{
    public: 
        int id;
        float gpa;
        void setup(int i, float g){
            if(i>0) id=i; 
            else cout<<"id should be greater than 0"<<"\n";
            if(gpa>0 && gpa<4.0) gpa=g;
            else cout<<"gpa is out of range"<<"\n";
        }
        void prt(){
            cout<<"id:"<<id<<"; "<<"gpa:"<<gpa<<"\n";
        }  
};

int main(void){
    Std a;          //a.Std(): construc empty
    Std *p;         //point to Std dType
    p=&a;           //p & a will share
    a.setup(12345, 3.5);
    cout<<a.id<<"; "<<a.gpa<<"\n";
    cout<<p->id<<"; "<<p->gpa<<"\n";
    
    p->setup(23456,3.8);
    cout<<a.id<<"; "<<a.gpa<<"\n";
    cout<<p->id<<"; "<<p->gpa<<"\n";
    return 0;
}
