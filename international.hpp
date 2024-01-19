/*
 * Filename: international.hpp
 *
 * Description: 
 *
 * Author: Riyan Roy & Rohit Bhardwaj
 * Student ID: 301472766(Roy) & 301450331(Bhardawaj)
 * Date: 2nd June 2022
 * 
 */

//international.hpp to implement class
#include "student.hpp"
#include "toefl.hpp"
using namespace std; //use namespace std
#include <string>

// #include "student.hpp"
// using namespace std; //use namespace std
// #include <string> //you will have to use string in C++


    class InternationalStudent : public Student
    {
        public:
        InternationalStudent();
        InternationalStudent(string first_name , string last_name, float Cgpa, int RE_score, int ID, string the_country, ToeflScore toefl);

        void set_country(string country);
        string get_country() const;

        void set_toefl(ToeflScore toefl);
        ToeflScore get_toefl();

        friend ostream& operator <<(ostream& outs , const InternationalStudent& i_stu );
        friend bool compareInternationalAll( const InternationalStudent& s1, const InternationalStudent& s2);
        friend bool compareInternationalAscending( const InternationalStudent& s1, const InternationalStudent& s2);
        

        private:
        string Country;
        ToeflScore toefl;
    };




