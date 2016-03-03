/* 
  1 Dimensional Dynamically allocated stack in C++
  Author: FaisalKhan 
  Dated: 2/3/16.
*/

#include <iostream>
#include <string>
#include <fstream>


using namespace std;

/*
 Stack class begins
 */
class Stack{
    
private:
    
    int top;
    // A pointer to the array that will be
    //initialized in the constructor
    int *dataArray;
    
    
public:
    //overloaded constructor
    Stack(int capicity){
        
        top = -1;
        dataArray = new int[capicity];
    }
    
    
    void push(int data){
        
        top = top + 1;
        dataArray[top] = data;
    }
    
    int pop(){
        
        top = top - 1;
        return dataArray[top+1];
    }
    
    bool isEmpty(){
        
        if(top < 0) return true;
        else    return false;
    }
    
    //destructor to free the space after usage
    ~Stack(){
        
        delete dataArray;
    }


   }; // class Stack ends



int main(int argc, const char * argv[]) {
    
    //counter for the number of integers in the file
    int count = 0;
    
    //temperory variable to store the integer read from file
    int fileData;
    
    ifstream inputFile;
    
    //open the file provided an argument
    inputFile.open(argv[1]);
    
    if(!inputFile.is_open()){
        cout<<"A file must be provided as an argument!"<<endl;
        cout<<"Terminating Program."<<endl;
        return -1;
    }
    
    cout<<endl;

    cout<<"Data Read from the File"<<endl;
    
    cout<<endl;

    //keep on reading from file until there is no more data left to read
    while(inputFile >> fileData){
    
    //writing data read to console
    cout << fileData << "  ";

    //increase the number of integers read from the file
    count ++;
    
    
    }
    
    cout<<endl;
    
    /*stack array pointer pointing to an object of type Stack
     with dynamically allocated array whom size is based on 
     the number of integers read from provided file.*/
    Stack *stackArry = new Stack(count);
    
    //close the input file
    inputFile.close();
    
    //Reopen the input file
    inputFile.open(argv[1]);

    //keep on reading from file until there is no more data left to read
    while(inputFile >> fileData){
        
        //push the integers read from the file into the stack
        stackArry->push(fileData);
        
    }
    
    cout<<endl;
    
    cout << "Poping Elements of the stack" <<endl;
    
    cout<<endl;

    while(!stackArry->isEmpty()){
    //pop the elements of the stack
    cout<<stackArry->pop()<< "  ";
        
    }
    
    cout<<endl;
    cout<<endl;

    //close input file
    inputFile.close();
    
    //delete the stack object
    delete stackArry;
    
    return 0;
}
