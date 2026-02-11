#include<iostream>
#include<vector>
using namespace std;

class Book{
private:
    string title;
    bool isIssued;
public:
    Book(string t){
        this->title=t;
        this->isIssued=false;
    }
    bool available(){
        return !isIssued;
    }
    void issue(){
        isIssued=true;
    }
    void giveBack(){
        isIssued=false;
    }
    string getTitle() const{
        return title;
    }
};
class Library{
private:
    vector<Book> books;
public:
    void addBook(const Book& book){
        books.push_back(book);
    }
    bool isBookAvailable(const string& title){
        for(auto& book:books){
            if(book.getTitle()==title && book.available()) return true;
        }
        return false;
    }
    bool issueBook(const string& title){
        for(auto& book:books){
            if(book.getTitle() == title && book.available()){
                book.issue();
                return true;
            }
        }
        return false;
    }
    bool returnBook(const string& title){
        for(auto& book:books){
            if(book.getTitle()==title && !book.available()){
                book.giveBack();
                return true;
            }
        }
        return false;
    }
};
int main(){
    Library lib;

    lib.addBook(Book("C++"));
    lib.addBook(Book("OOPS"));

    lib.issueBook("C++");
    cout<<lib.isBookAvailable("C++");
    lib.returnBook("C++");
    cout<<endl<<lib.isBookAvailable("C++");
}