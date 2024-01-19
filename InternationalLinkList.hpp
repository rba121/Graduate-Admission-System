#include "international.hpp"

using namespace std;

class INode{
    public:
      InternationalStudent* istu;
      INode* next;
    public:
    INode(InternationalStudent* Is){
      this->istu= Is;
      next = NULL;
    }
  };

class InternationalLinkList{
   private:
   INode* head;
   INode* tail;
   INode* current;
   
  public:
   void Intpush(InternationalStudent Is);
   void Intprint();
   void internationalinsert(string fn , string ln , string country , float cgpa , int re_scr , 
   int read_scr , int listen_scr , int speak_scr , int write_scr );

   void SearchbyID(int id);
   void SearchbyGPA(float gpa);
   void SearchbyRS(int re);
   void SearchbyName(string fn,string ln);
   void deletestudent(string fn,string ln);
   void deletestudent();
   string case_insensitive(string data);
   INode* getHead();
};
