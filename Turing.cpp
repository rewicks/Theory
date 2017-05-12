/*Rachel Wicks - rw3yp

Description: This is a simulation of a Turing machine that subtracts two
binary numbers and prints out the result in the form of an equation: x - y = z.

The method of subtraction is to take the two's complement of the second number (y)
and add it to the first. The first number (x), must be greater than the second (y).
Additionally, they must both be greater than 0. The program will prompt you until
you satisfy these conditions.

After the numbers are entered, it will use the constructor on the Turing machine
which represents the human component of feeding the input into the tape of a
Turing machine. The numbers are entered in decimal, and the constructor converts
them to binary and inputs them into the machine. After this, it "runs" the machine. This is a loop that continues
until the machine is in an accept state (0). In the loop, it switches between
the states and runs the corresponding function--the transition function.

Each transition function only reads/writes and moves left/right were applicable.
Like this, it simulates the functioning of a Turing machine. The machine can also
mark a cell. In the cell class, this is a separate bool variable, however it is printed
on the tape as a '*' next to the character. Each transition function
also contains the call to print out the tape.

There is a delay in the run loop so that you can see the head moving along the tape. The head
is represented by [] surrounding the character in the cell that the head is positioned on. It
makes the program take longer to run, so it may be best to start out with smaller numbers
to see the machine move. If you decide to use large numbers, you may want to remove the delay.


*/
#include <vector>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

class cell{
   public:
      cell(char c);
      bool getMark();
      char read();
      void mark();
      void unmark();
      void write(char c);
   private:
      char symbol;
      bool marked;

};

class Turing{
   public:
      Turing(int a, int b);
      void run();
      void printTape();
   
   private:
      vector<cell*> tape;
      int head; //index value of head the index is only ever incremented/decremented by one
      int state;
      string toString(int x);
      void moveRight();
      void moveLeft();
      void stateA(); //all the states contain their respective transition functions
      void stateB(); //it's a bit exhaustive, and I'm sure there's a simpler way to do this, but alas...
      void stateC(); //the states are referred to by characters in the name, but it is actually stored
      void stateD(); //as an int (a = 1, b = 2,...za = 27, etc)
      void stateE();
      void stateF();
      void stateG();
      void stateH();
      void stateI();
      void stateJ();
      void stateK();
      void stateL();
      void stateM();
      void stateN();
      void stateO();
      void stateP();
      void stateQ();
      void stateR();
      void stateS();
      void stateT();
      void stateU();
      void stateV();
      void stateW();
      void stateX();
      void stateY();
      void stateZ();
      void stateZA();
      void stateZB();

};

Turing::Turing(int a, int b){ //the human component of setting up the Turing Machine
   head = 0;
   state = 25; //aka state y (start state)
   string x = toString(a);
   string y = toString(b);
   
   for (int i = y.length(); i < x.length(); i++){
      y = "0" + y;
   }
   
   tape.push_back(new cell(' '));
   
   for (int i = 0; i < x.length(); i++)
      tape.push_back(new cell(x.at(i)));
   tape.push_back(new cell('-'));
   for (int i = 0; i < y.length(); i++){
      tape.push_back(new cell(y.at(i)));
   }
      
   tape.push_back(new cell('='));
}

void Turing::run(){
   while (state != 0){
      clock_t wait;
      wait = clock() + .25 * CLOCKS_PER_SEC;
      while (clock() < wait){} // <--delay loop can be commented out
      switch(state){
         case 1: stateA(); break;
         case 2: stateB(); break;
         case 3: stateC(); break;
         case 4: stateD(); break;
         case 5: stateE(); break;
         case 6: stateF(); break;
         case 7: stateG(); break;
         case 8: stateH(); break;
         case 9: stateI(); break;
         case 10: stateJ(); break;
         case 11: stateK(); break;
         case 12: stateL(); break;
         case 13: stateM(); break;
         case 14: stateN(); break;
         case 15: stateO(); break;
         case 16: stateP(); break;
         case 17: stateQ(); break;
         case 18: stateR(); break;
         case 19: stateS(); break;
         case 20: stateT(); break;
         case 21: stateU(); break;
         case 22: stateV(); break;
         case 23: stateW(); break;
         case 24: stateX(); break;
         case 25: stateY(); break;
         case 26: stateZ(); break;
         case 27: stateZA(); break;
         case 28: stateZB(); break;
      }
   }
}

void Turing::stateA(){ //finds the first bit of the second number
   if (tape[head]->read() != '-')
      moveRight();
   else{
      moveRight();
      state = 2;
   }
   printTape();
}

