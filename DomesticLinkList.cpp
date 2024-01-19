 #include "DomesticLinkList.hpp"
#include <iomanip>
using namespace std;


   void DomesticLinkList::domesticpush(DomesticStudent d)
   {
    try
    {
      DomesticStudent* ds = new DomesticStudent(d.get_FN(),d.get_LN(),d.get_cgpa(),d.get_re(),d.get_id(),d.get_province());
        DNode* node = new DNode(ds); 
        if(head==NULL || compareDomesticAscending(*head->dstu,*node->dstu)){
           node->next= head; 
           head = node;  //move the head to point to new node
        } 
        else
        {
           current = head;
           //locating node before point of insertion
           while (current->next!=NULL && (compareDomesticAscending(*node->dstu,*current->next->dstu)))
            {
              current = current->next;  //finding current
            }
              node->next= current->next; //node --> new value
              current->next = node; //new node
        }
    }
    catch(bad_alloc)
    {
      cout<<"Ran Out Of Memory !!!!"; //check error
    }
      
        
   }

  void DomesticLinkList::domesticinsert(string fn , string ln , string prov , float cgpa , int re_scr )
  {
    string NL = "NL";
    string PE = "PE";
    string NS = "NS";
    string NB = "NB";
    string QC = "QC";
    string ON = "ON";
    string MB = "MB";
    string SK = "SK";
    string AB = "AB";
    string BC = "BC";
    string YT = "YT";
    string NT = "NT";
    string NU = "NU";
    if(re_scr>100 || re_scr<0)
    {
      cout<<"\nInvalid Entry!!!\n";
    }
    else if(cgpa>4.33 || cgpa<0)
    {
      cout<<"\nInvalid Entry!!!\n";
    }
    else if (!(prov == NL || prov  == PE || prov  == NS || prov  == NB || prov  == QC || prov  == ON || prov  == MB || prov  == SK || prov  == AB || prov  == BC || 
        prov  == YT || prov  == NT || prov  == NU) )
    {
      cout<<"\nInvalid Entry!!!\n";
    }
    else
    {
      DomesticStudent d;
      d.set_FN(fn);
      d.set_LN(ln);
      d.set_province(prov);
      d.set_cgpa(cgpa);
      d.set_re(re_scr);
      domesticpush(d);
    }
  }
 
   void DomesticLinkList::domesticprint()
   {
    DomesticLinkList var;
    cout<<left<<setw(10)<<" ";
    cout<<left<<setw(2)<<"======================================================================================"<<endl;
    cout<<left<<setw(10)<<" ";
    cout<<left<<setw(2)<<"|";
    // cout<<left<<setw(20)<<"Application ID";
    // cout<<left<<setw(2)<<"|";
    cout<<left<<setw(20)<<"First name";
    cout<<left<<setw(2)<<"|";
    cout<<left<<setw(20)<<"Last name";
    cout<<left<<setw(2)<<"|";
    cout<<left<<setw(10)<<"Province";
    cout<<left<<setw(2)<<"|";
    cout<<left<<setw(15)<<"Research Score";
    cout<<left<<setw(2)<<"|";
    cout<<left<<setw(10)<<"CGPA";
    cout<<left<<setw(2)<<"|"<<endl;
    cout<<left<<setw(10)<<" ";
    cout<<left<<setw(2)<<"======================================================================================"<<endl;
     DNode *current = head;
     while (current!=NULL)
     {
         cout<<left<<setw(10)<<" ";
        //  cout<<left<<setw(2)<<"|";
        //  cout<<left<<setw(20)<<current->dstu->get_id();
         cout<<left<<setw(2)<<"|";
         cout<<left<<setw(20)<<current->dstu->get_FN();
         cout<<setw(2)<<"|";
         cout<<setw(20)<<current->dstu->get_LN() ;
         cout<<setw(2)<<"|";
         cout<<setw(10)<<current->dstu->get_province();
         cout<<setw(2)<<"|";         
         cout<<setw(15)<<current->dstu->get_re();
         cout<<setw(2)<<"|";
         cout<<setw(10)<<current->dstu->get_cgpa();
         cout<<setw(2)<<"|"<<endl;
         current = current->next;
     }
    cout<<left<<setw(10)<<" ";
    cout<<left<<setw(2)<<"======================================================================================"<<endl;

   }

    void  DomesticLinkList::SearchbyID (int id){
    int flag=0;
     DNode *current = head;
        while (current!=NULL){
          if(current->dstu->get_id()==id){
         cout <<  current->dstu->get_FN()<<" "<<current->dstu->get_LN() <<"\t"
         <<current->dstu->get_province()<<"\t"
         <<current->dstu->get_cgpa()<<"\t"
         <<current->dstu->get_re()<<"\t"<<endl;
               flag=1;
               //break;
          }
          current = current->next;
        }
          if(flag==0){
            cout<<"no match record found";
          }
      }

