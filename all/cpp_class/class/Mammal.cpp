#include<cmath>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<iomanip>
#include<iostream>


using namespace std;
enum COLOR { WHITE, RED, BROWN, BLACK, KHAKI };
//枚举类型，定义的名字叫COLOR，变量有后边这一串（WHITE, RED, BROWN, BLACK, KHAKI ）
//在这里是好看的？
//有给他赋值吗？

/*基类*/
class Mammal
{
public:
    //constructors
    Mammal(){}
    Mammal(int age)
    {
        itsAge=age;
    }
    ~Mammal(){}

    //accessors
    int GetAge() const
    {
        return itsAge;
    }
    void SetAge(int n)
    {
        itsAge=n;
    }
    int GetWeight() const
    {
        return itsWeight;
    }
    void SetWeight(int n)
    {
        itsWeight=n;
    }

    //Other methods
    void Speak() const//这个得好好写
    {
        cout<<"Mammal is speaking..."<<endl;
    }
    void Sleep() const//看起来可以瞎写
    {
        cout<<"Mammal is sleeping..."<<endl;
    }
protected:
    int itsAge;
    int itsWeight;
};

/*派生类*/

class Dog:public Mammal
{
public://呵
    Dog() {}//构造函数1号
    Dog(int age):Mammal(age) {}//构造函数2号
    Dog(int age,int weight):Mammal(age)//构造函数3号
    {
       SetWeight(weight);
    }
    Dog(int age, COLOR color):Mammal(age)//构造函数4号
    {
        colors=color;
    }
    Dog(int age, int weight, COLOR color):Mammal(age)//构造函数5号
    {
         SetWeight(weight);
        colors=color;
    }
    ~Dog() {}

    void WagTail() const//这个得好好写
    {
        cout<<"The dog is wagging its tail..."<<endl;
    }
    void BegForFood()  const//看起来可以瞎写
    {
        cout<<"The dog is begging for food..."<<endl;
    }
protected:
    COLOR colors;//所以其实没啥用？
};
int main()
{
	Dog Fido;
	Dog Rover(5);
	Dog Buster(6, 8);
	Dog Yorkie(3, RED);
	Dog Dobbie(4, 20, KHAKI);
	Fido.Speak();
	Rover.WagTail();
	cout << "Yorkie is " << Yorkie.GetAge() << " years old." << endl;
	cout << "Dobbie weighs " << Dobbie.GetWeight() << " pounds." << endl;
	return 0;
}

