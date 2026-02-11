#include<iostream>
#include<vector>
#include<string>
#include<map>
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
class Lib2{
private:
    map<string, Book> books;
public:
    void addBook(const Book& book ){
        books.emplace(book.getTitle(),book);
    }
    bool isBookAvailable(const string& title){
         auto it = books.find(title);
    return it != books.end() && it->second.available();
    }
    bool issueBook(const string& title) {
        auto it=books.find(title);
        if(it!=books.end() && it->second.available()){
            it->second.issue();
            return true;
        }
        return false;
    }
};
int main(){
    // Library lib;

    // lib.addBook(Book("C++"));
    // lib.addBook(Book("OOPS"));

    // lib.issueBook("C++");
    // cout<<lib.isBookAvailable("C++");
    // lib.returnBook("C++");
    // cout<<endl<<lib.isBookAvailable("C++");

    Lib2 lib;

    lib.addBook(Book("C++"));
    lib.addBook(Book("OOPS"));
    cout<<lib.isBookAvailable("C++")<<endl;
    lib.issueBook("C++");
    cout<<lib.isBookAvailable("C++");
}