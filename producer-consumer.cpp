#include<bits/stdc++.h>
#include<thread>
#include<mutex>
using namespace std;


const int BUFFER_SIZE = 10; // max limit of data structure
mutex gMutex; // shared mutex between cons and prod
bool gReady; // variable ensuring new changes have been made by the other party
deque<int> dq; // common data structure for producing and consuming data;

void Producer(){
    while(dq.size()==BUFFER_SIZE){
        this_thread::sleep_for(chrono::seconds(1));
    }
    unique_lock<mutex> ul(gMutex);
    int dataCnt =6;
    while(dataCnt-- && dq.size()<BUFFER_SIZE){
        int newData = rand();
        dq.push_back(newData);
        cout<<"produced "<<newData<<endl;
    }
    gReady=true;
    ul.unlock();
}

void Consumer(){
    while(!gReady){
        this_thread::sleep_for(chrono::seconds(1));
    }
    unique_lock<mutex> ul(gMutex);
    while(!dq.empty()){
        cout<<"consumed "<<dq.front()<<endl;
        dq.pop_front();
    }
    gReady=false;
    ul.unlock();
}


int main(){
    //initializations
    gReady = false;
  
    thread producer(producer);
    thread consumer(consumer);

    // join makes the main thread to wait for producer and consumer thread to complete
    producer.join();
    consumer.join();
    
}
