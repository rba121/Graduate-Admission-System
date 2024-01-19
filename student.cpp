/*
 * Filename: student.cpp
 *
 * Description: 
 *
 * Author: Riyan Roy & Rohit Bhardwaj
 * Student ID: 301472766(Roy) & 301450331(Bhardawaj)
 * Date: 2nd June 2022
 * 
 */

//student.cpp to implement your classes
#include<iostream>
#include "student.hpp"
using namespace std; //use namespace std
#include <string>
#include<iomanip>


    Student::Student()// defualt constructor
    : First_Name("No First name yet"), Last_Name("No Last name yet"), CGPA(0.00),Research_Score(0),Application_ID(0)
     {
        //deliberately empty
     }

    Student:: Student(string first_name , string last_name, float Cgpa, int RE_score, int ID) // constructor
    : First_Name(first_name),Last_Name(last_name),CGPA(Cgpa),Research_Score(RE_score),Application_ID(ID)
    {
        //deliberately empty
    }

    void Student::set_FN(string first) // sets first name
    {
        First_Name = first;
    }

    void Student::set_LN(string last) // sets last name
    {
        Last_Name = last;
    }

    void Student::set_cgpa(float cgpa) // sets cgpa
    {
        CGPA = cgpa;
    }

    void Student::set_re(int re_score) // sets research score
    {
        Research_Score = re_score;
    }

    void Student::set_id(int id) // sets application id
    {
        Application_ID = id;
    }

    string Student::get_FN() const
    {
        return First_Name;
    }

    string Student::get_LN() const
    {
        return Last_Name;
    }

    float Student::get_cgpa() const
    {
        return CGPA;
    }

    int Student::get_re() const
    {
        return Research_Score;
    }

    int Student::get_id() const
    {
        return Application_ID;
    }

    bool compareCGPA( const Student& s1, const Student& s2)
    {
            return (s1.CGPA < s2.CGPA);
    }

    bool compareResearchScore( const Student& s1, const Student& s2)
    {
            return (s1.Research_Score < s2.Research_Score);
    }

 bool compareFirstName( const Student& s1, const Student& s2)
    {
       int result =s1.First_Name.compare(s2.First_Name);
        if(result ==0){
            return s1.First_Name.compare(s2.First_Name) > 0;
        }
        else{
            return result >0;
        }
   }
 bool compareLastName( const Student& s1, const Student& s2)
    {
        int result =s1.Last_Name.compare(s2.Last_Name);
        if(result ==0){
            return s1.Last_Name.compare(s2.Last_Name) > 0;
        }
        else{
            return result >0;
        }
    }

    void Student::printStudent() 
    {
    cout<<"\n";
    cout << First_Name << "\t" << Last_Name << setw(20 - First_Name.size() - Last_Name.size()) ;
    cout<< Research_Score << "\t"<<setw(10 - (Research_Score)) << CGPA << setw(15 -(CGPA));
    cout<<"\n";
    }


