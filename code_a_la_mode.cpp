#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

class Position {
    public:
    int X,Y;
    Position();
    Position(int x, int y ){
        X=x;
        Y=y;
    }
    Position(const Position &p) { X =p.X ; Y = p.Y;}

    double distance(Position second_pos){
        return sqrt(pow(X - second_pos.X, 2)  + pow(Y - second_pos.Y, 2));
    }
    //TODO toString
};

class Item{
    string Content;
    bool HasPlate;
    
    public:
    Item();
    Item(string content){
        Content = content;
        //TODOHasPlate = 
    }
    // Copy constructor
    Item(const Item &i) {Content = i.Content; HasPlate = i.HasPlate; }
} ;

class Player{
    public:
    Position position;
    Item item;
    Player();
    Player(Item it, Position pos){
        position = pos;
        item = it;
    }
    void Refresh(Item it, Position pos){
        position = pos;
        item = it; 
    }
};



class Table{
    public:
    Position pos;

    bool HasFunction;
    Item item;
    Table();
    Table(Position p, bool hs){
        pos = p;
        HasFunction = hs;
    }
    Table(const Table &t){
        pos = t.pos; 
        HasFunction=t.HasFunction; 
        item = t.item;
    }
};


class Kitchen{
    public:
    vector<Table> tables;
    Table window;
    Table dishwasher;
    Table icecream;
    Table blueberry;

    Kitchen();
    void init(){
        string kitchen_line;
        for (int i = 0; i < 7; i++) {
            getline(cin, kitchen_line);
            for (int j = 0; j < kitchen_line.size(); j++){
                /*
                if (kitchen_line[j] == 'W') window =  Table( Position(j, i), true );
                if (kitchen_line[j] == 'D') dishwasher = Table ( Position(j, i), true );
                if (kitchen_line[j] == 'I') icecream = Table (Position(j, i), true );
                if (kitchen_line[j] == 'B') blueberry = Table (Position(j, i), true );
                if (kitchen_line[j] == '#') tables.push_back( Table(Position(j, i), false));*/
            }           

        }   
        

    }
};

/*
class MainClass{
    public:
    const string Dish = "DISH";

    static:
    Game ReadGame(){
        Game game = new Game()
        game.Players[0]= new Player(null, null);
        game.Players[1]= new Player(null, null);
        for (int i = 0 ; i<7 ; i++){
            string kitchen_line;
            getline(cin, kitchen_line);
                for (var x = 0; x < kitchenLine.Length; x++){
                if (kitchenLine[x] == 'W') game.Window = new Table { Position = new Position(x, i), HasFunction = true };
                if (kitchenLine[x] == 'D') game.Dishwasher = new Table { Position = new Position(x, i), HasFunction = true };
                if (kitchenLine[x] == 'I') game.IceCream = new Table { Position = new Position(x, i), HasFunction = true };
                if (kitchenLine[x] == 'B') game.Blueberry = new Table { Position = new Position(x, i), HasFunction = true };
                if (kitchenLine[x] == '#') game.Tables.Add(new Table { Position = new Position(x, i) });
            }

        }
    }
}
*/

int main()
{

    int num_all_customers;
    cin >> num_all_customers; cin.ignore();
    for (int i = 0; i < num_all_customers; i++) {
        string customer_item; // the food the customer is waiting for
        int customer_award; // the number of points awarded for delivering the food
        cin >> customer_item >> customer_award; cin.ignore();
    }
    /*for (int i = 0; i < 7; i++) {
        string kitchen_line;
        getline(cin, kitchen_line);
    }*/
    //Kitchen k;
    //Player p;
    //k.init();

    // game loop
    while (1) {
        Position p;
        int turns_remaining;
        cin >> turns_remaining; cin.ignore();
        int player_x;
        int player_y;
        string player_item;
        cin >> player_x >> player_y >> player_item; cin.ignore();
        int partner_x;
        int partner_y;
        string partner_item;
        cin >> partner_x >> partner_y >> partner_item; cin.ignore();
        int num_tables_with_items; // the number of tables in the kitchen that currently hold an item
        cin >> num_tables_with_items; cin.ignore();
        for (int i = 0; i < num_tables_with_items; i++) {
            int table_x;
            int table_y;
            string item;
            cin >> table_x >> table_y >> item; cin.ignore();
        }
        string oven_contents; // ignore until wood 1 league
        int oven_timer;
        cin >> oven_contents >> oven_timer; cin.ignore();
        int num_customers; // the number of customers currently waiting for food
        cin >> num_customers; cin.ignore();
        for (int i = 0; i < num_customers; i++) {
            string customer_item;
            int customer_award;
            cin >> customer_item >> customer_award; cin.ignore();
        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;


        // MOVE x y
        // USE x y
        // WAIT
        cout << "WAIT" << endl;
    }
}