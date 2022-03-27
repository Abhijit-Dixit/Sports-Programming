#include<bits/stdc++.h>
#include<thread>
using namespace std;


mutex gReadWrite; // shared mutex between readers and writers
mutex gRead;
int readerCnt=0;
string paper = "";


void Writer(string writeUp,bool append){
    while(!gReadWrite.try_lock());
    if(append)paper+=writeUp;
    else paper = writeUp;
    cout<<"paper state: "<<paper<<endl;
    gReadWrite.unlock();
}

void Reader(){
    while(!gRead.try_lock());
    readerCnt++;
    if(readerCnt==1)gReadWrite.lock();
    gRead.unlock();

    cout<<"Reading paper: "<<paper<<endl;


    gRead.lock();
    if(readerCnt==1)gReadWrite.unlock();
    readerCnt--;
    gRead.unlock();
}


int main(){
    //initializations
    thread writer1(Writer,"Hola ",true);
    thread writer2(Writer,"Namaste",true);
    thread read1(Reader);
    thread writer3(Writer,"Pranam",false);
    thread read2(Reader);

    writer1.join();
    writer2.join();
    writer3.join();
    read1.join();
    read2.join();
}
