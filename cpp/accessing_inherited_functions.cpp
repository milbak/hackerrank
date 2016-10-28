// accessing inherited functions
class D : public A, public B, public C
{

	int val;
	public:
		//Initially val is 1
		 D()
		 {
		 	val=1;
		 }


		 //Implement this function
		 void update_val(int new_val)
		 {
             int v = new_val;
             while(v%2==0){
                 A::func(val);
                v=v/2;
             }    
             while(v%3==0){
                 B::func(val);
                 v=v/3;
             } 
             while(v%5==0){
                 C::func(val);
                 v=v/5;
             } 
		 }
		 //For Checking Purpose
		 void check(int); //Do not delete this line.
};
