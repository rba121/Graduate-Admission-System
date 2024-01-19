#include "domestic.hpp"

using namespace std;

  class DNode{              
    public:       
      DomesticStudent* dstu;
      DNode* next;
    public:
    DNode(DomesticStudent* ds){
      this->dstu= ds;
      next = NULL;
    }
    //DNode* next;
  };
  

class DomesticLinkList{
   private:
   DNode* head;
   DNode* tail;
   DNode* current;
 
   
  public:
   void domesticpush(DomesticStudent d);
   void domesticinsert(string fn , string ln , string prov , float cgpa , int re_scr );
   void domesticprint();

   void SearchbyID(int id);   
   void SearchbyGPA(float gpa);
   void SearchbyRS(int re);
   void SearchbyName(string fn,string ln);
   void deletestudent(string fn,string ln);
   void deletestudent();
   
   string case_Upper(string data);
   string case_insensitive(string data);
   DNode* getHead();

};



