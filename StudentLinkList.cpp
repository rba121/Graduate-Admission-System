#include "StudentLinkList.hpp"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iterator>
#include <cctype>
#include <stdio.h>
#include <ctype.h>

using namespace std;

Student* copy(DomesticLinkList* domesticStudents) {
  if (domesticStudents == NULL || domesticStudents->getHead() == NULL) 
  return NULL;

  DNode* d_head = domesticStudents->getHead();
  Student* new_head = domesticStudents->getHead()->dstu;
  new_head = d_head->dstu;
  d_head = d_head->next;
  Student* current = new_head;

  while(d_head != NULL) {
    current->next = d_head->dstu;
    d_head = d_head->next;
    current = current->next;
  }

  return new_head;
}

Student* copy(InternationalLinkList* internationalStudents) {
  if (internationalStudents == NULL || internationalStudents->getHead() == NULL) return NULL;

  INode* i_head = internationalStudents->getHead();
  Student* new_head = internationalStudents->getHead()->istu;
  new_head = i_head->istu;
  i_head = i_head->next;
  Student* current = new_head;

  while(i_head != NULL) {
    current->next = i_head->istu;
    i_head = i_head->next;
    current = current->next;
  }

  return new_head;
}

Student* merge(DomesticLinkList* domesticStudents, InternationalLinkList* internationalStudents) {
  if (domesticStudents == NULL) return copy(internationalStudents);
  if (internationalStudents == NULL) return copy(domesticStudents);

  // both input lists are not empty
  // dummy head
  Student* mergedList = new Student("", "", 0, 0, 0);
  Student* current = mergedList;

  DNode* d_head = domesticStudents->getHead();
  INode* i_head = internationalStudents->getHead();

  while (d_head != NULL && i_head != NULL) {
    if (d_head->dstu->get_re() > i_head->istu->get_re()) {
      current->next = d_head->dstu;
      d_head = d_head->next;
    }
    else if (d_head->dstu->get_re() == i_head->istu->get_re() &&
             d_head->dstu->get_cgpa() >= i_head->istu->get_cgpa()) {
      current->next = d_head->dstu;
      d_head = d_head->next;
    }
    else {
      current->next = i_head->istu;
      i_head = i_head->next;
    }

    current = current->next;
  }

  // when one list runs out
  while(d_head != NULL) {
    current->next = d_head->dstu;
    d_head = d_head->next;
  }

  while (i_head != NULL) {
    current->next = i_head->istu;
    i_head = i_head->next;
  }

  return mergedList->next;
}


// search in the merged linked list and print out all the students that exceed threshold
void searchStudent(Student* student, int cgpa_threshold, int researchScore_threshold) {
  if (student == NULL) return;

  while (student != NULL) {
    if (student->get_cgpa() >= cgpa_threshold && student->get_re() >= researchScore_threshold) {
      student->printStudent();
    }

    student = student->next;
  }
}

void Studentprint()
{
    
}