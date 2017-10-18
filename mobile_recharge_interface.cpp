#include<iomanip.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
   void writetofile();
   void mainpage();
   void acc();
   void menu();
   void login();
   void reg();
   void recharge(char);
   void adminp();
   void dtransact(double,double);
   void transact(double,double);
   void success(double,double);
   void success(double,double,char);
   class user
     {   char name[50];
	 double mob,pass;
	 double bal;
       public:
	  char* showname()
	  { return name;}
	  double showmob()
	  { return mob; }
	  double showbal()
	  { return bal; }
	  void getname(char a[])
	  { strcpy(name,a); }
	  void getmob(double a)
	  { mob=a; }
	  void getpass(double a)
	  { pass=a; }
	  void putdata()
	  {
	    cout<<"\n\n\t\tName: ";
	    puts(name);
	    cout.setf(ios::fixed);

	    cout<<"\n\n\t\tMobile No: "<<setprecision(0)<<mob
		<<"\n\n\t\tBalance: "<<bal;
	  }

	  int checkpass(double x)
	  { if(pass==x)
	     return 1;
	    else return 0;
	  }
	  user(double x=50)
	  { bal=x;
	  }
	  void modify();
	  void deleter();
	  void addmoney();
	  void addmoney(double);

     }u1,u2,u3;

     void user::addmoney(double x)
      { bal=bal+x;
	writetofile();
      }
     void user::addmoney()
     { clrscr();
	  fstream f1("recharge.dat",ios::binary|ios::in|ios::out|ios::ate);
	  f1.seekp(0,ios::beg);
	  while(!f1.eof())
	  { f1.read((char*)&u3,sizeof(u3));
	    if(u3.mob==mob)
	    {
	    cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------";
	    cout<<"\n\n\n\t\t\t\tADD MONEY TO WALLET\n ";  getch();
	    cout<<"\n\n\t\tCurrent balance= "<<bal;
	    cout<<"\n\n\t\tEnter money to be added to the wallet: ";
	    long double a,d,p;
	    int check=0,b,c;
	    cin>>a;
	    do
	    { check=0;
	  cout<<"\n\n\t\tEnter mode of payment:(1/2)"
		  <<"\n\t\t1.Credit Card\n\t\t2.Debit Card\n\t";
	      cin>>b;
	      if(b==1)
	      { cout<<"\n\t\tEnter credit card no: ";
		cin>>d;
		cout<<"\n\t\tEnter password: ";
		cin>>p;
	      }
	      else
	      { if(b==2)
		{ cout<<"\n\t\tEnter debit card no: ";
		  cin>>d;
		  cout<<"\n\t\tEnter password: ";
		  cin>>p;
		}
		else
		{ check=1;
		  cout<<"\n\n\n\t\t\t!!Wrong Choice!!\n\n\t\t\tTry Again!";
		  clrscr();
		}
	      }
	    }while(check);

	    f1.seekp((-1*sizeof(u3)),ios::cur);
	    bal=bal+a;
	    f1.write((char*)&u1,sizeof(u1));
	    clrscr();
	    cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------";
	    cout<<"\n\n\n\t\t\t\t!!Money Added!!\n\n\n\t\tNew Balance="<<bal;
	    cout<<"\n\n\t\tPress 1 to go to account and 2 to exit: ";
	    cin>>c;
	    f1.close();
	    if(c==1)
	     acc();
	    else
	     exit(0);
	  }
	 }
     }
     void user::modify()
     { char a[50];
       unsigned long long int x,y;
       int f=0;
       ifstream f1("recharge.dat",ios::binary);
       ofstream f2("temp.dat",ios::binary);
       while(!f1.eof())
       {  clrscr();
	  cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------";
	  f1.read((char*)&u3,sizeof(u3));
	   if(u3.showmob()!=mob)
	    { f2.write((char*)&u3,sizeof(u3));
	    }
	   else
	    { cout<<"\n\n\n\t\t\tCurrent Details :\n\n";
	      u1.putdata();
	      cout<<"\n\n\t\tEnter new name: ";
	      gets(name);
	      cout<<"\n\n\t\tMobile No. can't be changed!";
	   do{ f=0;
	      cout<<"\n\n\t\tEnter new password:(in numbers only) ";
	      cin>>x;
	      cout<<"\n\n\t\tEnter password again: ";
	      cin>>y;
	       if(x==y)
	       { u3.pass=x;
	    pass=x;
		f2.write((char*)&u3,sizeof(u3));
	       }
	       else f=1;
	     }while(f);

	    }
       }
       f1.close();
       f2.close();
       remove("recharge.dat");
       rename("temp.dat","recharge.dat");
       login();
     }
     void user::deleter()
     {
       ifstream f1("recharge.dat",ios::binary);
       ofstream f2("temp.dat",ios::binary);
       while(!f1.eof())
       {  f1.read((char*)&u3,sizeof(u3));
	   if(u3.showmob()!=mob)
	    { f2.write((char*)&u3,sizeof(u3));
	    }
	    else;
       }
       f1.close();
       f2.close();
       remove("recharge.dat");
       rename("temp.dat","recharge.dat");
       menu() ;
     }
   class admin
     { float disc;
       public:
       void changedisc();
       float showdisc()
       {
	 return disc;
       }
       void viewmember();
     }a1;
     void admin::changedisc()
       { clrscr();
	 cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------";
	 cout<<"\n\n\n\t\t\t\tCHANGE DISCOUNT\n";
	 fstream f3("admin.dat",ios::binary|ios::in|ios::out|ios::ate);
	 f3.seekp(0,ios::beg);
	 cout<<"\n\n\t\t\tCurrent Discount is: "<<disc;
	 cout<<"\n\n\t\t\tEnter new discount: ";
	 float x;
	 cin>>x;
	 disc=x;
	 f3.write((char*)&a1,sizeof(a1));
	 f3.close();
	 menu();
       }
     void admin::viewmember()
     { ifstream f1("recharge.dat",ios::binary);
       int i=1;
       clrscr();
       cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------";
       cout<<"\n\n\n\t\t\t\tUSER DETAILS\n";
	while(!f1.eof())
	{ f1.read((char*)&u3,sizeof(u3));
	  if(u3.showmob()!=NULL)
	{
	  cout<<"\n\n\t\tThe deatails of user "<<i<<" are as follows:\n";
	  u3.putdata();    getch();
	 i++;
	}
	 else cout<<"\n\tNo Existing Users. ";   }

       f1.close();
       cout<<"\n\n\n\t\tPress any key to go to menu. ";
       getch();
       menu();
     }
     void mainpage()
     { clrscr();
       cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------";
       cout<<"\n\n\n\n\n\t\t\t\tRECHARGE\n";
       cout<<"\n\n\n\n\t\t\tPress any key to continue\n\n\n\n\n\n\n\n\n";
       cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------";
       getch();
       clrscr();
       menu();
     }
   void menu()
   {
     int c=0;
     do
     { clrscr();
      cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------";
      cout<<"\n\n\n\t\t\t\tMENU\n";
      cout<<"\n\n\t\tSelect the appropriate option: \n\t\t1.Login\n\t\t2.Register"
	   <<"\n\t\t3.Direct recharge\n\t\t4.Admin\n\t\t5.Exit \n\t";
       int a;
       cin>>a;
       switch(a)
       { case 1: login();
		 break;
	 case 2: reg();
		 break;
	 case 3: recharge('d');
		 break;
	 case 4: adminp();
		 break;
	 case 5: exit(0);
		 break;
	 default:cout<<"\n\n\t\tWrong choice entered"; c=1;
       }
     }while(c);

   }
   void adminp()
   { int a;
     int c=0;
     do
     { clrscr();
     cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------";
     cout<<"\n\n\n\t\t\t\tADMINISTRATOR\n";
     cout<<"\n\n\t\tChoose what do you want to do?";
     cout<<"\n\t\t1.Change discount\n\t\t2.View members with accounts";
     cin>>a;

      c=0;
       if(a==1)
       a1.changedisc();
       else if(a==2)
       a1.viewmember();
       else
       { c=1;
	 cout<<"\n\n\t\t!!Wrong Choice!!\n\n\t\tTry Again!";
       }
     }while(c);
   }
   void recharge( char a)
   { clrscr();
     cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------";
     double m;
     double b;
     cout<<"\n\n\n\t\t\t\tRECHARGE SCREEN\n";
     cout<<"\n\n\t\tEnter mobile no. to be recharged: ";
     cin>>m;
     cout<<"\n\n\t\tEnter amount: " ;
     cin>>b;
     clrscr();
     if(a=='d')
     dtransact(m,b);
     else transact(m,b);
   }
   void dtransact(double a,double b)
   { clrscr();
     cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------";
     cout<<"\n\n\n\t\t\t\tTRANSACTION\n";
     int c,d;
     double no,p;
     cout<<"\n\n\t\tEnter mode of payment(1/2):";
     cout<<"\n\n\t\t1.Credit card\n\t2.Debit card\n\t";
     cin>>c;
     switch(c)
     { case 1: cout<<"\n\t\tEnter credit card no: ";
	       cin>>no;
	       cout<<"\n\t\tEnter credit card password: ";
	       cin>>p;
	       break;
       case 2: cout<<"\n\t\tEnter debit card no: ";
	       cin>>no;
	       cout<<"\n\t\tEnter debit card password: ";
	       cin>>p;
	       break;
     }
     success(a,b);
     cout<<"\n\n\t\tTo go to main screen press 1 and to exit press 2: ";
     cin>>d;
     if(d==1)
     { clrscr() ; menu() ;}
     else if(d==2)
     exit(0);
   }
   void reg()
   { clrscr();
     cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------";
     cout<<"\n\n\n\t\t\t\tREGISTER\n";
     char name1[50];
     double p1,p2,m1;
     int f=0;
     cout<<"\n\n\t\tEnter name: ";
     gets(name1);
     cout<<"\n\n\t\tEnter mobile no.: ";
     cin>>m1;
     do
     { f=0;
       cout<<"\n\n\t\tEnter password(only in no.s): ";
       cin>>p1;
       cout<<"\n\n\t\tRe-enter password: ";
       cin>>p2;
       if(p1==p2)
       { u1.getname(name1);
	 u1.getmob(m1);
	 u1.getpass(p1);
	 ofstream f1("recharge.dat",ios::binary|ios::app);
	 f1.write((char*)&u1,sizeof(u1));
	 f1.close();
       }
       else
       { cout<<"\n\tPasswords don't match!!";
	 cout<<"\n\tTry again!!";
	 f=1;
       }
     }while(f);
     clrscr();
     cout<<"\n\n\n\t\t\t!!Account created!!\n\n\n\t\t\tPress any key to continue.";
     getch();
     clrscr();
     acc();
   }
   void login()
   { clrscr();
     double p1,m1;
     int f=0;
     cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------";
     cout<<"\n\n\n\t\t\t\t\tLOGIN\n";
     cout<<"\n\n\t\tEnter mobile no: ";
     cin>>m1;
     int flag=0;
     ifstream f2("recharge.dat",ios::binary);
     while(!f2.eof())
     { f2.read((char*)&u1,sizeof(u1));
       if(u1.showmob()==m1)
	{ flag=1;
	  break;
	}
     }
   if(flag)
    {
     do
     {
       cout<<"\n\n\t\tEnter password: " ;
       cin>>p1;
       if(u1.checkpass(p1))
       acc();
       else
       cout<<"\n\n\t\tWrong password!\n\n\t\tPress 1 to try again and 2 to go back to menu";
       cin>>f;
     }while(f==1);
     menu();
    }
    else cout<<"\n\n\t\tNo Account with the given moile number.\n\n\t\tPress 1 to try again and 2 to go to main page.\n\n\t\tPress any other key to exit. ";
    int flag2;
    cin>>flag2;
    switch(flag2)
    { case 1: login();
	      break;
      case 2: mainpage();
	      break;
      default: exit(0);
    }
   }
   void acc()
   { clrscr();
     cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------";
     cout<<"\n\n\n\t\t\t\tACCOUNT\n";
     u1.putdata();
     int a;
     cout<<"\n\n\t\tWhat do you want to do?";
     cout<<"\n\t\t1.Recharge\n\t\t2.Add money to wallet\n\t\t3.Log out\n\t\t"
	 <<"4.Change account details\n\t\t5.Delete account\n\t";
     cin>>a;
     clrscr();
     switch(a)
     { case 1: recharge('t');
	       break;
       case 2: u1.addmoney();
	       break;
       case 3: menu();
	   break;
       case 4: u1.modify();
	   break;
       case 5: u1.deleter();
	   break;
     }
}

   void transact(double a,double b)
   { clrscr();
     cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------";
     cout<<"\n\n\n\t\t\t\tTRANSACTION\n";
     int c,d;
     double no,p;
     cout<<"\n\n\t\tEnter mode of payment(1/2/3):";
     cout<<"\n\t\t1.Credit card\n\t\t2.Debit card\n\t\t3.Wallet\n\t\t";
     cin>>c;
     switch(c)
     { case 1: cout<<"\n\n\t\tEnter credit card no: ";
	       cin>>no;
	       cout<<"\n\t\tEnter credit card password: ";
	       cin>>p; success(a, b, 'n' );
	       break;
       case 2: cout<<"\n\n\t\tEnter debit card no: ";
	       cin>>no;
	       cout<<"\n\t\tEnter debit card password: ";
	       cin>>p;
	       success(a, b, 'n' ) ;
	       break;
      case 3: if(u1.showbal()<b)
	  { cout<<"\n\n\t\t!!Insufficient Balance!!\n";
	    char dummy;
	    cin>>dummy;
	    u1.addmoney() ;
	  }
	 else success(a, b, 'w' ) ;
	 break;
      default: cout<<"\n\n\t\tWrong Input\n\n\t\try again!! ";
	      transact(a, b) ;
	      break;
     }

     cout<<"\n\n\t\tTo go to main account screen press 1 and to exit press 2: ";
     cin>>d;
     if(d==1)
     { clrscr(); acc(); }
     else if(d==2)
     exit(0);
   }
   void success(double a,double b, char c)
   { clrscr();
     cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------";
     ifstream f5;
     f5.open("admin.dat",ios::binary|ios::beg);
     f5.read((char*)&a1,sizeof(a1));
     double newam;
     if(c=='n')
     newam=(b*a1.showdisc()/100);
     else
     newam=(b*a1.showdisc()/100)-b;
     cout<<"\n\n\n\t\t\t\tTransaction Successful!!\n" ;
     cout<<"\n\n\t\tDiscount of "<<a1.showdisc()<<"% given";
     cout<<"\n\n\t\tRecharge of mobile no. "<<a<<" of Rs "<<b<<" done";
     u1.addmoney(newam) ;
     cout<<"\n\n\t\tNew balance="<<u1.showbal();
     f5.close();
   }
   void success(double a, double b)
   { clrscr();
     cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------";
     cout<<"\n\n\t\tCongrats!! Transaction Successful!!" ;
     cout<<"\n\n\t\tRecharge of mobile no. "<<a<<" of Rs "<<b<<" done";

   }
   void writetofile()
   { fstream f1("recharge.dat",ios::binary|ios::in|ios::out|ios::ate);
     f1.seekp(0,ios::beg);
     while(!f1.eof())
     { f1.read((char*)&u3,sizeof(u3)) ;
       if(u3.showmob()==u1.showmob())
       { f1.seekp(-1*sizeof(u3),ios::cur);
	 f1.write((char*)&u1,sizeof(u1));
	 break;
       }
     }
   }
   void main()
   { clrscr() ;
     mainpage() ;
   }


