/*
    Date of last update: 13 August 2013
    Developer: Jesse Lloyd
    Description: I always disliked sitting through lectures whilst i was doing my degree so
    i decided to make something will sitting through them the result is this, a simple game of hangman run through console
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

void hangHim(int);
bool NextTurn(char[],string);
void toLowerCase(string&);

string word;
int main()
{
    string input;
    string words[78] = {"abattis","abattises","abattoir","abattoirs","abaxial","abaxile","abbaciesabbacy","abbatial","abbe","abbes","abbess","abbesses","abbey"
                    ,"handinesses","handing","handiwork","handiworks","handkerchief","cardiogram","cardiograms","cardiograph","cardiographic","mudstones","mueddin"
                    ,"brill","brilliance","brilliances","brilliancies","brilliancy","brilliant","brilliantly","brills","brim","brimful","brimfull","brimless","brimmed"
                    ,"cardiographies","cardiographs","cardiography","cardioid","cardioids","cardiologies","cardiologist","handkerchiefs","handle","muds","mudsillmudsills","mudstone"
                    ,"derelict","dereliction","derelictions","derelicts","deride","derided","derider","deriders","derides","deriding","dunk","dunked","dunker","dunkers"
                    ,"mueddins","muenster","muensters","muezzin","muezzins","ostioles","ostium","ostler","ostlers","help","there","carrot","pumpkin","cow","human"};
    srand(time(0));
    int wordSelect = (rand() % 78) + 0;
    word = words[wordSelect];
    char correct[word.size()];
    char guessed[27];

    for(int i=0;i<sizeof(correct);i++)
        correct[i]=0;
    for(int i=0;i<sizeof(guessed);i++)
        guessed[i]=0;

    int guesses=0;

    while(input != "exit")
    {
        system("cls");
        if(NextTurn(correct,word))
        {
            input="exit";
            cout << word<<"\nYou Win >__< \n";
            hangHim(guesses);
        }
        else
            if(guesses==11)
            {
                input="exit";
                cout<<"GameOver!! \nThe word was: "<<word;
            }
            else
            {
                hangHim(guesses);
                for(int i=0;i<word.length();i++)
                {
                    if (correct[i]==0)
                        cout<< "__ ";
                    else
                        cout<<correct[i]<<" ";
                }
                cout << "\nLetters already guessed \n";

                for(int i=0;i<27;i++)
                    if(guessed[i]!=0)
                        cout<<" <"<<guessed[i]<<"> ";

                cin >> input;
                toLowerCase(input);

                for(int i=0;i<=input.length();i++) //writing entered letters into an array and insuring there are no doubles of the same letter
                {
                    for(int l=0;l<27;l++)
                    {
                        if(guessed[l]==0 && guessed[l]!=input[i])
                        {
                            bool exist = false;

                            for(int j=26;j>=0;j--)
                                if(input[i]==guessed[j])
                                    exist=true;

                            if(!exist)
                            {
                                guessed[l] = input[i];
                                l=26;
                            }
                        }
                    }
                    bool rightAnswer=false;
                    for(int j=0;j<=word.length();j++) //check if letter(s) from the users input is contained in the answer(word)
                    {
                        if(input[i]==word[j])
                        {
                            correct[j]=input[i];
                            rightAnswer=true;
                        }
                    }
                    if(!rightAnswer)
                        guesses++;
                }
            }
    }
    return 0;
}
/*
    function toLowerCase converts all user inputted letters to lowercase
*/
void toLowerCase(string &str)
{
	const int length = str.length();
	for(int i=0; i < length; ++i)
	{
		str[i] = tolower(str[i]);
	}
}
/*
    function nextTurn is used to determine if the user has guessed the word,
    true if yes false if no.
*/
bool NextTurn(char guessed[],string word)
{
        int temp=0;
        for(int i=0;i<=word.length();i++)
        {
            if(guessed[i]==word[i] && guessed[i] !=0)
                temp++;
            if(temp==word.length())
               return true;
        }
        return false;

}
/*
    function hangHim is used to draw the hangman graphics, how
    much is drawn is determined by the interger argument
*/
void hangHim(int index)
{
    switch(index)
    {
        case 1:
            cout<<"_____\n";
        break;

        case 2:
            cout<<"   |\n   |\n   |\n   |\n___|___\n";
        break;

        case 3:
            cout<<"    ________\n   |\n   |\n   |\n   |\n___|___\n";
        break;

        case 4:
            cout<<"    ________\n   |/\n   |\n   |\n   |\n___|___\n";
        break;

        case 5:
            cout<<"    ________\n   |/       |\n   |\n   |\n   |\n___|___\n";
        break;

        case 6:
            cout<<"    ________\n   |/       |\n   |        O\n   |\n   |\n___|___\n";
        break;

        case 7:
            cout<<"    ________\n   |/       |\n   |        O\n   |        |\n   |        |\n___|___\n";
        break;

        case 8:
            cout<<"    ________\n   |/       |\n   |        O\n   |        |\n   |        |\n___|___    / \n";
        break;

        case 9:
            cout<<"    ________\n   |/       |\n   |        O\n   |        |\n   |        |\n___|___    / \\ \n";
        break;

        case 10:
            cout<<"    ________\n   |/       |\n   |        O\n   |       /|\n   |        |\n___|___    / \\ \n";
        break;

        case 11:
            cout<<"    ________\n   |/       |\n   |        O\n   |       /|\\ \n   |        |\n___|___    / \\ \n";
        break;

        default:
            cout<<"\n \n \n";
        break;
    }



}


