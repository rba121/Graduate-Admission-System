/*
 * Filename: student.hpp
 *
 * Description: 
 *
 * Author: Riyan Roy & Rohit Bhardwaj
 * Student ID: 301472766(Roy) & 301450331(Bhardawaj)
 * Date: 2nd June 2022
 * 
 */

//header file student.hpp to declare your classes

#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
using namespace std; //use namespace std
#include <string> //you will have to use string in C++


    class Student
    {

        public:
            // default constructor
            Student();
            //sets student details
            Student(string first_name , string last_name, float Cgpa, int RE_score, int ID); 

            void set_FN(string first);
            void set_LN(string last);
            void set_cgpa(float cgpa);
            void set_re(int re_score);
            void set_id(int id);

            string get_FN() const;
            string get_LN() const;
            float get_cgpa() const;
            int get_re() const;
            int get_id() const;
            virtual void printStudent();
            Student* next;


            friend bool compareCGPA( const Student& s1, const Student& s2);
            friend bool compareResearchScore( const Student& s1, const Student& s2);
            friend bool compareFirstName( const Student& s1, const Student& s2);
            friend bool compareLastName( const Student& s1, const Student& s2);


        private:
            string First_Name;
            string Last_Name;
            float CGPA;
            int Research_Score;
            int Application_ID;


    };












#endif