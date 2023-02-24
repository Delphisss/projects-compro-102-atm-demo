#include <iostream>
#include <conio.h> // for getch() function
#include <iomanip>
#include <windows.h> //sleep

using namespace std;
//game
enum eDirection { STOP=0,LEFT,RIGHT,UP,DOWN};
eDirection dira;
bool gameOver;
void setup();
void Draw();
void Input();
void Logic();
void Logic2();
const int width=20;
const int height=20;
int x,y, fruitX, fruitY,score;
int tailx[100],taily[100];
int ntail;
int game()
{
	char ch;
	cout<<"\n\t---------------------------------------\n";
	cout<<"\t\t:Snake game in C++:\n";
	cout<<"\t---------------------------------------\n\n";
	cout<<"Please Enter Game Mod which you Play:\n\n";
	cout<<"Play Hard Mode for Press : H\n\n";
	cout<<"Play Easy for Press: S\n\n";
	cin>>ch;
	switch (ch)
	{
	case 'S': 
		setup();
		while(!gameOver)
		{
			Draw();
			Input();
			Logic();
			Sleep(30);
		}
		break;
	case 'H':
		setup();
		while(!gameOver)
		{
			Draw();
			Input();
			Logic2();
			Sleep(30);
		}

		break;
	default:
		cout<<"Invalid!! Please Select Given Options.";
		break;
	}
	
	getch();
	return 0;
}
void setup()
{
	gameOver=false;
	dira=STOP;
	x=width/2;
	y=height/2;
	fruitX=rand()%width;
	fruitY=rand()%height;
	score=0;
}
void Draw()
{
	system("cls");
	cout<<"\n\t\t      :SNAKE GAME:\n";
	cout<<"\t\t";
	for(int i=0;i<width-8;i++)
	{
		cout<<"||";
	}
	cout<<endl;
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			if(j==0)
			{
				cout<<"\t\t||";
			}
			if(i==y&&j==x)
				cout<<"O";
			else if(i==fruitY&&j==fruitX)
				cout<<"*";
			else
			{
				bool print=false;
				for(int k=0;k<ntail;k++)
				{
					if(tailx[k]==j&& taily[k]==i)
					{
						cout<<"o";
						print=true;
					}
				} 
				if(!print)
				{
					cout<<" ";
				}
			}
			if (j==width-1)
				cout<<"||";
		}
		cout<<endl;
	}
	cout<<"\t\t";
	for(int i=0;i<width-8;i++)
	{
		cout<<"||";
	}
	cout<<endl;
	cout<<"\t\t\tScore: "<<score<<endl;
}
void Input()
{
	if(_kbhit())
	{
		switch(_getch())
		{
		case 'a':
			dira=LEFT;
			break;
		case 'd':
			dira=RIGHT;
			break;
		case 'w':
			dira=UP;
			break;
		case 's':
			dira=DOWN;
			break;
		case 'x':
			gameOver=true;
			break;
		}
	}
}
//simple mode
void Logic()
{
	int prevX=tailx[0];
	int prevY=taily[0];
	int prev2X,prev2Y;
	tailx[0]=x;
	taily[0]=y;
	for(int i=1;i<ntail;i++)
	{
		prev2X=tailx[i];
		prev2Y=taily[i];
		tailx[i]=prevX;
		taily[i]=prevY;
		prevX=prev2X;
		prevY=prev2Y;
	}
	switch (dira)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	if(x>=width) x=0; else if(x<0)x=width-1;
	if(y>=height) y=0; else if(y<0)y=height-1;
	for(int i=0;i<ntail;i++)
	{
		if(tailx[i]==x && taily[i]==y)
		{
			gameOver=true;
		}
	}
	if(x==fruitX&&y==fruitY)
	{
		score+=10;
		fruitX=rand()%width;
		fruitY=rand()%height;
		ntail++;
	}

}
//hard mod
void Logic2()
{
	int prevX=tailx[0];
	int prevY=taily[0];
	int prev2X,prev2Y;
	tailx[0]=x;
	taily[0]=y;
	for(int i=1;i<ntail;i++)
	{
		prev2X=tailx[i];
		prev2Y=taily[i];
		tailx[i]=prevX;
		taily[i]=prevY;
		prevX=prev2X;
		prevY=prev2Y;
	}
	switch (dira)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	if(x>width||x<0||y>height||y<0)
	{
		gameOver=true;
	}
	if(x>=width) x=0; else if(x<0)x=width-1;
	if(y>=height) y=0; else if(y<0)y=height-1;
	for(int i=0;i<ntail;i++)
	{
		if(tailx[i]==x && taily[i]==y)
		{
			gameOver=true;
		}
	}
	if(x==fruitX&&y==fruitY)
	{
		score+=10;
		fruitX=rand()%width;
		fruitY=rand()%height;
		ntail++;
	}

}



