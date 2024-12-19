#include <iostream>
#include <string> 
#include <limits> 
class Publication
{ protected:
std::string title;
float price;

public:
Publication() : title(""), price(0.0) {}
Publication(const std::string& t, float p) : title(t), price(p) {}

virtual void input() {
std::cout << "Enter the title: ";
std::getline(std::cin, title);

std::cout << "Enter the price: "; 
std::cin >> price;
if (std::cin.fail()) {
 throw std::runtime_error("Invalid price input");
}
std::cin.clear();
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

virtual void display() const {
std::cout << "Title: " << title << ", Price: $" << price << std::endl;
}
};
class Book : public Publication { private:
int pageCount;
public:
Book() : Publication(), pageCount(0) {}
Book(const std::string& t, float p, int pc) : Publication(t, p), pageCount(pc) {}

void input() override { try {
Publication::input();
std::cout << "Enter the page count: "; std::cin >> pageCount;
if (std::cin.fail()) {
throw std::runtime_error("Invalid page count input");
}
std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
} catch (const std::exception& e) {
std::cerr << "Error: " << e.what() << ". Setting default values." << std::endl; title = "";
price = 0.0;
pageCount = 0;
 
}
}

void display() const override { Publication::display();
std::cout << "Page Count: " << pageCount << std::endl;
}
};
class Tape : public Publication { private:
float playingTime;

public:
Tape() : Publication(), playingTime(0.0) {}
Tape(const std::string& t, float p, float pt) : Publication(t, p), playingTime(pt) {}

void input() override { try {
Publication::input();
std::cout << "Enter the playing time (in minutes): "; std::cin >> playingTime;
if (std::cin.fail()) {
throw std::runtime_error("Invalid playing time input");
}
std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
} catch (const std::exception& e) {
std::cerr << "Error: " << e.what() << ". Setting default values." << std::endl; title = "";
price = 0.0;
playingTime = 0.0;
}
}
void display() const override { Publication::display();
std::cout << "Playing Time: " << playingTime << " minutes" << std::endl;
}
};

int main() {
std::cout << "For Book:" << std::endl; Book book;
book.input();
std::cout << "\nBook Details:" << std::endl; book.display();

std::cout << "\nFor Tape:" << std::endl; Tape tape;
tape.input();
std::cout << "\nTape Details:" << std::endl; tape.display();
 
return 0;
}