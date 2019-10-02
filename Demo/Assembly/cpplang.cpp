#include <iostream>
using namespace std;

// Test c++ class virtual friend
class ClassType
{
  protected:
    int index;
    char buf[3];
    const char *name;

  public:
    ClassType(int index)
    {
        cout << "Constructor ClassType: " << index << endl;
        this->index = index;
        this->buf[0] = 'a';
        this->buf[1] = 'b';
        this->buf[2] = 'c';
        this->name = "HelloWorld!";
    }
    ~ClassType()
    {
        cout << "Destructor ClassType: " << this->index << endl;
    }
    void display()
    {
        cout << "index: " << this->index << endl;
        cout << "buf: " << this->buf[0] << ", " << this->buf[1] << ", " << this->buf[2] << ", " << endl;
        cout << "*name: " << this->name << endl;
    }
    virtual void whoami()
    {
        cout << "ClassType" << endl;
    }
    friend void changeIndex(ClassType &var, int index);
};
void changeIndex(ClassType &var, int index)
{
    var.index = index;
}
class ChildType : public ClassType
{
  public:
    ChildType(int index) : ClassType(index)
    {
        cout << "Constructor ChildType: " << index << endl;
    }
    ~ChildType()
    {
        cout << "Destructor ChildType: " << this->index << endl;
    }
    virtual void whoami()
    {
        cout << "ChildType" << endl;
    }
};

int main()
{
    class ClassType LocalClass(1);
    LocalClass.display();
    LocalClass.whoami();
    changeIndex(LocalClass, 3);

    class ChildType ChildClass(2);
    ChildClass.display();
    ChildClass.whoami();

    class ClassType *classPtr;
    classPtr = &LocalClass;
    classPtr->display();
    classPtr = &ChildClass;
    classPtr->display();

    return 0;
}