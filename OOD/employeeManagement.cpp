// inheritance
// pure virtual functions
// function overloading
// protected, private and public access

#include <bits/stdc++.h>
using namespace std;
#define ll          long long
#define pb          push_back
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define rall(a)      (a).rbegin(),(a).rend()
#define ff           first
#define ss           second
//#define endl        '\n'
//#define mod        1000000007
//#define mod        998244353
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define rem(i,a,b)  for(int i=a;i>b;i--)
#define INF         numeric_limits<ll>::max()
#define NINF        numeric_limits<ll>::min()
#define vvi(a,b,name)    vector<vector<int>> name(a,vector<int>(b,-1))
#define vvd(a,b,name)    vector<vector<double>> name(a,vector<double>(b,-1))
#define int long long
//const ld pi=3.14159265359;

// inheritance
// pure virtual functions
// function overloading
// protected, private and public access
// static variables


class Salary{
private:
    int CTC;
    int base;
    int bonus;
    int stocks;
public:
    Salary(){
        base=0;
        bonus=0;
        stocks=0;
    }
    void increment(int baseInc,int bonusInc,int stocksInc){
        this->base+=baseInc;
        this->bonus+=bonusInc;
        this->stocks+=stocksInc;
    }
    void increment(int bonusInc){
        this->bonus+=bonusInc;
    }
    void print(){
        cout<<"CTC - "<<bonus+base+stocks<<endl;
    }
};


class Employee{
protected:
    string name;
    Salary* salary;
public:
    // festive bonus to all
    virtual void promote()=0;
    void printSalary(){
        cout<<name<<endl;
        salary->print();
    }
};

class Manager:public Employee{
private:
    int baseInc = 5;
    int stockInc = 20;
    int bonus = 10;
public:
    //Manager's Hefty bonus
    Manager(string name){
        this->name = name;
        salary = new Salary();
    }
    void promote(){
        salary->increment(baseInc,bonus,stockInc);
    }
};

class Engineer:public Employee{
private:
    int bonus = 15;
public:
    Engineer(string name){
        this->name = name;
        salary = new Salary();
    }
    void promote(){
        salary->increment(bonus);
    }
};

class Organization{
private:
    set<Employee*> employees;
public:
    static int headCount;
    static string name;
    void addEmployee(Employee* e){
        employees.insert(e);
    }
    void fireEmployee(Employee* e){
        employees.erase(employees.find(e));
    }
    void promoteAll(){
        for(auto employee: employees){
            employee->promote();
            employee->printSalary();
        }
    }
};

int Organization::headCount=0;
string Organization::name="Aarti Industries";

void solve(){
    Organization AartiIND = Organization();
    Employee* manager1 = new Manager("Aarti Shukla");
    Employee* engineer1 = new Engineer("Achintya Patel");
    Employee* engineer2 = new Engineer("Aman Gupta");
    AartiIND.addEmployee(manager1);
    AartiIND.addEmployee(engineer1);
    AartiIND.addEmployee(engineer2);
    AartiIND.promoteAll();
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
