//
//  main.cpp
//  Class Equ Solver
//
//  Created by Batuhan Aydın on 1.01.2019.
//  Copyright © 2019 i.Batuhan Aydın. All rights reserved.
//

#include <iostream>
#include <string>

using namespace  std;

int howmanyx(string);
void delete_unwanted(string *);
int is_number(char ch);

class equsolver{
private:
    string equ;
    int A,B,C,D,E,x;
    int result;
public:
    // A x x x x + B x x x + C x x + D x x + E
    equsolver(string A = "A*x*x*x*x + B*x*x*x + C*x*x + D*x + E",int a = 0){
        x = a;
        equ = A;
        delete_unwanted(&equ);
        find_nums();
        Solve();
    }
    ~equsolver(){}
    
    void Solve(){
        result = A*x*x*x*x + B*x*x*x + C*x*x + D*x + E;
        print_result();
    }
    
    void print_result()
    {
        cout << endl;
        //cout << "nums " <<endl<< A << endl << B <<endl<< C <<endl<<D <<endl<< E <<endl;
        cout << "= " << result;
        cout << endl;
    }
    
    void find_nums()
    {
        int temp;
        for(int i = 0;i<equ.size();i++)
        {
            if(is_number(equ.at(i)) == 1)
            {
                for(int j = i;j<equ.size();j++)
                {
                    if(equ.at(j) == 'x' || j == equ.size()-1)
                    {
                        if(equ.at(j-1) == '+')
                            temp = 1;
                        else if(equ.at(j-1) == '-')
                            temp = -1;
                        else
                            temp = stoi(equ.substr(i,j));
                        //cout <<"temp = " <<temp<<endl;
                        switch(howmanyx(equ.substr(j,4)))
                        {
                            case 0:
                                E = temp;
                                break;
                            case 1:
                                D = temp;
                                break;
                            case 2:
                                C = temp;
                                break;
                            case 3:
                                B = temp;
                                break;
                            case 4:
                                A = temp;
                                break;
                        }
                        i = j;
                        break;
                    }
                }
            }
        }
        
    }
};

int main()
{
    cout << "----- Polinom Solver -----"<<endl;
    cout << "created by ibaydin"<<endl;
    cout << "www.ibaydin.com"<<endl<<endl;
    string input,x;
    cout << "Enter the equation (-1 for exit) : ";
    getline(cin,input);
    while(input != "-1")
    {
        cout << "Enter x value : ";
        getline(cin,x);
        equsolver(input,stoi(x));
        cout << "Enter the equation (-1 for exit) : ";
        getline(cin,input);
    }
}

int is_number(char ch){
    if((ch >= '0'  && ch <= '9') || ch =='-')
        return 1;
    else
        return 0;
}

void delete_unwanted(string *a){
    for(int i = 0;i<(*a).size();i++){
        if(a->at(i) == ' ' || a->at(i) == '*'){
            (*a).erase(i,1);
            i--;
        }
    }
}

int howmanyx(string a){
    int x = 0;
    for(int i = 0;i<a.size();i++){
        if(a.at(i) == 'x')
            x++;
    }
    //cout <<endl << x << " adet x" <<endl;
    return x;
}
