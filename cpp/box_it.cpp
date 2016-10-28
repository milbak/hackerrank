// box it

//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);

// Destructor
// ~Box()
// {

// }

// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box &b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box B)
class Box {
    private:
        int l,b,h;
    public:
        Box() {
            l=0;
            b=0;
            h=0;
            BoxesCreated++;
        }
        Box(int a1, int a2, int a3) {
            l=a1;
            b=a2;
            h=a3;
            BoxesCreated++;
        }
        Box(const Box& B) {
            l=B.l;
            b=B.b;
            h=B.h;
            BoxesCreated++;
        }
        ~Box() {BoxesDestroyed++;}
        int getLength() {return l;}
        int getBreadth() {return b; }
        int getHeight() {return h;}
        long long CalculateVolume() {return (long long) l*b*h;}   
    
        bool operator<(const Box& B){
            return ((l<B.l)||((b<B.b)&&(l==B.l))||((h<B.h)&&(b==B.b)&&(l==B.l)));
        }

        friend ostream& operator<<(ostream& os, Box B) {
            os<<B.l<<" "<<B.b<<" "<<B.h;
            return os;
        }
};
