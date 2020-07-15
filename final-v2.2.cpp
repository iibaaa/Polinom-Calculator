//
//  main.cpp
//  Polinom Random
//
//  Created by Batuhan Aydın on 5.01.2019.
//  Copyright © 2019 i.Batuhan Aydın. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int addchar(string *,char,char);
void delete_char(string *a,char b);
void find_parts(string *,string *,char);
int calculate_parts(string *, int,int);
int convert_num(string ,int);
int numofmult(string a);
int calculate_one_part(string a,int x);

int main()
{
    // Pol and X value
    string pol1 = "5*x*x*x + 3*x*0*x+5*0 +4";
    int x = 3;
    //
    
    cout << pol1  << " | x = "<< x<<endl;
    delete_char(&pol1, ' ');
    
    int numberofpart = addchar(&pol1, '+', '-');
    
    string parts[numberofpart];
    
    find_parts(&pol1,parts,'|');

    cout<<  "= "<< calculate_parts(parts, x,numberofpart) <<endl;
    
}

int calculate_parts(string *parts,int value_x,int num)
{
    int result = 0;
    for(int i = 0;i<num;i++)
        result += calculate_one_part(parts[i], value_x);
    
    return result;
}

int calculate_one_part(string a,int x)
{
    int result = 1;
    int b = numofmult(a);
    string nums[b];
    int numss[b];
    
    find_parts(&a, nums, '*');
        
    for(int i = 0;i<b;i++)
        numss[i] = convert_num(nums[i], x);
    
    for(int k = 0;k<b;k++)
        result *= numss[k];
    
    return result;
}

int numofmult(string a)
{
    int say = 0;
    for(int i = 0;i<a.size();i++)
    {
        if(a.at(i) == '*')
            say++;
    }
    return say-1;
}

int convert_num(string a,int x_value)
{
    if(a.at(0) == 'x')
        return x_value;
    else if(a.size() > 0)
        return stoi(a);
    else
        return 1;
}

void find_parts(string *a , string *b, char d)
{
    int num = 0;
    for(int i = 0 ;i<a->size();i++)
    {
        if(a->at(i) == d)
        {
            for(int j = i+1;j<a->size();j++)
            {
                if(a->at(j) == d)
                {
                    b[num] = a->substr(i+1,j-i-1);
                    num++;
                    i = j;
                }
            }
        }
    }
}

void delete_char(string *a,char b)
{
    for(int i = 0;i<a->size();i++)
        if(a->at(i) == b)
        {
            a->erase(i,1);
            i--;
        }
}


int addchar(string *a,char b,char c)
{
    string d = "*|*";
    int say = 0;
    a->insert(0,"|*");
    a->insert(a->size(),"*|");
    for(int i = 0;i<a->size();i++)
    {
        if(a->at(i) == b || a->at(i) == c)
        {
            a->insert(i,d);
            i+= d.size();
            say++;
        }
    }
    return say+1;
}

