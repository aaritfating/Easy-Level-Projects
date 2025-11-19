#include<iostream>
#include<string>
#include<cctype>

using namespace std;

void greet();
void instructions();
void questions();

int score=0;

int main(){
    
    greet();
    instructions();
    questions();
    cout<<"your total score is:"<<score<<endl;

    return 0;

}

void greet() {
    cout<<"welcome to this game"<<endl;
    return ;
}

void instructions() {
    cout<<" Instruction"<<endl;
    cout<<" 1. you will be asked few serise of questions "<<endl;
    cout<<" 2. typpe your answer and press enter."<<endl;
    cout<<"3. your score will be shown in last"<<endl;
    cout<<"good luck"<<endl;
    return;
}

int askquestions( const string& question , const string& optionA,
    const string& optionB, const string& optionC , const string& optionD, const char& correctanswer){


    cout<<question<<endl;
    cout<<"a) "<<optionA<<endl
        <<"b) "<<optionB<<endl
        <<"c) "<<optionC<<endl
        <<"d) "<<optionD<<endl;
    
    char answer;
    cin>>answer;
    
    // to normalize input to lower case for case insenstive comparison 
    // a==A i.e a and A will e treated same 
    
    answer= static_cast<char>(tolower(static_cast<unsigned char>(answer)));
    char expected = static_cast<char>(tolower(static_cast<unsigned char> ( correctanswer)));
    
    if (answer == expected){
        cout << " Correct"<< endl;
        return 1;
    } else {
        cout << " Wrong!!!  correct ans is : " << correctanswer<<"."<<endl;
        return 0;
    }
}

void questions(){
    score+= askquestions("What is the capital of France?", "Berlin", "Madrid", "Paris", "Rome", 'c');

    score+= askquestions("Which planet is known as the Red Planet?", "Earth", "Mars", "Jupiter", "Saturn", 'b');
    score+= askquestions("What is the largest ocean on Earth?", "Atlantic Ocean", "Indian Ocean", "Arctic Ocean", "Pacific Ocean", 'd');    
    score+= askquestions("Who wrote 'Romeo and Juliet'?", "Mark Twain", "Charles Dickens", "William Shakespeare", "Jane Austen", 'c');
    return;

}