//2>Recursive Program

 #include<iostream>
 using namespace std;
 void Fibonacci(int n){
 static int n1=0, n2=1, n3;
 if(n>0)
 {
	n3 = n1 + n2;
	n1 = n2;
	n2 = n3;
	cout<<n3<<" ";
	Fibonacci(n-1);
 }
 }
 int main()
 {
	int n;
	cout<<"Enter the number of elements: ";
	cin>>n;
	cout<<"Fibonacci Series: ";
	cout<<"0 "<<"1 ";
	Fibonacci(n-2); //n-2 because 2 numbers are already printed
 return 0;
 }