void Turing::stateB(){ //flips the bits (for the complement)
   if (tape[head]->read() == '1'){
      tape[head]->write('0');
      moveRight();
   }
   else if (tape[head]->read() == '0'){
      tape[head]->write('1');
      moveRight();
   }
   else if (tape[head]->read() == '='){
      moveLeft();
      state = 3; //state C
   }
   printTape();
}

void Turing::stateC(){ //adds one for two's complement
   if (tape[head]->read() == '0'){
      tape[head]->write('1');
      state = 4; //state D
   }
   else if(tape[head]->read() == '1'){
      tape[head]->write('0');
      moveLeft();
   }
   printTape();
}

void Turing::stateD(){ //finds right most bit of first number
   if (tape[head]->read() != '-'){
      moveLeft();
   }
   else{
      moveLeft();
      state = 5; //state E
   } 
   printTape();
}

void Turing::stateE(){ //5 reads the right most unmarked number and stores what it reads
   if (tape[head]->read() == '0' && !tape[head]->getMark()){
      tape[head]->mark();
      state = 6; //state F
   }
   else if (tape[head]->read() == '1' && !tape[head]->getMark()){
      tape[head]->mark();
      state = 7; //state G
   }
   else if (tape[head]->read() == ' '){
      moveRight();
      state = 18;
   }
   else{
      moveLeft();
   }
   printTape();
}

void Turing::stateF(){ //6 finds the right most bit of second number
   if (tape[head]->read() != '=')
      moveRight();
   else{
      moveLeft();
      state = 8; //state H
   }
   printTape();
}

void Turing::stateG(){ //7 finds the right most bit of second number
   if (tape[head]->read() != '=')
      moveRight();
   else{
      moveLeft();
      state = 9; //state I
   }
   printTape();
}

void Turing::stateH(){ //8 finds the right most unmarked bit of second number and reads 0/1
   if (tape[head]->getMark())
      moveLeft();
   else if (tape[head]->read() == '1'){
      tape[head]->mark();
      state = 10; //0 and 1
   }
   else if (tape[head]->read() == '0'){
      tape[head]->mark();
      state = 11; //0 and 0
   }
   printTape();
}

void Turing::stateI(){ //9 finds the right most unmarked bit of second number and reads 0/1
   if (tape[head]->getMark())
      moveLeft();
   else if (tape[head]->read() == '1'){
      tape[head]->mark();
      state = 12; //1 and 1
   }
   else if (tape[head]->read() == '0'){
      tape[head]->mark();
      state = 10; //1 and 0
   }
   printTape();
}

void Turing::stateJ(){//10 if it read one 1 and one 0, then finds the right most bit in result
   if (tape[head]->read() != ' ')
      moveRight();
   else{
      moveLeft();
      state = 13;
   }
   printTape();
}

void Turing::stateK(){ //11 if it read two 0s, then it finds the right most bit in result
   if (tape[head]->read() != ' ')
      moveRight();
   else{
      moveLeft();
      state = 14;
   }
   printTape();
}

void Turing::stateL(){ //12 if it read two 1s, then it finds the right most bit in result
   if (tape[head]->read() != ' ')
      moveRight();
   else{
      moveLeft();
      state = 15;
   }
   printTape();
}

void Turing::stateM(){ //13 one 1 and one 0, finds right most unmarked bit in result, changes 0 to 1*, or 1 to 0, move left try again
   if (tape[head]->getMark())
      moveLeft();
   else if (tape[head]->read() == '0'){
      tape[head]->write('1');
      tape[head]->mark();
      moveLeft();
      state = 16;
   }
   else if (tape[head]->read() == '1'){
      tape[head]->mark();
      tape[head]->write('0');
      moveLeft();
      state = 17;
   }
   printTape();
}

void Turing::stateN(){//14 two 0s, finds right most unmarked bit in result, marks this bit
   if (tape[head]->getMark())
      moveLeft();
   else{
      tape[head]->mark();
      moveLeft();
      state = 16;
   }
   printTape();
}

void Turing::stateO(){//15 two 1s, marks the same index and moves left for adding
   if (tape[head]->getMark())
      moveLeft();
   else{
      tape[head]->mark();
      moveLeft();
      state = 17;
   }
   printTape();
}

void Turing::stateP(){//16 moves head back to the second number, then will move to the beginning of tape in state 4
   if (tape[head]->read() != '-')
      moveLeft();
   else{
      moveRight();
      state = 4;
   }
   printTape();
}

void Turing::stateQ(){ //17 carry the one
   tape[head]->write('1');
   moveLeft();
   state = 16;
   printTape();
}

void Turing::stateR(){ //18 finds first bit in result
   if (tape[head]->read() != '='){
      moveRight();
   }
   else{
      moveRight();
      state = 19;
   }
   printTape();
}

