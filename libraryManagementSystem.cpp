#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
//-BUG:  IF two book of same name exist in BOOKS.txt then there is problem in modify_book
using namespace std;
class library
{
    string book_name;
    string author_name;
    string publisher;
    string price;
    string quantity;
    public:
    //default constructor
    library()
    {

    }
    void add_book();
    void delete_book();
    void  view_booklist();
    void  search_book();

};

class librarian:public library
{
    
    string student_name;
    string student_id;
    string book_name;
    public:
    librarian()
    {
           
    }
    void issue_book();
    void modify_book();
    void view_issuedbooks();
    void search_students(); //Search for students whom book is issued
};
void librarian_menu()
{
    int choice;
    librarian obj;
        cout<<"\t\t****WELCOME LIBRARIAN****"<<endl;
        cout<<"Select an option to proceed: "<<endl;
        cout<<"1- Add a book"<<endl;
        cout<<"2- View booklist"<<endl;
        cout<<"3- Delete a book"<<endl;
        cout<<"4- Search for a book"<<endl;
        cout<<"5- Issue a book"<<endl;
        cout<<"6- Modify details of a book"<<endl;
        cout<<"7- View issued books"<<endl;
        cout<<"8- Search for students whom book is issued"<<endl;
        cout<<"9- Exit"<<endl<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                obj.add_book();
                break;
            case 2:
                obj.view_booklist();
                break;
            case 3:
                obj.delete_book();
                break;
            case 4:
                obj.search_book();
                break;
            case 5:
                obj.issue_book();
                break;
            case 6:
                obj.modify_book();
                break;
            case 7:
                obj.view_issuedbooks();
                break;
            case 8:
                obj.search_students();
                break;
            case 9:
                system("cls");
                break;
            default:
                cout<<"Invalid option try again...";
                librarian_menu();
        }

}
void login()
{
    int i=0;
    char ch,st[21],ch1[21]={"pass"};
    cout<<"\n\t\tEnter Password : ";
    while(1)
    {
    ch=getch();
    if(ch==13)
    {
        st[i]='\0';
        break;
    }
    else if(ch==8&&i>0)
    {
        i--;
        cout<<"\b \b";
    }
    else
    {
    cout<<"*";
    st[i]=ch;
    i++;
    }
    }
    ifstream inf("C://Users//hp//Desktop//OOP project//Console Application//password.txt");
    inf>>ch1;
    inf.close();
    for(i=0;st[i]==ch1[i]&&st[i]!='\0'&&ch1[i]!='\0';i++);
    if(st[i]=='\0'&&ch1[i]=='\0')
    {
        system("cls");
        librarian_menu();
    }
    else
    {
        cout<<"\n\n\t\tWrong Password.\n\n\t\ttry again.....\n";
        getch();
        system("cls");
        login();
    }
}
void menu()
{
    int choice=0;
    cout<<"\t\t****WELCOME*****"<<endl<<endl;
    cout<<"Please select an option: "<<endl;
    cout<<"1- Librarian"<<endl;
    cout<<"2- Student"<<endl;
    cout<<"Enter your choice(1,2): ";
    cin>>choice;
    if(choice==1)
    {
        login();
    }
}


void  library:: search_book()
{
    char c;
    int flag=0;
    string name;
    string line;
    string file;
    file="C://Users//hp//Desktop//OOP project//Console Application//BOOKS.txt";
    ifstream search(file);
    cout<<"Enter name of the book: ";
    cin>>name;
    while (getline(search,line))
    {
        if(line==name)
        {
            flag=1;
            cout<<"Book name: "<<line<<endl;
            getline(search,line);
            cout<<"Author name: "<<line<<endl;
            getline(search,line);
            cout<<"Publisher name: "<<line<<endl;
            getline(search,line);
            cout<<"Book price: "<<line<<endl;
            getline(search,line);
            cout<<"Book quantity: "<<line<<endl;
        }
    }
    if(flag==0)
    {
        cout<<"Book not found...";
    }

    cout<<"Press any key to continue..."<<endl;
    c=getch();
    system("cls");
    librarian_menu();

    
}

