//virtual functions
static int pid = 0, sid = 0;

class Person {
    protected:
        int age;
        string name;
    public:
        virtual void getdata(){
            cin>>name>>age;
        }
        virtual void putdata(){
            cout<<name<<" "<<age<<" ";
        }
};

class Professor : public Person {
    int pubs,id;
    public:
        Professor(){
             id = ++pid;
        }
        void getdata(){
            Person::getdata();
            cin>>pubs;
        }
        void putdata(){
            Person::putdata();
            cout<<pubs<<" "<<id<<endl;
        }
};
class Student : public Person {
    int marks[6];
    int id,sum;
    public:
        Student(){
            id = ++sid;
            sum =0;
        }
        void getdata(){
            Person::getdata();
            for(int i = 0; i<6; i++){
                cin>>marks[i];
                sum+=marks[i];
            }      
        }
        void putdata(){
            Person::putdata();
            cout<<sum<<" "<<id<<endl;
        }
};