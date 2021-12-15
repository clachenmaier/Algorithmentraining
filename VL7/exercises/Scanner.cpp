#include <iostream>

using namespace std;

class Inputo{
    int index, length;
    string input;
    public:
    Inputo(string inp){
        index = 0;
        length = inp.size();
        input = inp;
    }

    char next(){
        if (index< length){
            char literal = input[index];
            index++;
            return literal;
        } else{
            return 'f' ;
        }
    }
};
class Scanner{

};

int main(){
    string test = "Hello";
    Inputo input = new Inputo(test);
    for (int i = 0 ; i<7; i++){
        cout << input.next() << endl;
    }
    return 0;
}