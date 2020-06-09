#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
           
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
    char choice;
    librarian obj;
        cout<<endl<<"\t\t**** WELCOME LIBRARIAN ****"<<endl<<endl;
        cout<<"\tSelect an option to proceed: "<<endl;
        cout<<"\t1- Add a book"<<endl;
        cout<<"\t2- View booklist"<<endl;
        cout<<"\t3- Delete a book"<<endl;
        cout<<"\t4- Search for a book"<<endl;
        cout<<"\t5- Issue a book"<<endl;
        cout<<"\t6- Modify details of a book"<<endl;
        cout<<"\t7- View issued books"<<endl;
        cout<<"\t8- Search for students whom book is issued"<<endl;
        cout<<"\t9- Exit"<<endl<<endl;
        cout<<"\tEnter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case '1':
                obj.add_book();
                break;
            case '2':
                obj.view_booklist();
                break;
            case '3':
                obj.delete_book();
                break;
            case '4':
                obj.search_book();
                break;
            case '5':
                obj.issue_book();
                break;
            case '6':
                obj.modify_book();
                break;
            case '7':
                obj.view_issuedbooks();
                break;
            case '8':
                obj.search_students();
                break;
            case '9':
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
    ifstream inf("password.txt");
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
class student
{
    public:
    student()
    {

    }
    void view_stbooklist();
    void search_stbook();
};
void student_menu()
{
    student st;
    char choice;
    system("cls");
    cout<<endl<<endl<<"\t\t******  Welcome Student  ******"<<endl<<endl;
    cout<<"\t\t1- View Booklist"<<endl;
    cout<<"\t\t2- Search For a Book"<<endl;
    cout<<"\t\t3- Exit"<<endl;
    cout<<"\t\tEnter your choice: ";
    cin>>choice;
    if(choice=='1')
    {
        
            st.view_stbooklist();
    }
    else if(choice=='2')
    {
            st.search_stbook();
    }
    else if( choice=='3')
    {
        exit(1);
    }
    else
    {
            system("cls");
            student_menu();
    }   
}
void student::search_stbook()
{
    char c;
    int flag=0;
    string name;
    string line;
    string file;
    ifstream search("BOOKS.txt");
    cout<<"\tEnter name of the book: ";
    cin>>name;
    while (getline(search,line))
    {
        if(line==name)
        {
            flag=1;
            cout<<"\tBook name: "<<line<<endl;
            getline(search,line);
            cout<<"\tAuthor name: "<<line<<endl;
            getline(search,line);
            cout<<"\tPublisher name: "<<line<<endl;
            getline(search,line);
            cout<<"\tBook price: "<<line<<endl;
            getline(search,line);
            cout<<"\tBook quantity: "<<line<<endl;
        }
    }
    if(flag==0)
    {
        cout<<"\tBook not found..."<<endl;
    }
    search.close();
    cout<<"\tEnter any key to continue...";
    c=getch();
    system("cls");
    student_menu();

}
void student::view_stbooklist()
{
    char c;
    int no=1;
    string line;
    ifstream view("BOOKS.txt");
    while(getline(view,line))
    {
        cout<<"\t\t***** BOOK#"<<no<<" *****"<<endl;
        cout<<"\tBook name: "<<line<<endl;
        getline(view,line);
        cout<<"\tAuthor name: "<<line<<endl;
        getline(view,line);
        cout<<"\tPublisher name: "<<line<<endl;
        getline(view,line);
        cout<<"\tPrice of book: "<<line<<endl;
        getline(view,line);
        cout<<"\tQuantity of book: "<<line<<endl<<endl;
        no++;
    }
    view.close();
    cout<<"\tEnter any key to continue...";
    c=getch();
    system("cls");
    student_menu();
}


void menu()
{
    char choice;
    cout<<endl<<endl<<"\t\t***** WELCOME *****"<<endl<<endl;
    cout<<"\t1- Librarian"<<endl;
    cout<<"\t2- Student"<<endl;
    cout<<"\t\tEnter your choice(1,2): ";
    cin>>choice;
    if(choice=='1')
    {
        login();
    }
    else if(choice=='2')
    {
        student_menu();
    }
    else
    {
        system("cls");
        menu();
    }
    

}

void show_librarianmenu()
{
    char c;
    cout<<endl<<"\tPress any key to continue..."<<endl;
    c=getch();
    system("cls");
    librarian_menu();
}


void  library:: search_book()
{
    
    int flag=0;
    string name;
    string line;
    ifstream search("BOOKS.txt");
    cout<<"\tEnter name of the book: ";
    cin>>name;
    while (getline(search,line))
    {
        if(line==name)
        {
            flag=1;
            cout<<"\tBook name: "<<line<<endl;
            getline(search,line);
            cout<<"\tAuthor name: "<<line<<endl;
            getline(search,line);
            cout<<"\tPublisher name: "<<line<<endl;
            getline(search,line);
            cout<<"\tBook price: "<<line<<endl;
            getline(search,line);
            cout<<"\tBook quantity: "<<line<<endl;
        }
    }
    if(flag==0)
    {
        cout<<"\tBook not found...";
    }

    show_librarianmenu();

    
}

void library::view_booklist()
{
    int no=1;
    string line;
    ifstream view("BOOKS.txt");
    while(getline(view,line))
    {
        cout<<"\t\t***** BOOK#"<<no<<" *****"<<endl;
        cout<<"\tBook name: "<<line<<endl;
        getline(view,line);
        cout<<"\tAuthor name: "<<line<<endl;
        getline(view,line);
        cout<<"\tPublisher name: "<<line<<endl;
        getline(view,line);
        cout<<"\tPrice of book: "<<line<<endl;
        getline(view,line);
        cout<<"\tQuantity of book: "<<line<<endl<<endl;
        no++;
    }
    view.close();
    show_librarianmenu();
}