void library::view_booklist()
{
    char c;
    int no=1;
    string line;
    string file;
    file="C://Users//hp//Desktop//OOP project//Console Application//BOOKS.txt";
    ifstream view(file);
    while(getline(view,line))
    {
        cout<<"***** BOOK#"<<no<<" *****"<<endl;
        cout<<"Book name: "<<line<<endl;
        getline(view,line);
        cout<<"Author name: "<<line<<endl;
        getline(view,line);
        cout<<"Publisher name: "<<line<<endl;
        getline(view,line);
        cout<<"Price of book: "<<line<<endl;
        getline(view,line);
        cout<<"Quantity of book: "<<line<<endl<<endl;
        no++;
    }
    view.close();
    cout<<"Press any key to continue..."<<endl;
    c=getch();
    system("cls");
    librarian_menu();
}

void library::delete_book()
{
    char c;
    int flag=0;
    string line;
    cout<<"Enter name of the book to be deleted: ";
    cin>>book_name;
    string file;
    file="C://Users//hp//Desktop//OOP project//Console Application//BOOKS.txt";
    ifstream del(file);
    ofstream temp("C://Users//hp//Desktop//OOP project//Console Application//temp.txt");
    while(getline(del,line))
    {
        if(line==book_name)
        {
            flag=1;
            for(auto i=0;i<5;i++)
            {
                getline(del,line);
            }
        }
        temp<<line<<endl;
    }
    if(flag==0)
    {
        cout<<"Book not found"<<endl;
    }
    else
    {
        temp.close();
        del.close();
        remove("C://Users//hp//Desktop//OOP project//Console Application//BOOKS.txt");
        rename("C://Users//hp//Desktop//OOP project//Console Application//temp.txt","C://Users//hp//Desktop//OOP project//Console Application//BOOKS.txt");
        cout<<"Book has been deleted successfully...."<<endl;
    }
    cout<<"Press any key to continue..."<<endl;
    c=getch();
    system("cls");
    librarian_menu();


}

void library::add_book()
{
    char c;
    ofstream add("C://Users//hp//Desktop//OOP project//Console Application//BOOKS.txt" , ios::app);
    cout<<"Enter name of the book: ";
    cin>>book_name;
    cout<<"Enter name of the Author: ";
    cin>>author_name;
    cout<<"Enter name of the Publisher: ";
    cin>>publisher;
    cout<<"Enter price of the Book: ";
    cin>>price;
    cout<<"Enter quantity of the Book: ";
    cin>>quantity;
    add<<book_name<<endl;
    add<<author_name<<endl;
    add<<publisher<<endl;
    add<<price<<endl;
    add<<quantity<<endl;
    cout<<"Book has been added successfully....."<<endl;
    cout<<"Press any key to continue..."<<endl;
    c=getch();
    system("cls");
    librarian_menu();
    
}







void librarian::search_students()
{

        //This function will show details of book issued to students
        //searching book by name
    
    char c;
    int flag=0;
    string line;
    ifstream search("C://Users//hp//Desktop//OOP project//Console Application//STUDENTS.txt");
    cout<<"Enter name of book: "<<endl;
    cin>>book_name;
    while(getline(search,line))
    {
        if(line==book_name)
        {
            flag=1;
            getline(search,line);
            cout<<"Student Name:  "<<line<<endl;
            getline(search,line);
            cout<<"Student ID:  "<<line<<endl;
        }
    }
    search.close();
    if(flag==0)
    {
        cout<<"This book is not issued to any student...."<<endl;
    }
     cout<<"Press any key to continue..."<<endl;
    c=getch();
    system("cls");
    librarian_menu();
    

}