void  DomesticLinkList::SearchbyGPA (float gpa){
  if(gpa > 4.33 || gpa<0)
  {
    cout<<"INVALID SEARCH !!!\n";
    //exit(1);
  }
  else
  {
    int flag=0;
     DNode *current = head;
        while (current!=NULL){
          if(current->dstu->get_cgpa()==gpa){
         cout <<  current->dstu->get_FN()<<" "<<current->dstu->get_LN() <<"\t"
         <<current->dstu->get_province()<<"\t"
         <<current->dstu->get_cgpa()<<"\t"
         <<current->dstu->get_re()<<"\t"<<endl;
               flag=1;
               //break;
          }
          current = current->next;
        }
          if(flag==0){
            cout<<"no match record found";
          }
  }      
}
void  DomesticLinkList::SearchbyRS (int re){
  if(re>100 || re<0)
  {
    cout<<"INVALID SEARCH !!!\n";
  }
  else
  {
    int flag=0;
     DNode *current = head;
        while (current!=NULL){
          if(current->dstu->get_re()==re){
         cout <<  current->dstu->get_FN()<<" "<<current->dstu->get_LN() <<"\t"
         <<current->dstu->get_province()<<"\t"
         <<current->dstu->get_cgpa()<<"\t"
         <<current->dstu->get_re()<<"\t"<<endl;
               flag=1;
               //break;
          }
          current = current->next;
        }
          if(flag==0){
            cout<<"no match record found";
          }
  }      
}
void  DomesticLinkList::SearchbyName(string fn,string ln){
    DomesticLinkList var ;
    int flag=0;
     DNode *current = head;
        while (current!=NULL){
          if((var.case_insensitive(current->dstu->get_FN()) == var.case_insensitive(fn)) &&
            (var.case_insensitive(current->dstu->get_LN())== var.case_insensitive(ln)) 
            )
        {
         cout <<  current->dstu->get_FN()<<" "<<current->dstu->get_LN() <<"\t"
         <<current->dstu->get_province()<<"\t"
         <<current->dstu->get_cgpa()<<"\t"
         <<current->dstu->get_re()<<"\t"<<endl;
               flag=1;
          }
          current = current->next;
        }
          if(flag==0){
            cout<<"no match record found";
          }
      }

void  DomesticLinkList::deletestudent(string fn,string ln){
  DomesticLinkList var;
    int flag=0;
     DNode *temp;
     current = head;
      //head node 
          if(
            (var.case_insensitive(current->dstu->get_FN()) == var.case_insensitive(fn)) &&
            (var.case_insensitive(current->dstu->get_LN())== var.case_insensitive(ln)) 
            ){
                 temp = current;
                 current = current->next;
                 //free(temp);
                 delete(temp);
            }
            else {
            current  = head;
             while(current->next != NULL)
            {

              //if yes, we need to delete the current->next node
              if((var.case_insensitive(current->next->dstu->get_FN()) == var.case_insensitive(fn)) && 
              (var.case_insensitive(current->next->dstu->get_LN())== var.case_insensitive(ln)) ) 
              {

                  temp = current->next;
                  //node will be disconnected from the linked list.
                  current->next = current->next->next;
                  //free(temp);
                  delete temp;
                  break;
              }
              //Otherwise, move the current node and proceed
              else
              {
                current = current->next;
              }
                
            }

           }
}
      
void  DomesticLinkList::deletestudent(){

  DNode *temp,*prev;
  if(head ==NULL){
    cout<<"Invalid Pointer"<<endl;
  }
  if(head->next==NULL){
    delete head;
  }
  //delete first node 
  else {
     temp = head;
     head = head->next; //(Moving head pointer to next node)
     //free(temp);
     delete temp;

  }
   //find second last node
   DNode* second_last = head;
    while (second_last->next->next != NULL)
        second_last = second_last->next; 
  
    // Delete last node
    delete (second_last->next);
  
    // Change next of second last
    second_last->next = NULL;
}

string DomesticLinkList::case_insensitive(string data){
  int i;
  char c;
  for (int i = 0; i < data.size(); i++)
  {
    c = data[i];
    if (isupper(c))
    {
      data[i] = tolower(c);
    }
    else
    {
      data[i] = data[i];
    }
  }
  data[0] = toupper(data[0]);

  return data;
} 
string DomesticLinkList::case_Upper(string data){
  int i;
  char c;
  for (int i = 0; i < data.size(); i++)
  {
    c = data[i];
  if (isupper(c))
  {
    data[i] = toupper(c);
  }
  else
  {
    data[i] = data[i];
  }
  }
  data[0] = toupper(data[0]);

  return data;
} 

DNode* DomesticLinkList::getHead() {
  return head;
}