void library::delete_book()
{
    int flag=0;
    string line;
    cout<<"\tEnter name of the book to be deleted: ";
    cin>>book_name;
    ifstream del("BOOKS.txt");
    ofstream temp("temp.txt");
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
        cout<<"\tBook not found"<<endl;
        del.close();
        temp.close();
    }
    else
    {
        temp.close();
        del.close();
        remove("BOOKS.txt");
        rename("temp.txt","BOOKS.txt");
        cout<<"\tBook has been deleted successfully...."<<endl;
    }
    show_librarianmenu();

}

void library::add_book()
{
    int flag=0;
    string line;
    cout<<"\tEnter name of the book: ";
    cin>>book_name;
        //Check if the book is already there
    ifstream check("BOOKS.txt");
    while(getline(check,line))
    {
        if(line==book_name)
        {
            flag=1;
            cout<<"\tBook already exists...."<<endl;
            check.close();
            show_librarianmenu();
        }
    }
    if(flag==0)
    {
        check.close();
    cout<<"\tEnter name of the Author: ";
    cin>>author_name;
    cout<<"\tEnter name of the Publisher: ";
    cin>>publisher;
    cout<<"\tEnter price of the Book: ";
    cin>>price;
    cout<<"\tEnter quantity of the Book: ";
    cin>>quantity;
    ofstream add("BOOKS.txt" , ios::app);
    add<<book_name<<endl;
    add<<author_name<<endl;
    add<<publisher<<endl;
    add<<price<<endl;
    add<<quantity<<endl;
    cout<<"\tBook has been added successfully....."<<endl;
    add.close();
    show_librarianmenu();
    }
    
}


void librarian::search_students()
{

        //This function will show details of book issued to students
        //searching book by name

    int flag=0;
    string line;
    ifstream search("STUDENTS.txt");
    cout<<"\tEnter name of book: ";
    cin>>book_name;
    while(getline(search,line))
    {
        if(line==book_name)
        {
            flag=1;
            getline(search,line);
            cout<<"\tStudent Name:  "<<line<<endl;
            getline(search,line);
            cout<<"\tStudent ID:  "<<line<<endl;
        }
    }
    search.close();
    if(flag==0)
    {
        cout<<"\tThis book is not issued to any student...."<<endl;
    }
    show_librarianmenu();

}

void librarian::view_issuedbooks()
{
    string line;
    ifstream view("STUDENTS.txt");
    while(getline(view,line))
    {
        cout<<"\tBook name: "<<line<<endl;
        getline(view,line);
        cout<<"\tStudent name: "<<line<<endl;
        getline(view,line);
        cout<<"\tStudent ID: "<<line<<endl;
    }   
    view.close();
    show_librarianmenu();

}

    
void librarian::modify_book()
{
    //this function modifies the details of the book
    
    string author;
    string publisher;
    string price;
    string quantity;
    int flag=0;
    string line;
     cout<<"\tEnter name of the book to be modified: ";
    cin>>book_name;
    ifstream modify("BOOKS.txt");
    ofstream temp("temp.txt");
    while(getline(modify,line))
    {
        if(line==book_name)
        {
            flag=1;
            cout<<"\tEnter (modified)name of author: ";
            cin>>author;
            cout<<"\tEnter (modified)name of publisher: ";
            cin>>publisher;
            cout<<"\tEnter (modified)price of book: ";
            cin>>price;
            cout<<"\tEnter (modified)quantity of book: ";
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
        cout<<"\tBook not found"<<endl;
        temp.close();
        modify.close();
        remove("temp.txt");
    }
    else
    {
        temp.close();
        modify.close();
        remove("BOOKS.txt");
        rename("temp.txt","BOOKS.txt");
        cout<<"\tBook has been modified successfully...."<<endl;
    }
     show_librarianmenu();
}



void librarian :: issue_book()
{
    
    int flag=0;
    int conv;
    string line;
    cout<<"\tEnter name of the book: ";
    cin>>book_name;
    cout<<"\tEnter name of student: ";
    cin>>student_name;
    cout<<"\tEnter ID of student: ";
    cin>>student_id;
    ifstream readfile("BOOKS.txt");
    
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
            cout<<"\tBook not found"<<endl;
        }
        else
        {
            conv=stoi(line);
            conv=conv-1;
            readfile.close();
            //ifstream readagain("C://Users//hp//Desktop//OOP project//Console Application//BOOKS.txt"); //changing quantity of books after issuing a book            
            string strReplace = line;
            string strNew =to_string(conv);
            ifstream filein("BOOKS.txt"); //File to read from
            ofstream fileout("fileout.txt"); //Temporary file
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
            remove("BOOKS.txt"); 
            rename("fileout.txt","BOOKS.txt");             
            
            //Writing the name and ID of the student whom book is issued in STUDENTS.txt 

            ofstream student("STUDENTS.txt",ios::app);
            student<<book_name<<endl;
            student<<student_name<<endl;
            student<<student_id<<endl;
            student.close();
            cout<<"\tBook issued successfully....."<<endl;
        }    

            if(conv==0)
            {
                //IF quantity of book becomes zero after issuing last book then the book should be deleted from data
                string line;
                ifstream old("BOOKS.txt");
                ofstream newfile("temp.txt",ios::app);
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
                remove("BOOKS.txt"); 
                rename("temp.txt","BOOKS.txt");
            }
        show_librarianmenu();
}



int main()
{
   menu();
}