void Turing::stateS(){ //19 erases the first bit in the result
   tape[head]->write('0');
   moveRight();
   state = 20;
   printTape();
}

void Turing::stateT(){ //20 moves the head all the way right
   if (tape[head]->read() != ' ')
      moveRight();
   else{
      moveLeft();
      state = 21;
   }
   printTape();
}

void Turing::stateU(){ //unmarks the whole tape
   if (tape[head]->read() != ' '){
      tape[head]->unmark();
      moveLeft();
   }
   else
      state = 0;
   printTape();
}
     
     
void Turing::stateZ(){ //26 resets head and unmarks everything
   if (tape[head]->read() != ' '){
      tape[head]->unmark();
      moveLeft();
   }
   else
      state = 1;
   printTape();
}

void Turing::stateY(){ //25   finds the first unmarked bit in the first number and marks
   if (tape[head]->read() == ' ')
      moveRight();
   else if (!tape[head]->getMark()){
      tape[head]->mark();
      state = 24;
   }
   else{
      moveRight();
   }
   printTape();
}

void Turing::stateX(){ //24   ensures the result will have the same number of bits as the first number
   if (tape[head]->read() == '-' && tape[head]->getMark()){ // if all of the first number bits have been marked
      state = 27;
   }
   else if (tape[head]->read() != '='){ //finds the placement of the start of the result
      moveRight();
   }
   else{
      moveRight(); //will be on the first bit of the result
      state = 23;
   }
   printTape();
}

void Turing::stateW(){ //23
   if (tape[head]->read() == '0'){ //if a number has already been written, move right
      moveRight();
   }
   else{
      tape[head]->write('0'); //write a zero (will be changed later)
      state = 22;
   }
   printTape();
}

void Turing::stateV(){ //22
   if (tape[head]->getMark()){ //finds the next unmarked bit from the first number
      moveRight();
      state = 25;
   }
   else
      moveLeft();
   printTape();
}

void Turing::stateZA(){ //27 moves tape head to first bit past the equals sign for adding one additional bit to the end of result
   if (tape[head]->read() != '=')
      moveRight();
   else{
      moveRight();
      state = 28;
   }
   printTape();
}

void Turing::stateZB(){ //28 writes one additional bit (result will be one bit longer than necessary)
   if (tape[head]->read() == '0'){
      moveRight();
   }
   else{
      tape[head]->write('0');
      state = 26;
   } 
   printTape();
}
   

void Turing::printTape(){
   cout << "STATE: " << state << endl;
   for (int i = 0; i < tape.size(); i++){
      cout << "|";
      if (head == i)
         cout << "[";
      cout << tape[i]->read();
      if (tape[i]->getMark())
         cout << "*";
      if (head == i)
         cout << "]";
   }
   cout << "|" << endl;
}

string Turing::toString(int x){
   string temp = "";
   while (x != 0){
      if (x % 2 == 0)
         temp += "0";
      else
         temp += "1";
      x /= 2;
   }
   string retVal = "";
   for (int i = temp.size() - 1; i >= 0; i--){
      retVal += temp.at(i);
   }
   return retVal;
}

void Turing::moveRight(){
   if (head < tape.size() - 1)   
      head++;
   else{
      tape.push_back(new cell(' '));
      head++;
   }
}

void Turing::moveLeft(){
   head--;
}

cell::cell(char c){
   symbol = c;
   marked = false;
}

bool cell::getMark(){
   return marked;
}

char cell::read(){
   return symbol;
}

void cell::mark(){
   marked = true;
}

void cell::unmark(){
   marked = false;
}

void cell::write(char c){
   symbol = c;
}

int main(){
   int x, y;
   cout << "Welcome to my Turing Program!" << endl
         << "After each transition, the program will print out the tape. The cells are divided by '|' and the head of the Turing machine is represented by '[]'" << endl
         << "If a cell is marked, it will have a '*' by it" << endl
         << "For anything else, see comments! :)" << endl << endl
         << "Directions: " << endl
         << "You will be asked to enter two unsigned integers. The first number MUST BE greater than the second number. They must BOTH be greater than 0." << endl
         << "Your equation (with the answer) will be shown in tape format in binary" << endl << endl
         << "FIRST INTEGER: ";
   
   cin >> x;
   cout << "SECOND INTEGER: ";
   cin >> y;
   
   while (x < y || x < 0){
      cout << endl << "Please try again" << endl;
      cout << "FIRST INTEGER: ";
      cin >> x;
      cout << "SECOND INTEGER: ";
      cin >> y;
   }
         
   Turing t(x, y);
   t.printTape();
   t.run();
   return 0;
 }