//
//  main.cpp
//  Class Equ Solver
//
//  Created by Batuhan Aydın on 1.01.2019.
//  Copyright © 2019 i.Batuhan Aydın. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
#define Size 100 // max prime number
using namespace  std;

void delete_unwanted(string *);
int is_number(char ch);
int howmanyx(string);

class equsolver{
private:
    string equ;
    int nums[Size] = {0};
    int x;
    int result;
public:
    equsolver(string A = "1*x*x*x*x + 1*x*x*x + 1*x*x + 1*x + 1",int a = 0){
        x = a;
        equ = A;
        // Activate this part if all first numbers not set 0
        //for(int i = 0;i<Size;i++)
        //    nums[i] = 0;
        delete_unwanted(&equ);
        find_nums();
        Solve();
    }
    ~equsolver(){}
    
    void Solve(){
        result = 0;
        for(int i = 0;i<Size;i++){
            result = result + (nums[i] * pow(x,i));
        }
        print_result();
    }
    
    void print_result()
    {
        cout << endl;
        //for(int i = 0;i<Size;i++)
            //cout << nums[i] << " " ;
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
                        nums[howmanyx(equ.substr(j,equ.size()-j))] =temp;
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
    if((ch >= '0'  && ch <= '9') || ch =='-' || ch == '+')
        return 1;
    else
        return 0;
}

void delete_unwanted(string *a){
    for(int i = 0;i<(*a).size();i++){
        if((*a).at(i) == ' ' || a->at(i) == '*'){
            (*a).erase(i,1);
            i--;
        }
    }
}

int howmanyx(string a){
    int i;
    for(i = 0;i<a.size();i++){
        if(a.at(i) != 'x')
            break;
    }
    //cout <<endl << i << " adet x" <<endl;
    return i;
}
