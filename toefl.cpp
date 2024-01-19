#include "toefl.hpp"
using namespace std; //use namespace std

ToeflScore::ToeflScore():reading_scr(0),listening_scr(0),speaking_scr(0),writing_scr(0)
{
    //delibrately empty
}

ToeflScore::ToeflScore(int readscore , int listenscore , int speakscore , int writescore):
reading_scr(readscore),listening_scr(listenscore),speaking_scr(speakscore),writing_scr(writescore)
{
    //delibrately empty
}

//set functions
void ToeflScore::set_rd_scr(int read)
{
    reading_scr=read;
}

void ToeflScore::set_lst_scr(int listen)
{
    listening_scr=listen;
}

void ToeflScore::set_wrt_scr(int write)
{
    writing_scr=write;
}

void ToeflScore::set_spk_scr(int speak)
{
    speaking_scr=speak;
}


//get functions
int ToeflScore::get_rd_scr() const
{
    return reading_scr;
}

int ToeflScore::get_lst_scr() const
{
    return listening_scr;
}

int ToeflScore::get_wrt_scr() const
{
    return writing_scr;
}

int ToeflScore::get_spk_scr() const
{
    return speaking_scr;
}

int ToeflScore::get_totalsum() const
{
    return reading_scr + writing_scr + listening_scr + speaking_scr;
}





