#include "InternationalLinkList.hpp"
#include <iomanip>



void InternationalLinkList::Intpush(InternationalStudent d)
{
  try
  {    

        InternationalStudent* ins = new InternationalStudent(d.get_FN(),d.get_LN(),d.get_cgpa(),d.get_re(),d.get_id(),d.get_country(),d.get_toefl());
        INode* node = new INode(ins);
        if(head==NULL || compareInternationalAscending(*head->istu,*node->istu)){
           node->next= head;
           head = node;
        } 
        else
        {
           current = head;
           while (current->next!=NULL && (compareInternationalAscending(*node->istu,*current->next->istu)))
            {
              current = current->next;
            }
              node->next= current->next;
              current->next = node;
        }
  }
  catch(bad_alloc)
  {
    cout<<"Ran Out of Memory";
  }    
     

     
}

void InternationalLinkList::internationalinsert(string fn , string ln , string country , float cgpa , int re_scr , 
int read_scr , int listen_scr , int speak_scr , int write_scr)
{
    string Canada = "Canada";
    string China = "China";
    string India = "India";
    string Iran = "Iran";
    string Korea = "Korea";
   
  if(re_scr>100 || re_scr<0)
  {
    cout<<"Invalid Entry!!!";
  }
  else if(cgpa>4.33 || cgpa<0)
  {
    cout<<"Invalid Entry!!!";
  }
  else if(read_scr>30 || read_scr<0 || listen_scr>30 || listen_scr<0 || speak_scr>30 || speak_scr<0 || write_scr>30 || write_scr<0)
  {
    cout<<"Invalid Entry!!!";
  }
  else if (!(country == Canada || country == China || country == Iran || country == India || country == Korea) )
  {
    cout<<"Invalid Entry!!!";
  }
  else
  {
    InternationalStudent i;
    i.set_FN(fn);
    i.set_LN(ln);
    i.set_country(country);
    i.set_cgpa(cgpa);
    i.set_re(re_scr);
    i.set_toefl(ToeflScore(read_scr,listen_scr,speak_scr,write_scr));
    Intpush(i);
      
  }
}

   void InternationalLinkList::Intprint(){
     cout<<left<<setw(10)<<" ";
    cout<<left<<setw(2)<<"======================================================================"
                       <<"===================================================================================="<<endl;
    cout<<left<<setw(10)<<" ";
    cout<<left<<setw(2)<<"|";
    cout<<left<<setw(20)<<"First name";
    cout<<left<<setw(2)<<"|";
    cout<<left<<setw(20)<<"Last name";
    cout<<left<<setw(2)<<"|";
    cout<<left<<setw(15)<<"Research Score";
    cout<<left<<setw(2)<<"|";
    cout<<left<<setw(10)<<"CGPA";
    cout<<left<<setw(2)<<"|";
    cout<<left<<setw(10)<<"Country";
    cout<<left<<setw(2)<<"|";
    cout<<left<<setw(15)<<"Reading Score";
    cout<<left<<setw(2)<<"|";
    cout<<left<<setw(15)<<"Writing Score";
    cout<<left<<setw(2)<<"|";
    cout<<left<<setw(15)<<"Listening Score";
    cout<<left<<setw(2)<<"|";
    cout<<left<<setw(15)<<"Speaking Score";
    // cout<<left<<setw(2)<<"|";
    // cout<<left<<setw(20)<<"Total Tofel Score";
    cout<<left<<setw(2)<<"|\n";
    cout<<left<<setw(10)<<" ";
    cout<<left<<setw(2)<<"======================================================================"
                        <<"===================================================================================="<<endl;
     INode *current = head;
     while (current!=NULL)
     {
        cout<<left<<setw(10)<<" ";
        cout<<left<<setw(2)<<"|";
        cout<<left<<setw(20)<<current->istu->get_FN();
        cout<<setw(2)<<"|";
        cout<<setw(20)<<current->istu->get_LN() ;
        cout<<setw(2)<<"|";
        cout<<setw(15)<<current->istu->get_re();
        cout<<setw(2)<<"|";         
        cout<<setw(10)<<current->istu->get_cgpa();
        cout<<setw(2)<<"|";
        cout<<setw(10)<<current->istu->get_country();
        cout<<setw(2)<<"|";
        cout<<setw(15)<<current->istu->get_toefl().get_rd_scr();
        cout<<setw(2)<<"|";
        cout<<setw(15)<<current->istu->get_toefl().get_wrt_scr();
        cout<<setw(2)<<"|";
        cout<<setw(15)<<current->istu->get_toefl().get_lst_scr();
        cout<<setw(2)<<"|";
        cout<<setw(15)<<current->istu->get_toefl().get_spk_scr();
        cout<<setw(2)<<"|";
        // cout<<setw(20)<<current->istu->get_toefl().get_totalsum();
        cout<<setw(2)<<""<<endl;
        current = current->next;
     }

     cout<<left<<setw(10)<<" ";
     cout<<left<<setw(2)<<"======================================================================"
                        <<"===================================================================================="<<endl;


   }

  
   
