
//#include "student.hpp"
//#include "international.hpp"
using namespace std; //use namespace std
#include <string> //you will have to use string in C++

    class ToeflScore 
    {
        public:
            //Defalut constructor
            ToeflScore();

            ToeflScore(int readscore , int listenscore , int speakscore , int writescore );

            void set_rd_scr(int read);
            void set_lst_scr(int listen);
            void set_wrt_scr(int write);
            void set_spk_scr(int speak);

            int get_rd_scr()  const;
            int get_lst_scr() const;
            int get_wrt_scr() const;
            int get_spk_scr() const;
            int get_totalsum() const;


        private:
            int reading_scr;
            int listening_scr;
            int writing_scr;
            int speaking_scr;
        
    };
//}    