#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>

using namespace std;

class librarian
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
        librarian();
    }
    else
    {
        cout<<"\n\n\t\tWrong Password.\n\n\t\ttry again.....\n";
        getch();
        system("cls");
        login();
    }
}

void librarian::search_students()
{

        //This function will show details of book issued to students
        //searching book by name
    
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
    if(flag==0)
    {
        cout<<"This book is not issued to any student...."<<endl;
    }
    search.close();

}

void librarian::view_issuedbooks()
{
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

    

int main()
{
    
  librarian ob;
  //Hellow I am in library
  //ob.issue_book();
 // ob.modify_book();
// ob.view_issuedbooks();
//ob.search_students();
}
