#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> DIGIT {'0','1','2','3','4','5','6','7','8','9'};

class myParser{
    string input;
    int index;
    int length;
    char cur_char;
    bool last_char_reached;
    public:
    myParser(string inp){
        input = inp;
        index = 0;
        length = inp.size();
        cur_char = input[index];
        last_char_reached = false;
    }  

    bool has_next(){
        return index<length;
    } 
    
    void get_next(){
        if (has_next()){
            index++;
            set_cur_char(input[index]);
        }else{
            last_char_reached=true;
        } 
    }
    int get_index(){
        return index;
    }
    void set_cur_char(char buchst){
        cur_char=buchst;
    }
    char get_cur_char(){
        return cur_char;
    }
      

    bool sym_equal(char symbol){
        return cur_char == symbol;
    }

    void error(string expected){
        cout << "expected " << expected << ", found " << cur_char <<endl;
    }

    bool is_digit(){
        return (find(DIGIT.begin(), DIGIT.end(), get_cur_char()) != DIGIT.end());        
    }

    bool is_digit_plus(){
        if (is_digit()){
            get_next();
        }else{
            error("Digit");
            return false;
        }
        while(is_digit() && !last_char_reached){
            get_next();
        }
        return true;
    }

    bool fnumber(){
        if (sym_equal('+') || sym_equal('-')) {
            get_next();
        }
        cout << "1" << endl;
        if (last_char_reached){ return false;}
        cout << "2" << endl;
        if (!is_digit_plus()){return false;}
        cout << "3" << endl;
        if (last_char_reached){return true;}
        cout << "4" << endl;
        if (sym_equal('.')){
            get_next();
            cout << "5" << endl;
            if (last_char_reached || !is_digit_plus()){
                cout << "6" << endl;
                return false;
            }
        }
        cout << "7" << endl;
        if (last_char_reached){return true;}
        cout << "8" << endl;
        if (sym_equal('e')|| sym_equal('E')){
            get_next();
            cout << "9" << endl;
            if (last_char_reached){return false;}
            cout << "10" << endl;
            if (sym_equal('+') || sym_equal('-')) {
                get_next();
            }
            cout << "11" << endl;
            if (last_char_reached || !is_digit_plus()){
                return false;
            }
        }
        if (last_char_reached){
            return true;
        }else {
            return false;
        }
    }
};

int main(){
    //myParser testparser;
    string test = "+793.75e-91"; 
    myParser testparser = myParser(test);
    cout << testparser.fnumber() << endl;
    return 0;
}