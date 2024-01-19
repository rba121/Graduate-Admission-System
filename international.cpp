/*
 * Filename: international.cpp
 *
 * Description: 
 *
 * Author: Riyan Roy & Rohit Bhardwaj
 * Student ID: 301472766(Roy) & 301450331(Bhardawaj)
 * Date: 2nd June 2022
 * 
 */

//international.cpp to implement your classes
#include "international.hpp"
using namespace std; //use namespace std
#include <string>


    InternationalStudent::InternationalStudent() : Student(), Country("Not data yet") 
    {
        //deliberately empty
    }

    InternationalStudent::InternationalStudent(string first_name , string last_name, float Cgpa, int RE_score, int ID, string the_country, ToeflScore toefl)
    : Student(first_name , last_name, Cgpa, RE_score, ID), Country(the_country) , toefl(toefl)
    {
        
    }

    void InternationalStudent::set_country(string country)
    {
        Country = country;
    }

    
    string InternationalStudent::get_country() const
    {
        return Country;
    }

    void InternationalStudent::set_toefl(ToeflScore tf)
    {
        toefl=tf;
    }
    ToeflScore InternationalStudent::get_toefl()
    {
       return toefl;
    }



    
    ostream& operator <<(ostream& outs , const InternationalStudent& i_stu )
    {
      outs << i_stu.get_FN()<<"\t"<< i_stu.get_LN()<<"\t"<< i_stu.get_country() <<"\t"<< i_stu.get_cgpa()<<"\t"
      <<i_stu.get_re()<<"\t"<<i_stu.toefl.get_rd_scr()<<"\t"<<i_stu.toefl.get_lst_scr()
      <<"\t"<<i_stu.toefl.get_spk_scr()<<"\t"<<i_stu.toefl.get_wrt_scr()<<endl;
      return outs;
    }
 
    bool compareInternationalAll( const InternationalStudent& s1, const InternationalStudent& s2)
    {
        return (s1.get_re() < s2.get_re()) ||
           ((s1.get_re()== s2.get_re()) && s1.get_cgpa()< s2.get_cgpa()) ||
           ((s1.get_re()== s2.get_re()) && s1.get_cgpa()== s2.get_cgpa()) &&
           (s1.get_country().compare(s2.get_country())) >0;

    }

    bool compareInternationalAscending( const InternationalStudent& s1, const InternationalStudent& s2)
    {
        return (s1.get_re() > s2.get_re()) ||
           ((s1.get_re()== s2.get_re()) && s1.get_cgpa()> s2.get_cgpa()) ||
           ((s1.get_re()== s2.get_re()) && s1.get_cgpa()== s2.get_cgpa()) &&
           (s1.get_country().compare(s2.get_country())) >0;

    }





