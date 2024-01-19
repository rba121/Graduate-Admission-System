#include "DomesticLinkList.hpp"
#include "InternationalLinkList.hpp"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>

using namespace std;

Student* copyD(DomesticLinkList* domesticStudents);

Student* copyI(InternationalLinkList* internationalStudents);

Student* merge(DomesticLinkList* domesticStudents, InternationalLinkList* internationalStudents);




// search in the merged linked list and print out all the students that exceed threshold
void searchStudent(Student* student, int cgpa_threshold, int researchScore_threshold);
void Studentprint();