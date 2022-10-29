#include<iostream>
#include<time.h>
using namespace std;

string reply[] = { " I'm here.", ":)", " Hi", " Hello" };
string randomReply[] = { " Oh, sorry. I don't know what you meant...", " Emm...I also  need further study", " LittleWhite doesn't konw..." };

void bye()
{
    // ...
    cout << " Wu~, bye!\n" << endl;
}

int main(void)
{
    string user_input;
    string name = "LittleWhite";
    string temp;
    cout << " Hello! My name is " << name << endl;

    while (true)
    {
        srand(time(NULL));
        cout << "___";
        getline(cin, user_input);
	    if (user_input == "")
        {
            continue;
        }
        if (user_input == "bye")
        {
            bye();
            break;
        }
        else if (user_input.find("name") != -1 || user_input.find("who") != -1)
        {
            cout << " My name is " << name << ". " << name << " is me." << endl;
            continue;
        }
        else if (user_input.find("hello")!= -1 || 
                user_input.find("Hello") != -1 ||
                user_input.find("hi") != -1 || 
                user_input.find("Hi") != -1)
        {
            cout << reply[rand() % 4] << endl;
            continue;
        }
        else if (user_input.find(name) != -1)
        {
            cout << reply[rand() % 4] << endl;
            continue;
        }
        else
        {
            cout << randomReply[rand() % 3] << endl;
            continue;
        }
    }
    return 0;
}