//
int id, password; //login
char ch; //login && ATM
int choice = 1; //ATM
float balance = 2000; //ลบออก

//higlight atm menu
void highlight_ATM_MENU(int index, bool selected) { 
    int l = 0 ;
    
    if (selected) {
        cout << "\033[1;7m"; // set background and foreground color to white and black
    }
    cout << index << ". ";

    // print the option label
    switch (index) {
        case 1:
            l = 29 ;
            cout << "Deposit";
            break;
        case 2:
            l = 28 ;
            cout << "Withdraw";
            break;
        case 3:
            l = 21 ;
            cout << "Balance Inquiry";
            break;
        case 4:
            l = 32 ;
            cout << "Exit";
            break;
        case 5:
            l = 32 ;
            cout << "Game" ;
        default:
            break;
    }

    cout << "\033[0m"  << setw(l)<<" | \n"; // window
}

//Login failed
int Login_failed (){
    system("cls");
    cout << "+-------------------------------------+" ;
    cout << "\nLogin failed. Incorrect ID or password. \n" ;
    cout << "+-------------------------------------+\n" ;
    cout << setw(28) <<"Please try again." ;
    cout << "\n+-------------------------------------+\n" ;
}

//Login ATM
int login(){
    //int id, password;
    //char ch;
    // Display login window frame
    system("cls");
    cout << "+-------------------------------------+\n" ;
    cout << "|              Login ATM              |\n" ;
    cout << "+-------------------------------------+\n" ;

    // Display prompts for ID and password
    cout << "\nEnter your ID: ";
    cin >> id;
    
    cout << "Enter your password: ";

    // Read in password character by character without displaying on screen
    password = 0;
    while ((ch = _getch()) != '\r') {  // Stop reading when user presses Enter key
        if (ch == '\b') {  // Handle backspace character
            if (password > 0) {
                password /= 10;
                cout << "\b \b";  // Move cursor back and overwrite character with space
            }
        } else if (isdigit(ch)) {  // Handle numeric characters
            password = password * 10 + (ch - '0');
            cout << "*";
        }
    } 
}


