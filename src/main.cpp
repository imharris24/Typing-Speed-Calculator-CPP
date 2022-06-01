#include<iostream>
#include<string>
#include<chrono>
using namespace std;

class TypingSpeedCalculator {
private:
    string Paragraph;
    string TypedParagraph;
    chrono::steady_clock::time_point StartingTime;
    chrono::steady_clock::time_point EndingTime;
    float TimeTaken;
    float TypingSpeed;
    void StartTime();
    void StopTime();
    void GetTimeTaken();
    void CalculateTypingSpeed();
    void DisplayParagraph();
    void GetTypedParagraph();
public:
    TypingSpeedCalculator();
    void Run();
};
TypingSpeedCalculator::TypingSpeedCalculator() {
    Paragraph = "The Dowry system is evil in society. It has reduced the sacred affair of marriage to a business deal. Brides are treated as a marketable commodity. The parents of the brides are often put under inhuman pressure for a handsome dowry. Sometimes they become pauper to get their daughters married. In many cases, young brides are ruthlessly tortured or pushed to suicide. To eradicate this social evil, a total change in the outlook of society is a must. The woman has to be considered as an equal partner of the man. Widespread education and employment and their rights of property can bring about the right remedy. Legal prohibition of dowry is not enough. Strong social disapproval of dowry is the only guarantee against this evil. Our youth should come forward to generate public awareness against this shameful custom.\n";
    TypedParagraph = "\0";
    TimeTaken = 0;
    TypingSpeed = 0.0f;
}
void TypingSpeedCalculator::DisplayParagraph() {
    cout << Paragraph << "\n";
}
void TypingSpeedCalculator::GetTypedParagraph() {
    getline(cin, this->TypedParagraph);
}
void TypingSpeedCalculator::StartTime() {
    StartingTime = chrono::steady_clock::now();
}
void TypingSpeedCalculator::StopTime() {
    EndingTime = chrono::steady_clock::now();
}
void TypingSpeedCalculator::GetTimeTaken() {
    TimeTaken = chrono::duration_cast<chrono::seconds>(EndingTime - StartingTime).count();
}
void TypingSpeedCalculator::CalculateTypingSpeed() {
    TimeTaken = TimeTaken / 60;
    if (TimeTaken == 0) {
        TimeTake = 1;
    }
    TypingSpeed = (TypedParagraph.length()/5) / TimeTaken;
}
void TypingSpeedCalculator::Run() {
    cout << "Retype the following paragraph and press enter\n";
    DisplayParagraph();
    StartTime();
    GetTypedParagraph();
    StopTime();
    GetTimeTaken();
    CalculateTypingSpeed();
    cout << "\nTyping Speed (WPM) = " << TypingSpeed << "\n";
}

int main() {
    TypingSpeedCalculator Calc;
    char Option = '\0';
    while (true) {
        system("cls");
        cout << "Typing Speed Calculator\n";
        cout << "1. Calculate Typing Speed\n";
        cout << "2. Exit\n";
        cout << "Option: ";
        cin >> Option;
        cin.ignore();
        switch(Option) {
            case '1':
                Calc.Run();
                cout << "\n";
                system("pause");
                break;
            case '2':
                exit(-1);
                break;
            default:
                break;
        }
    }
    return 0;
}
