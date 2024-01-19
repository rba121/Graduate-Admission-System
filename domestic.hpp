#include<iostream>
#include "student.hpp"
using namespace std; //use namespace std
#include <string> //you will have to use string in C++


    class DomesticStudent : public Student
    {
        public:
            // default constructor
            DomesticStudent();
            //sets student details
            DomesticStudent(string first_name , string last_name, float Cgpa, int RE_score, int ID, string the_province);

            void set_province(string province);

            string get_province() const;

            friend ostream& operator <<(ostream& outs , const DomesticStudent& d_stu );
            friend bool compareDomesticAll( const DomesticStudent& s1, const DomesticStudent& s2);
            friend bool compareDomesticAscending (const DomesticStudent& s1, const DomesticStudent& s2);

        private:
            string Province;

    };


