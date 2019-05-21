#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include "LinkedStack.h"

using namespace std;

void readData(LinkedStack<string> & myStack);
bool arepair(char opening,char closing);
bool balanced(string exp);
void check( LinkedStack<string> myStack);

int main() {
    LinkedStack<string> myStack;
 
    readData(myStack);
    check(myStack);
    
    return 0;
}

void readData(LinkedStack<string> & myStack){
    ifstream file;
    file.open("input.txt");
    string expression;
    file >> expression;
    while(!file.eof()) {
      getline(file, expression);
      myStack.push(expression);
    }
    file.close();
}

bool arepair(char opening,char closing)
{
	if(opening == '(' && closing == ')') return true;
	else if(opening == '{' && closing == '}') return true;
	else if(opening == '[' && closing == ']') return true;
	return false;
}

bool balanced(string exp)
{
  stack<char>s;
  for(int i = 0; i < exp.length();i++)
    {
      if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
	s.push(exp[i]);
      }else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
	if(s.empty() || !arepair(s.top(),exp[i])){
	  return false;
	}else{
	  s.pop();
	}
      }
    }
  return s.empty() ? true:false;
}

void check( LinkedStack<string> myStack){
  LinkedStack<string> checkStack(myStack);
  while(!checkStack.isEmpty()){
    string exp = checkStack.peek();
    cout << exp;
    if(balanced(exp)){
      cout << exp << " Valid\n";
    }else{
      cout << exp << " Not Valid\n";
    }
    checkStack.pop();
  }

}
