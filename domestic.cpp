/*
 * Filename: domestic.cpp
 *
 * Description: 
 *
 * Author: Riyan Roy & Rohit Bhardwaj
 * Student ID: 301472766(Roy) & 301450331(Bhardawaj)
 * Date: 2nd June 2022
 * 
 */

//domestic.cpp to implement your classes
#include<iostream>
#include "domestic.hpp"
using namespace std; //use namespace std
#include <string>


    DomesticStudent::DomesticStudent() : Student(), Province("Not data yet")
    {
        //deliberately empty
    }

    DomesticStudent::DomesticStudent(string first_name , string last_name, float Cgpa, int RE_score, int ID, string the_province)
    : Student(first_name , last_name, Cgpa, RE_score, ID), Province(the_province)
    {
        //deliberately empty
    }

    void DomesticStudent::set_province(string province)
    {
        Province = province;
    }

    string DomesticStudent::get_province() const
    {
        return Province;
    }

    ostream& operator <<(ostream& outs , const DomesticStudent& d_stu )
    {
         outs << d_stu.get_FN() <<"\t"<< d_stu.get_LN()<<"\t"<<d_stu.get_province()<<"\t"<<d_stu.get_cgpa()<<"\t"<<d_stu.get_re()<<endl;
         return outs;
    }

     bool compareDomesticAll( const DomesticStudent& s1, const DomesticStudent& s2)
    {
        return (s1.get_re() < s2.get_re()) ||
           ((s1.get_re()== s2.get_re()) && s1.get_cgpa()< s2.get_cgpa()) ||
           ((s1.get_re()== s2.get_re()) && s1.get_cgpa()== s2.get_cgpa()) &&
           (s1.Province.compare(s2.Province)) >0;
    }

    bool compareDomesticAscending( const DomesticStudent& s1, const DomesticStudent& s2)
    {
        return (s1.get_re() > s2.get_re()) ||
           ((s1.get_re()== s2.get_re()) && s1.get_cgpa()> s2.get_cgpa()) ||
           ((s1.get_re()== s2.get_re()) && s1.get_cgpa()== s2.get_cgpa()) &&
           (s1.Province.compare(s2.Province)) >0;
    }




