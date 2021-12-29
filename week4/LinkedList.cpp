/*
LinkedList 
*/
#include<iostream>
#include<string>


struct Tower
{
    std::string name;
    Tower *link; 
};


Tower *create_beacon();
Tower *create_tower(std::string name, Tower *link);
void signal(Tower *start);
void recursive_signal(Tower *start);


int main() {
    Tower *list_example = create_beacon();
    signal(list_example);
    recursive_signal(list_example);
    return 0;
}


Tower *create_beacon(){
    Tower *tp = create_tower("Rohan", NULL);
    tp = create_tower("halifirien", tp);
    tp = create_tower("Calenhad", tp);
    tp = create_tower("Min-Rinmon", tp);
    tp = create_tower("Nardol", tp);
    return create_tower("Amon Din", tp);
}


Tower *create_tower(std::string name, Tower *link) {
    Tower *tp = new Tower;  // new operator to take memoery from heap 
    tp->name = name; 
    tp->link = link; 
    return tp;
}


void signal(Tower *start) {
    for (Tower *tp = start; tp != NULL; tp = tp->link) {
        std::cout << "Lighting " << tp->name << "Its address is: " << tp << "\n";
    }
}

void recursive_signal(Tower *start) { 
    if (start != NULL) {
        std::cout << "Lighting " << start->name << "Its address is: " << start << "\n";
        recursive_signal(start->link);
    }

}