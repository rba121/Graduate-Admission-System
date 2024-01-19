/*
 * Filename: main.cpp
 *
 * Description: 
 *
 * Author: Riyan Roy & Rohit Bhardwaj
 * Student ID: 301472766(Roy) & 301450331(Bhardawaj)
 * Date: 2nd June 2022
 * 
 */

//main.cpp, put your driver code here, 
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <vector>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <bits/stdc++.h>
//#include "DomesticLinkList.hpp"
//#include "InternationalLinkList.hpp"
#include "StudentLinkList.hpp"
//#include "toefl.hpp"
using namespace std;



int main()
{
  vector<DomesticStudent> d_studentlist;
  vector<InternationalStudent> i_studentlist; 
  DomesticStudent d_stobj;
  InternationalStudent i_stobj;
 // studentSort stusort;
  DomesticLinkList* dll = new DomesticLinkList();
  InternationalLinkList* intll = new InternationalLinkList(); 

  string prefix = "2022";
  string con,striid;
  int val = 0;

  
  string line1,line2;
  //d stands for domestic , i stands for international
  int stu_count = 1;

  //Read the domestic-stu.txt file and exit if failed
  ifstream domesticFile("domestic-stu.txt");
  if(!domesticFile.is_open()) 
  {
    cout << "Unable to open file domestic-stu.txt" << endl;
    return -1;
  }

  //Read the first line of domestic-stu.txt, which specifies
  //the file format. And then print it out to the screen
  getline(domesticFile, line1);
  //cout<<"File Format: "<<line1<<endl;
  
  while( getline(domesticFile, line1) ) 
  {
    int line = stu_count + 1;
    istringstream ss(line1);

     line1.rfind(",");  
    
    //get firstName separated by comma
    string d_FN,d_LN,d_Prv,d_cgpa,d_res;
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
    float dcgpa;
    int dres_scr;
    if(val<9)
    {
      con = "000";
    }
    else if(val>=10 && val<99)
    {
      con = "00";
    }
    else if(val>=100 && val<999)
    {
      con = "0";
    }
    //striid = prefix + con + to_string(val);
    getline(ss , d_FN , ',');
    if (d_FN == "")
    {
      cout<<"\nFor one of the Domestic Student the First Name data is empty in line "<<line<<"\n\n";
      exit(1);
    }
    else
    {
      d_stobj.set_FN(d_FN);
    }
    
    getline(ss , d_LN , ',');
    if (d_LN == "")
    {
      string X = "";
      d_stobj.set_LN(X);
    }
    else
    {
      d_stobj.set_LN(d_LN);
    }
    
    getline(ss , d_Prv , ',');
    if (d_Prv == NL || d_Prv == PE || d_Prv == NS || d_Prv == NB || d_Prv == QC || d_Prv == ON || d_Prv == MB || d_Prv == SK || d_Prv == AB || d_Prv == BC || 
        d_Prv == YT || d_Prv == NT || d_Prv == NU )
    {
      d_stobj.set_province(d_Prv);
    }
    else if (d_Prv == "" )
    {
      cout<<"\nFor one of the Domestic Student the Province data is empty in line "<<line<<"\n\n";
      exit(1);
    }
    else
    {
      cout<<"\nFor one of the Domestic Student the Province data is incorrect in line "<<line<<"\n\n";
      exit(1);
    }

    getline(ss, d_cgpa, ',');
    dcgpa = atof(d_cgpa.c_str());
    if (d_cgpa == "")
    {
      cout<<"\nFor one of the Domestic Student the CGPA data is empty in line "<<line<<"\n\n";
      exit(1);
    }
    else if (dcgpa > 4.33 || dcgpa < 0)
    {
      cout<<"\nFor one of the Domestic Student the CGPA data is of the range (4.33 SFU scale) or missing in line "<<line<<"\n\n";
      exit(1);
    }
    else
    {
      d_stobj.set_cgpa(dcgpa);
    }
    
    

    getline(ss, d_res, ',');
    dres_scr = atoi(d_res.c_str());
    if (d_res == "")
    {
      cout<<"\nFor one of the Domestic Student the Research Score data is empty in line "<<line<<"\n\n";
      exit(1);
    }
    else if (dres_scr > 100 || dres_scr < 0)
    {
      cout<<"\nFor one of the Domestic Student the Research Score data is of the range (0 - 100) or missing in line "<<line<<"\n\n";
      exit(1);
    }
    else
    {
      d_stobj.set_re(dres_scr);
    }
    
    dll->domesticpush(d_stobj);
    stu_count++;
  }
  
  //close your file
  domesticFile.close();

  //dll->domesticprint();

  //*******************************************************************************************************//

  //Read the international-stu.txt file and exit if failed
  ifstream internationalFile("international-stu.txt");
  if(!internationalFile.is_open()) {
    cout << "Unable to open file international-stu.txt" << endl;
    return -1;
  }

  //Read the first line of international-stu.txt, which specifies
  //the file format. And then print it out to the screen
  getline(internationalFile, line2);
  
  int loop=0;
  while( getline(internationalFile, line2) ) 
  {
    int line = loop + 1;
    istringstream ss(line2);
    line2.rfind(",");

    string i_FN,i_LN,country,i_cgpa,i_res,readscr,listenscr,speakscr,writescr;
    string Canada = "Canada";
    string China = "China";
    string India = "India";
    string Iran = "Iran";
    string Korea = "Korea";
    string Idian = "Idian";
    float icgpa;
    int ires_scr,read,listen,speak,write;

    getline(ss,i_FN,',');
    if (i_FN == "")
    {
      cout<<"\nFor one of the Internation Student the First Name data is empty in line "<<line<<"\n\n";
      exit(1);
    }
    else
    {
      i_stobj.set_FN(i_FN);
    }

    getline(ss,i_LN,',');
    if (i_LN == "")
    {
      string X = "";
      i_stobj.set_LN(X);
    }
    else
    {
      i_stobj.set_LN(i_LN);
    }

    getline(ss,country,',');
    if (country == Canada || country == China || country == Iran || country == India || country == Korea )
    {
      i_stobj.set_country(country);
    }
    else if (country == Idian)
    {
      //cout<<"\nTypo error, Idian is invaild, should be India in line"<<line<<"\nAutocorrected to India\n";
      i_stobj.set_country(India);
    }
    else if (country == "")
    {
      cout<<"\nFor one of the International Student the Country data is empty in line "<<line<<"\n\n";
      exit(1);
    }
    else
    {
      cout<<"\nFor one of the International Student the Country data is incorect in line "<<line<<"\n\n";
      exit(1);
    }
    
    

    getline(ss, i_cgpa, ',');
    icgpa = atof(i_cgpa.c_str());
    if (i_cgpa == "")
    {
      cout<<"\nFor one of the International Student the CGPA data is empty in line "<<line<<"\n\n";
      exit(1);
    }
    else if (icgpa > 4.33 || icgpa < 0)
    {
      cout<<"\nFor one of the International Student the CGPA data is of the range (4.33 SFU scale) or missing in line "<<line<<"\n\n";
      exit(1);
    }
    else
    {
      i_stobj.set_cgpa(icgpa);
    }

    getline(ss, i_res, ',');
    ires_scr = atoi(i_res.c_str());
    if (i_res == "")
    {
      cout<<"\nFor one of the International Student the Research Score data is empty in line "<<line<<"\n\n";
      exit(1);
    }
    else if (ires_scr > 100 || ires_scr < 0)
    {
      cout<<"\nFor one of the International Student the Research Score data is of the range (0 - 100) or missing in line "<<line<<"\n\n";
      exit(1);
    }
    else
    {
      i_stobj.set_re(ires_scr);
    }

    getline(ss, readscr, ',');
    read = atoi(readscr.c_str());
    getline(ss, listenscr, ',');
    listen = atoi(listenscr.c_str());
    getline(ss, speakscr, ',');
    speak = atoi(speakscr.c_str());
    getline(ss, writescr, ',');
    write = atoi(writescr.c_str());
    if (read>30||read<0||readscr=="")
    {
      cout<<"\nFor one of the International Student the Reading Score data is of the range (0 - 30) or missing in line "<<line<<"\n\n";
      exit(1);
    }
    else if (listen>30||listen<0||listenscr=="")
    {
      cout<<"\nFor one of the International Student the Listening Score data is of the range (0 - 30) or missing in line "<<line<<"\n\n";
      exit(1);
    }
    else if (speak>30||speak<0||speakscr=="")
    {
      cout<<"\nFor one of the International Student the Speaking Score data is of the range (0 - 30) or missing in line "<<line<<"\n\n";
      exit(1);
    }
    else if (write>30||write<0||writescr=="")
    {
      cout<<"\nFor one of the International Student the Writing Score data is of the range (0 - 30) or missing in line "<<line<<"\n\n";
      exit(1);
    }
    else
    {
      i_stobj.set_toefl(ToeflScore(read,listen,speak,write));
      //cout<<"\n"<<read;
      //i_stobj.set_toefl(ToeflScore(20,20,20,20));
    }
    intll->Intpush(i_stobj); 

    loop++;
  }
  //close your file
  internationalFile.close();
  //intll->Intprint();

  //*******************************************************************************************************//

  int Test_Code = 2;//<---------------------Change this to 0 for Test_unit or 1 for Error cheacking or 2 for main UI

  if (Test_Code ==0)
  {
    //Insert Domestic Student Normal case
    dll->domesticinsert("Amit","Sharma","BC",3.20,89);

    //Insert Domestic Student Corner Case
    dll->domesticinsert("Amit","Sharma","BC",4.33,100);

    //Insert Domestic Student corner Case
    dll->domesticinsert("Amit","Sharma","BC",2.75,69);

    //Insert Domestic Student Illegal Case
    dll->domesticinsert("Amit","Sharma","BC",3.20,101);

    dll->domesticprint();

    //Domestic student Search by CGPA 
    cout<<"\n Domestic CGPA Search Normal case \n ";
    dll->SearchbyGPA(2.85); //Normal Case
    cout<<"\n Domestic CGPA Search Corner Case \n ";
    dll->SearchbyGPA(4.33); // Corner case
    cout<<"\n Domestic CGPA Search Illegal  Case \n ";
    dll->SearchbyGPA(4.35); //Illegal Case

    //Domestic student Search by Res_scr 
    cout<<"\n Domestic Res_scr Search Normal case \n ";
    dll->SearchbyRS(80); //Normal
    cout<<"\n Domestic Res_scr Search Corner case \n ";
    dll->SearchbyRS(100); //Corner
    cout<<"\n Domestic Res_scr Search Illegal case \n";
    dll->SearchbyRS(101); //Illegal

    //Deleting Domestic student using first name and last name
    cout<<"\nDeleting student using Firt Name and Last Name........";
    dll->deletestudent("Nora","Barnes");
    //dll->domesticprint();
    dll->deletestudent("ASHER", "BryaNt");
    dll->deletestudent("Aurora","Foster");
    dll->domesticprint();

    cout<<"\n========================================================================================\n";

    //Delete Domestic Head Node and Tail Node
    dll->deletestudent(); //domestic
    dll->domesticprint();

    cout<<"\n========================================================================================================\n";

    //Insert International Student Normal Case
    intll->internationalinsert("Rohit","Titans","Korea",3.20,85,23,25,23,27);

    //Insert International Student Corner Case
    intll->internationalinsert("Rohit","Titans","Korea",4.33,90,30,30,30,30);

    //Insert International Student Illegal Case
    intll->internationalinsert("Rohit","Titans","Korea",2.65,70,27,31,25,23);
    cout<<"Insert Print\n";
    intll->Intprint();

    //International student Search by CGPA 
    cout<<"International Search GPA Normal case\n";
    intll->SearchbyGPA(3.20); //Normal case
    cout<<"International Search GPA Corner case\n";
    intll->SearchbyGPA(4.33); //Corner Case
    cout<<"International Search GPA Illegal case\n";
    intll->SearchbyGPA(4.35); //Illegal case

    //International student Search by Res_scr
    cout<<"International Search RS Normal case\n";
    intll->SearchbyRS(80); //Normal
    // cout<<"International Search RS Corner case\n";
    // intll->SearchbyRS(100); //Corner
    cout<<"International Search RS Illegal case\n";
    intll->SearchbyRS(101); //Illegal

    //Deleting International Student using first name and last name
    cout<<"Deleting International Student by name\n";
    intll->deletestudent("Ting", "Fang"); //Corner Case
    intll->deletestudent("Mohammad","Darbandi"); //Corner case
    intll->deletestudent("Tania" , "Asan");//Normal case
    intll->deletestudent("Rohit","Bhardwaj"); //Illegal case
    intll->Intprint();

    cout<<"Deleting International Student by name\n";
    //Deleting International Student Head and Tail Node
    intll->deletestudent();
    //Printing Table
    intll->Intprint();



    cout<<"\n========================================================================================================\n";

    Student* mergedHead = merge(dll, intll);
    searchStudent(mergedHead,2.85,75);

    searchStudent(mergedHead,4.33,101); //Illegal case


  }
  else if (Test_Code == 1)
  {
    dll->domesticinsert("Rohit","Bhardwaj","XX",3.15,100);
    dll->SearchbyName("EvElyN","MuRphY");
  }
  else if (Test_Code == 2)
  {
    string Username = "";
    string Password = "";
    bool login = false;
    
    cout<<left<<setw(10)<<" ";
    cout<<"Welcome To SFU Graduate Student Admission System\n";
    cout<<left<<setw(10)<<" ";
    cout<<"Please Login.....\n";


    do
    {
      cout<<left<<setw(10)<<" ";
      cout<<"Username:  ";
      cin>>Username;
      cout<<left<<setw(10)<<" ";
      cout<<"Password:  ";
      cin>>Password;

      if (Username == "PRJ_13" && Password == "312")
      {
        cout<<left<<setw(10)<<" ";
        cout<<"Login Successfull\n\n";
        login = true;
      }
      else
      {
        cout<<left<<setw(10)<<" ";
        cout<<"Username or Password is wrong\n";
        cout<<left<<setw(10)<<" ";
        cout<<"Please try again\n";
      }
      

    } while (!login);

    if (login == true)
    {
      int ch;
      cout<<left<<setw(10)<<" ";
      for(;;)
    {  
        cout<<" *** Menu ***\n";
        cout<<"1. Display Domsetic Student\n";
        cout<<"2. Display International Student\n";
        cout<<"3. Search\n";
        cout<<"4. Insert\n";
        cout<<"5. Delete\n";
        cout<<"6. Merge\n";
        cout<<"7. Clear\n";
        cout<<"8. Exit\n";
        cout<<"Enter your choice: ";                       
        cin>>ch;

    if(ch == 1 || ch == 2 ||ch == 3 ||ch == 4 ||ch == 5 ||ch == 6 ||ch == 7 ||ch == 8 )
      {
        switch(ch)
        {
            case 1:
            {
              dll->domesticprint();
              break;
            }
         	 
            case 2:
            {
              intll->Intprint();
              break;
            } 
         	 
            case 3:
            {
              int A;
              bool temp = false;
              do
              { 
                cout<<" *** Search ***\n";
                cout<<"1. Search Domsetic Student by Name\n";
                cout<<"2. Search Domsetic Student by CGPA\n";
                cout<<"3. Search Domsetic Student by Research Score\n";
                cout<<"4. Search International Student by Name\n";  
                cout<<"5. Search International Student by CGPA\n";
                cout<<"6. Search International Student by Research Score\n";
                cout<<"7. Go Back\n"; 
                cout<<"Enter your choice: ";                      
                cin>>A;
            if(A == 1 || A == 2 ||A == 3 ||A == 4 ||A == 5 ||A == 6 ||A == 7 )
              {
                switch (A)
                {
                case 1:
                {
                  string fn;
                  string ln;
                  cout<<"Enter First Name:";
                  cin>>fn;
                  cout<<"Enter Last Name:";
                  cin>>ln;
                  dll->SearchbyName(fn,ln);
                  break;            
                }
                case 2:
                {
                  double cgpa;
                  cout<<"Enter CGPA: ";
                  cin>>cgpa;
                  dll->SearchbyGPA(cgpa);
                  break; 
                }
                case 3:
                {
                  int re;
                  cout<<"Enter Research Score: ";
                  cin>>re;
                  dll->SearchbyRS(re);
                  break; 
                }
                case 4:
                {
                  string fn;
                  string ln;
                  cout<<"Enter First Name:";
                  cin>>fn;
                  cout<<"Enter Last Name:";
                  cin>>ln;
                  intll->SearchbyName(fn,ln);
                  break;
                }
                case 5:
                {
                  double cgpa;
                  cout<<"Enter CGPA: ";
                  cin>>cgpa;
                  intll->SearchbyGPA(cgpa);
                  break;
                }
                case 6:
                {
                  int re;
                  cout<<"Enter Research Score: ";
                  cin>>re;
                  intll->SearchbyRS(re);
                  break; 
                }
                case 7:
                {
                  temp = true;
                  system("clear");
                }
                default:
                {
                  cout<<"Invalid Entry"<<endl;
                  //break;
                }
              }
            }
            else
            {
              cout<<"Invalid Entry\n";
              break;
            }
            }
              while (!temp);
              break;
              
        
            }
         	 
            case 4:
            {
              int A;
              bool temp = false;
              do
              { 
                cout<<" *** Insert ***\n";
                cout<<"1. Insert Domsetic Student\n";
                cout<<"2. Insert International Student\n";
                cout<<"3. Go Back\n"; 
                cout<<"Enter your choice: ";                      
                cin>>A;
            if(A == 1 || A == 2 ||A == 3 )
              {
                switch (A)
                {
                  case 1:
                  {
                    string fn,ln,pr;
                    double cgpa;
                    int re;
                    cout<<"Enter First Name:";
                    cin>>fn;
                    cout<<"Enter Last Name:";
                    cin>>ln;
                    cout<<"Enter Province:";
                    cin>>pr;
                    cout<<"Enter CGPA:";
                    cin>>cgpa;
                    cout<<"Enter Research Score:";
                    cin>>re;
                    dll->domesticinsert(fn,ln,pr,cgpa,re);
                    break;
                  }
                  case 2:
                  {
                    string fn,ln,con;
                    double cgpa;
                    int re,rs,ls,ss,ws;
                    cout<<"Enter First Name:";
                    cin>>fn;
                    cout<<"Enter Last Name:";
                    cin>>ln;
                    cout<<"Enter Country:";
                    cin>>con;
                    cout<<"Enter CGPA:";
                    cin>>cgpa;
                    cout<<"Enter Research Score:";
                    cin>>re;
                    cout<<"Enter Reading Score:";
                    cin>>rs;
                    cout<<"Enter Listening Score:";
                    cin>>ls;
                    cout<<"Enter Speaking Score:";
                    cin>>ss;
                    cout<<"Enter Writing Score:";
                    cin>>ws;
                    intll->internationalinsert(fn,ln,con,cgpa,re,rs,ls,ss,ws);
                    break;
                  }
                  case 3:
                  {
                    temp = true;
                    system("clear");
                  }
                }
              }
              else
              {
                cout<<"Invalid Entry";
                break;

              }
              }
              while (!temp);
              break;
        
            }

            case 5:
            { 
              int A;
              bool temp = false;
              do
              {
                cout<<" *** Delete ***\n";
                cout<<"1. Delete Domsetic Student\n";
                cout<<"2. Delete Head and Tail Note for Domsetic Student\n";
                cout<<"3. Delete International Student\n";  
                cout<<"4. Delete Head and Tail Note for International Student\n";
                cout<<"5. Go Back\n"; 
                cout<<"Enter your choice: ";                      
                cin>>A;
            if(A == 1 || A == 2 ||A == 3 ||A == 4 ||A == 5 )
              {
                switch (A)
                {
                  case 1:
                  {
                    string fn;
                    string ln;
                    cout<<"Enter First Name:";
                    cin>>fn;
                    cout<<"Enter Last Name:";
                    cin>>ln;
                    dll->deletestudent(fn,ln);
                    //dll->domesticprint();
                    break;            
                  }
                  case 2:
                  {
                    dll->deletestudent();
                    //dll->domesticprint();
                    break;
                  }
                  case 3:
                  {
                    string fn;
                    string ln;
                    cout<<"Enter First Name:";
                    cin>>fn;
                    cout<<"Enter Last Name:";
                    cin>>ln;
                    intll->deletestudent(fn,ln);
                    //dll->domesticprint();
                    break;
                  }
                  case 4:
                  {
                    intll->deletestudent();
                    break;
                  }
                  case 5:
                  {
                    temp = true;
                    system("clear");
                  }
                } 
              }
              else
              {
                cout<<"Invalid Entry";
                break;
              }
              }
              while (!temp);
              break;
                
              }

            case 6: 
            {
              int A;
              bool temp = false;
              do
              {
                cout<<" *** Merge ***\n";
                cout<<"1. Merge Student List\n";
                cout<<"2. View exsiting merge lisrt\n"; 
                cout<<"3. Go Back\n"; 
                cout<<"Enter your choice: ";                      
                cin>>A;
            if(A == 1 || A == 2 ||A == 3 )
              {
                switch (A)
                {
                case 1:
                {
                  Student* mergedHead = merge(dll, intll);
                  break;
                }
                case 2:
                {
                  double cgpa_threshold;
                  int researchScore_threshold;
                  cout<<"Enter the CGPA threshold:";
                  cin>>cgpa_threshold;
                  cout<<"Enter the Research Score threshold:";
                  cin>>researchScore_threshold;
                  if (cgpa_threshold>4.33||cgpa_threshold<0||researchScore_threshold>100||researchScore_threshold<0)
                  {
                    cout<<"Invalid entry";
                    break;
                  }
                  else{
                    Student* mergedHead = merge(dll, intll);
                    searchStudent(mergedHead,cgpa_threshold, researchScore_threshold);
                    break; 
                  }
                  break;   
                }
                case 3:
                {
                  temp = true;
                  system("clear");
                }
              } 
              }
              else
              {
                cout<<"Invalid Entry";
                break;
              }
              }
              while (!temp);
              break;
            }
  
            case 7: 
            {
              system("clear");
              break;
            }
            case 8: 
            {
              system("clear");
              exit(1);
              break;
            }
            default:
              cout<<"Invalid Entry!!!"<<endl;
        }
      }
      else
      {
        cout<<"Invalid Entry";
        break;
      }
  }
    
    
  }
  else
  {
    cout<<"\n**ERROR**\n";
    exit(1);
  }
     
  return 0;
}

}


