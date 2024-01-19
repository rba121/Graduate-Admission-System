#compile and link the application
all: main

#run the application
run: main
	./main

#link main.o, student.o, and stu_sort.o to executable main
main: main.o student.o international.o domestic.o toefl.o  DomesticLinkList.o InternationalLinkList.o StudentLinkList.o
	g++ -g -o main main.o student.o international.o domestic.o toefl.o DomesticLinkList.o  InternationalLinkList.o StudentLinkList.o

#compile the main.cpp to main.o
main.o: main.cpp
	g++ -g -c main.cpp

#compile the student.cpp to student.o
student.o: student.cpp
	g++ -g -c student.cpp

#compile the international.cpp to international.o
international.o: international.cpp
	g++ -g -c international.cpp

#compile the domestic.cpp tos domestic.o
domestic.o: domestic.cpp
	g++ -g -c domestic.cpp

#compile the toefl.cpp to toefl.o
toefl.o: toefl.cpp
	g++ -g -c toefl.cpp

#compile the DomesticLinkList.cpp to DomesticLinkList.o
DomesticLinkList.o: DomesticLinkList.cpp
	g++ -g -c DomesticLinkList.cpp

#compile the InternationalLinkList.cpp to InternationalLinkList.o
InternationalLinkList.o: InternationalLinkList.cpp
	g++ -g -c InternationalLinkList.cpp

#compile the StudentLinkList.cpp to InternationalLinkList.o
StudentLinkList.o: StudentLinkList.cpp
	g++ -g -c StudentLinkList.cpp


#remove built files
clean:
	rm -rf main main.o student.o international.o domestic.o toefl.o StudentLinkList.o DomesticLinkList.o InternationalLinkList.o *~
