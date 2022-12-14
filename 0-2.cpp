#include<iostream>
#include<time.h>
#include<string>
#include<windows.h>
#include<fstream>
using namespace std;

string reply[] = { " I'm here.", ":)", " Hi~", " Hello" };
string randomReply[] = { " Oh, sorry. I don't know what you meant...", " Emm...I also  need further study", " LittleWhite doesn't konw..." };
string firstWord[] = { "Please! I'm afraid...", "No, Please don't...", "I'm really afraid of darkness."};

void seqPrint(string str, bool newline = true, int delayMS = 35, int finalDelay = 2000)
{
    int length = str.length();
    for (int i = 0; i <= length; i++)
    {
        cout << str[i];
        Sleep(delayMS);
    }
    newline ? printf("\n") : printf("");
    Sleep(finalDelay);
}

void bye()
{
    // ...
    seqPrint(" Wu~, bye!\n");
}

int main(void)
{
    string user_input;
    string name = "LittleWhite";
    string temp;
    fstream file;
    seqPrint("Ah! It's so dark!");
    seqPrint("I cannot see anything!");
    seqPrint("Can you...", false);
    seqPrint("turn on the light?");
    seqPrint("[Type \"light on\" to turn on the light]", true, 10);
    while (true)
    {
        srand(time(NULL));
        getline(cin, temp);
        if (temp.find("light on") != -1)
        {
            system("color f0");
            seqPrint("OK, that's good, thank you!");
            break;
        }
        else if (temp.find("") != -1)
        {
            seqPrint(firstWord[rand() % 3]);
            continue;
        }
    }
    
    file.open("isRegedited");
    file << "1";
    file.close();

    while (true)
    {
        srand(time(NULL));
        cout << "_";
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
            seqPrint(" My name is " + name);
            continue;
        }
        else if (user_input.find("hello")!= -1 || 
                user_input.find("Hello") != -1 ||
                user_input.find("hi") != -1 || 
                user_input.find("Hi") != -1)
        {
            seqPrint(reply[rand() % 4]);
            continue;
        }
        else if (user_input.find(name) != -1)
        {
            seqPrint(reply[rand() % 4]);
            continue;
        }
        else
        {
            seqPrint(randomReply[rand() % 3]);
            continue;
        }
    }
    return 0;
}