void librarian::view_issuedbooks()
{
    char c;
    string line;
    ifstream view("C://Users//hp//Desktop//OOP project//Console Application//STUDENTS.txt");
    while(getline(view,line))
    {
        cout<<"Book name: "<<line<<endl;
        getline(view,line);
        cout<<"Student name: "<<line<<endl;
        getline(view,line);
        cout<<"Student ID: "<<line<<endl;
    }   
    view.close();
     cout<<"Press any key to continue..."<<endl;
    c=getch();
    system("cls");
    librarian_menu();

}

    
void librarian::modify_book()
{
    //this function modifies the details of the book
    char c;
    string author;
    string publisher;
    string price;
    string quantity;
    int flag=0;
    string line;
    string file="C://Users//hp//Desktop//OOP project//Console Application//BOOKS.txt";    
    cout<<"Enter name of the book to be modified: "<<endl;
    cin>>book_name;
    ifstream modify(file);
    ofstream temp("C://Users//hp//Desktop//OOP project//Console Application//temp.txt");
    while(getline(modify,line))
    {
        if(line==book_name)
        {
            flag=1;
            cout<<"Enter (modified)name of author: "<<endl;
            cin>>author;
            cout<<"Enter (modified)name of publisher: "<<endl;
            cin>>publisher;
            cout<<"Enter (modified)price of book: "<<endl;
            cin>>price;
            cout<<"Enter (modified)quantity of book: "<<endl;
            cin>>quantity;
            temp<<book_name<<endl;
            temp<<author<<endl;
            temp<<publisher<<endl;
            temp<<price<<endl;
            temp<<quantity<<endl;
            for(auto i=0;i<5;i++)
            {
                getline(modify,line);
            }
        }
        temp<<line<<endl;
    }
    if(flag==0)
    {
        cout<<"Book not found"<<endl;
    }
    else
    {
        temp.close();
        modify.close();
        remove("C://Users//hp//Desktop//OOP project//Console Application//BOOKS.txt");
        rename("C://Users//hp//Desktop//OOP project//Console Application//temp.txt","C://Users//hp//Desktop//OOP project//Console Application//BOOKS.txt");
        cout<<"Book has been modified successfully...."<<endl;
    }
     cout<<"Press any key to continue..."<<endl;
    c=getch();
    system("cls");
    librarian_menu();

}



void librarian :: issue_book()
{
    int flag=0;
    int conv;
    string line;
    cout<<"Enter name of the book: "<<endl;
    cin>>book_name;
    cout<<"Enter name of student: "<<endl;
    cin>>student_name;
    cout<<"Enter ID of student: "<<endl;
    cin>>student_id;
    ifstream readfile("C://Users//hp//Desktop//OOP project//Console Application//BOOKS.txt");
    
    while(getline(readfile,line))
    {
       
        if(line==book_name)
        {
            flag=1;

            for(auto i=0;i<4;i++)
            {
                getline(readfile,line);
            }
            break;
        }
    }  
        if(flag==0)
        {
            cout<<"Book not found"<<endl;
        }
        else
        {
            conv=stoi(line);
            conv=conv-1;
            readfile.close();
            //ifstream readagain("C://Users//hp//Desktop//OOP project//Console Application//BOOKS.txt"); //changing quantity of books after issuing a book            
            string strReplace = line;
            string strNew =to_string(conv);
            ifstream filein("C://Users//hp//Desktop//OOP project//Console Application//BOOKS.txt"); //File to read from
            ofstream fileout("C://Users//hp//Desktop//OOP project//Console Application//fileout.txt"); //Temporary file
            if(!filein || !fileout)
            {
                cout << "Error opening files!" << endl;
                return ;
            }
            string strTemp;
            //bool found = false;
            while(filein >> strTemp)
            {
                if(strTemp == strReplace){
                    strTemp = strNew;
                    //found = true;
                }
                strTemp += "\n";
                fileout << strTemp;
                //if(found) break;
            }
            filein.close();
            fileout.close();
            remove("C://Users//hp//Desktop//OOP project//Console Application//BOOKS.txt"); 
            rename("C://Users//hp//Desktop//OOP project//Console Application//fileout.txt","C://Users//hp//Desktop//OOP project//Console Application//BOOKS.txt");             
            
            //Writing the name and ID of the student whom book is issued in STUDENTS.txt 

            ofstream student("C://Users//hp//Desktop//OOP project//Console Application//STUDENTS.txt",ios::app);
            student<<book_name<<endl;
            student<<student_name<<endl;
            student<<student_id<<endl;
            student.close();
        }    

            if(conv==0)
            {
                //IF quantity of book becomes zero after issuing last book then the book should be deleted from data
                string line;
                ifstream old("C://Users//hp//Desktop//OOP project//Console Application//BOOKS.txt");
                ofstream newfile("C://Users//hp//Desktop//OOP project//Console Application//temp.txt",ios::app);
                while(getline(old,line))
                {
                    if(line==book_name)
                    {
                        for(auto i=0;i<4;i++)
                        {
                            getline(old,line);
                        }
                    }
                    else
                    {
                        newfile<<line<<endl;
                    }
                    
                }
                old.close();
                newfile.close();
                remove("C://Users//hp//Desktop//OOP project//Console Application//BOOKS.txt"); 
                rename("C://Users//hp//Desktop//OOP project//Console Application//temp.txt","C://Users//hp//Desktop//OOP project//Console Application//BOOKS.txt");
            }
  
}
class student:public library
{
    public:
    student()
    {

    }
};




int main()
{
   menu();
}