int main(){
    //login
    login();
    if (id-650610000 == password ) {
        system("cls");
        cout << "+-------------------------------------+\n";
        cout << "|          Login successful!          |\n";
        cout << "+-------------------------------------+\n";
        Sleep(1000); // Wait for 1000 milliseconds
        //ATM
        do {
            system("cls"); // clear the console
            cout << "+-------------------------------------+\n";
            cout << "|              ATM Menu               |\n"; 
            cout << "+-------------------------------------+\n";
            // display the menu options
            for (int i = 1; i <= 5; i++) {
            cout << "| ";
            highlight_ATM_MENU(i, i == choice);
            }
            
            cout << "|                                     |\n";
            cout << "+-------------------------------------+\n";

            ch = getch(); // wait for a key press

            // update the choice variable based on the arrow key input
            if (ch == 72 && choice > 1) { // up arrow key
                choice--;
            }
            else if (ch == 80 && choice < 5) { // down arrow key
                choice++;
            }
            } while (ch != 13); // enter key

                // display the selected option
                switch (choice) {
                    case 1:
                        // Deposit
                        system("cls"); // clear the console
                        cout << "+-------------------------------------+\n";
                        cout << "|               Deposit               |\n"; 
                        cout << "+-------------------------------------+\n";
                        double depositAmount;
                        cout << "Enter the amount to deposit: ";
                        cin >> depositAmount;
                                
                        if (depositAmount > 0) {
                            balance += depositAmount;
                            system("cls"); // clear the console
                            cout << "+-------------------------------------+\n";
                            cout << "|               Deposit               |\n"; 
                            cout << "+-------------------------------------+\n";
                            cout << "Deposit successful!"<< "\nYour new balance is: $" << fixed << setprecision(2) << balance << "\n";
                            Sleep(2000); // Wait for 1000 milliseconds
                            system("cls"); // clear the console
                            cout << "+-------------------------------------+\n";
                            cout << "|               Deposit               |\n"; 
                            cout << "+-------------------------------------+\n";
                            cout << "Thank you for using this ATM. Goodbye!\n";
                            Sleep(2000); // Wait for 1000 milliseconds
                            main();

                         } else {
                                    cout << "Invalid deposit amount.\n";
                                    Sleep(2000); // Wait for 1000 milliseconds
                                    main();
                                }
                                break;
                    
                    case 2:
                        // Withdraw
                        system("cls");
                        cout << "+-------------------------------------+\n";
                        cout << "|               Withdraw              |\n"; 
                        cout << "+-------------------------------------+\n";
                        double withdrawAmount;
                        cout << "Enter the amount to withdraw: ";
                        cin >> withdrawAmount;
                        if (withdrawAmount <= balance && withdrawAmount > 0) {
                                balance -= withdrawAmount;
                                system("cls"); // clear the console
                                cout << "+-------------------------------------+\n";
                                cout << "|               Withdraw              |\n"; 
                                cout << "+-------------------------------------+\n";
                                cout << "Withdrawal successful!" << "\nYour new balance is: $" << fixed << setprecision(2) << balance << "\n";
                                Sleep(2000); // Wait for 1000 milliseconds
                                system("cls"); // clear the console
                                cout << "+-------------------------------------+\n";
                                cout << "|               Withdraw              |\n"; 
                                cout << "+-------------------------------------+\n";
                                cout << "Thank you for using this ATM. Goodbye!\n";
                                Sleep(2000); // Wait for 1000 milliseconds
                                main();
                        } else {
                                    cout << "Invalid withdrawal amount.\n";
                                    Sleep(2000); // Wait for 1000 milliseconds
                                    main();
                                }
                                break;
                    
                    case 3:
                        // Balance Inquiry
                        system("cls");
                        cout << "+-------------------------------------+\n";
                        cout << "|           Balance Inquiry           |\n"; 
                        cout << "+-------------------------------------+\n";
                        cout << "Your current balance is: $" << fixed << setprecision(2) << balance << "\n";
                        Sleep(2000); // Wait for 1000 milliseconds
                        system("cls"); // clear the console
                        cout << "+-------------------------------------+\n";
                        cout << "|           Balance Inquiry           |\n"; 
                        cout << "+-------------------------------------+\n";
                        cout << "Thank you for using this ATM. Goodbye!\n";
                        Sleep(2000); // Wait for 1000 milliseconds
                        main();
                        break;

                    case 4:
                        // Exit
                        system("cls"); // clear the console
                        cout << "+-------------------------------------+\n";
                        cout << "|                 Exit                |\n"; 
                        cout << "+-------------------------------------+\n";
                        cout << "Thank you for using this ATM. Goodbye!\n";
                        Sleep(2000); // Wait for 1000 milliseconds
                        main();// Return to login page 
                        break;

                    case 5:
                        cout << "game" ;
                        system("cls"); // clear the console
                        game();
                            if(gameOver=true)
                                main();
                        break;
                        }

                        return 0; 
    } else {
        Login_failed();
        Sleep(1000); // Wait for 1000 milliseconds
        main();
                 
    }
    
}