void  InternationalLinkList::SearchbyID (int id){
    int flag=0;
     INode *current = head;
        while (current!=NULL){
          if(current->istu->get_id()==id){
        cout<<current->istu->get_FN()<< " " <<current->istu->get_LN() <<"\t"
        <<current->istu->get_re()<<"\t"
        <<current->istu->get_cgpa()<<"\t"
        <<current->istu->get_country()<<"\t"
        <<current->istu->get_toefl().get_rd_scr()<<"\t"
        <<current->istu->get_toefl().get_wrt_scr()<<"\t"
        <<current->istu->get_toefl().get_lst_scr()<<"\t"
        <<current->istu->get_toefl().get_spk_scr()<<endl;
        current = current->next;
               flag=1;
               break;
          }
          current = current->next;
        }
          if(flag==0){
            cout<<"no match record found";
          }
      }

void  InternationalLinkList::SearchbyGPA (float gpa){
  if(gpa>4.33 || gpa<0)
  {
    cout<<"INVALID SEARCH !!!";
  
  }
  else
  {
    int flag=0;
     INode *current = head;
        while (current!=NULL){
          if(current->istu->get_cgpa()==gpa){
        cout<<current->istu->get_FN()<< " " <<current->istu->get_LN() <<"\t"
        <<current->istu->get_re()<<"\t"
        <<current->istu->get_cgpa()<<"\t"
        <<current->istu->get_country()<<"\t"
        <<current->istu->get_toefl().get_rd_scr()<<"\t"
        <<current->istu->get_toefl().get_wrt_scr()<<"\t"
        <<current->istu->get_toefl().get_lst_scr()<<"\t"
        <<current->istu->get_toefl().get_spk_scr()<<endl;
        current = current->next;
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
void  InternationalLinkList::SearchbyRS (int re){
  if(re>100 || re<0)
  {
    cout<<"INVALID SEARCH !!!";
  }
  else
  {
    int flag=0;
     INode *current = head;
        while (current!=NULL){
          if(current->istu->get_re()==re){
        cout<<current->istu->get_FN()<< " " <<current->istu->get_LN() <<"\t"
        <<current->istu->get_re()<<"\t"
        <<current->istu->get_cgpa()<<"\t"
        <<current->istu->get_country()<<"\t"
        <<current->istu->get_toefl().get_rd_scr()<<"\t"
        <<current->istu->get_toefl().get_wrt_scr()<<"\t"
        <<current->istu->get_toefl().get_lst_scr()<<"\t"
        <<current->istu->get_toefl().get_spk_scr()<<endl;
        current = current->next;
               flag=1;
              
          }
          current = current->next;
        }
          if(flag==0){
            cout<<"no match record found";
          }
  }       
}
   
void  InternationalLinkList::SearchbyName (string fn,string ln){
  InternationalLinkList var;
    int flag=0;
     INode *current = head;
        while (current!=NULL){
           if(
           (var.case_insensitive(current->istu->get_FN()) == var.case_insensitive(fn)) &&
            (var.case_insensitive(current->istu->get_LN())== var.case_insensitive(ln)) 
            )
        {
        cout<<current->istu->get_FN()<< " " <<current->istu->get_LN() <<"\t"
        <<current->istu->get_re()<<"\t"
        <<current->istu->get_cgpa()<<"\t"
        <<current->istu->get_country()<<"\t"
        <<current->istu->get_toefl().get_rd_scr()<<"\t"
        <<current->istu->get_toefl().get_wrt_scr()<<"\t"
        <<current->istu->get_toefl().get_lst_scr()<<"\t"
        <<current->istu->get_toefl().get_spk_scr()<<endl;
        current = current->next;
               flag=1;
          }
          current = current->next;
        }
          if(flag==0){
            cout<<"no match record found";
          }
      }

  void  InternationalLinkList::deletestudent(string fn,string ln){
    InternationalLinkList var;
    int flag=0;
     INode *temp;
     current = head;
     
          if(
            (var.case_insensitive(current->istu->get_FN()) == var.case_insensitive(fn)) &&
            (var.case_insensitive(current->istu->get_LN())== var.case_insensitive(ln)) 
            ){
                 temp = current;
                 current = current->next;
                 //free(temp);
                 delete temp;
            }
            else {
            current  = head;
             while(current->next != NULL)
            {

              //if yes, we need to delete the current->next node
              if(            
                (var.case_insensitive(current->next->istu->get_FN()) == var.case_insensitive(fn)) &&
                (var.case_insensitive(current->next->istu->get_LN())== var.case_insensitive(ln))
                ) 
              {

                  temp = current->next;
                  //node will be disconnected from the linked list.
                  current->next = current->next->next;
                  //free(temp);
                  delete temp;
                  break;
              }
              //Otherwise, move the current node and proceed
              else{
                  current = current->next;
              }
            }

           }
}

void  InternationalLinkList::deletestudent(){

  INode *temp,*prev;
  if(head ==NULL){
    cout<<"Invalid Pointer"<<endl;
  }
  if(head->next==NULL){
    delete head;
  }
  //delete first node
  else {
     temp = head;
     head = head->next;
     //free(temp);
     delete temp;

  }
   //find second last node
    prev = head;
    while (prev->next->next != NULL)
        prev = prev->next;
  
    // Delete last node
    delete (prev->next);
  
    // Change next of second last
    prev->next = NULL;
  
}


string InternationalLinkList::case_insensitive(string data){
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

INode* InternationalLinkList::getHead() {
  return head;
}
