#include<iostream>
#include<mutex>
using namespace std;

class Singleton{
  private:
    static Singleton* instance;
    static mutex mtx;
    Singleton(){
      cout<<"Object created."<<endl;
    }

  public:
    static Singleton* getInstance(){
      lock_guard<mutex> lock(mtx);
      if(instance==nullptr){
        instance=new Singleton();
      }
      return instance;
    }
};

Singleton* Singleton :: instance=nullptr;
mutex Singleton::mtx;

int main(){
  return 0;
}