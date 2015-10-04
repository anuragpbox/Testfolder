#include <iostream>

using namespace std;

class Line
{
   public:
      int getLength( void );
	  void setLength( int len);
      Line( int len );             // simple constructor
      Line( const Line &obj);  // copy constructor
      ~Line();                     // destructor

   private:
      int *ptr;
};

// Member functions definitions including constructor
Line::Line(int len)
{
    cout << "Normal constructor allocating ptr" << endl;
    // allocate memory for the pointer;
    ptr = new int;
    *ptr = len;
}

Line::Line(const Line &obj)
{
    cout << "Copy constructor allocating ptr." << endl;
    ptr = new int;
   ptr = obj.ptr; // point to pointer.
}

Line::~Line(void)
{
    cout << "Freeing memory!" << endl;
    delete ptr;
}
int Line::getLength( void )
{
    return *ptr;
}


void display(Line obj)
{
   cout << "Length of line : " << obj.getLength() <<endl;
}

void Line::setLength( int len )
{
	*ptr = len;
}
// Main function for the program
int main( )
{
   Line line1(10);

   int a=0;
   int* p;
   p=&a;
   
  int* p2;
   p2=p;
   
   cout<<"p2 value :" << *p2 <<endl;
   
   Line line2 = line1; // This also calls copy constructor
   
   
   display(line1);
   display(line2);

	line1.setLength(20);
	line2.setLength(30);
	
	display(line1);
	display(line2);
   
   return 0;
}