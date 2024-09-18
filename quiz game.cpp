#include <iostream>
#include <iomanip>
#include <ctime>
#include <limits>
#include <map>
#include <string>
#include <chrono>  

using namespace std;
using namespace std::chrono;

int playQuiz(void); 

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    int finalResult = 0;
    char playAgain;

    play:  
    finalResult = playQuiz();
    cout << "Your score is " << finalResult << "/10" << endl;

    if (finalResult >= 6) {
        cout << "You passed!" << endl;
    } else {
        cout << "You failed." << endl;
    }

    cout << "Do you want to play QUIZ again (y/n)? ";
    cin >> playAgain;

    if (playAgain == 'y' || playAgain == 'Y') {
        goto play;  
    } else {
        cout << "Thank you for playing the quiz!" << endl;
    }

    return 0;
}

int playQuiz() {
    char option;
    int score = 0;
    const int questionTimeLimit = 10;  

    cout << "---------- Welcome to C++ Quiz Game -------------" << endl;
    cout << "Step 1: The quiz contains 10 questions about C++." << endl;
    cout << "Step 2: You will get 1 point for each correct answer." << endl;
    cout << "Step 3: No negative marking." << endl;
    cout << "Step 4: You have " << questionTimeLimit << " seconds per question." << endl;
    cout << "Step 5: Press 's' to start the quiz." << endl;
    cin >> option;

    if (option == 's' || option == 'S') {
        
        string questions[10] = {
            "Q1. What is the correct syntax to output 'Hello World' in C++?\n(a) cout << 'Hello World'; (b) echo 'Hello World'; (c) print('Hello World'); (d) printf('Hello World');",
            "Q2. Which header file is required to use input/output in C++?\n(a) iostream (b) stdio.h (c) conio.h (d) math.h",
            "Q3. What does 'cout' stand for in C++?\n(a) Character Output (b) Console Output (c) Comment Output (d) Color Output",
            "Q4. Which of the following is used for comments in C++?\n(a) // (b) /* */ (c) # (d) Both a and b",
            "Q5. What is the default access specifier for class members in C++?\n(a) private (b) public (c) protected (d) none",
            "Q6. What is the purpose of the 'namespace' keyword in C++?\n(a) To define a new data type (b) To create a new scope (c) To include external libraries (d) To create a new class",
            "Q7. How do you declare a pointer variable in C++?\n(a) int ptr; (b) int ptr; (c) int ptr; (d) pointer int;",
            "Q8. Which function is the entry point of a C++ program?\n(a) start() (b) main() (c) init() (d) execute()",
            "Q9. How do you declare a constant variable in C++?\n(a) const int x = 10; (b) int const x = 10; (c) #define x 10 (d) Both a and b",
            "Q10. What is the purpose of the 'virtual' keyword in C++?\n(a) To allow method overriding in derived classes (b) To create a new thread (c) To declare a constant variable (d) To manage memory"
        };

        char correctAnswers[10] = {'a', 'a', 'b', 'd', 'a', 'b', 'a', 'b', 'd', 'a'};

        
        for (int i = 0; i < 10; i++) {
            cout << questions[i] << endl;
            auto start = steady_clock::now(); 

            cin >> option;
            auto end = steady_clock::now();  

            duration<double> elapsedSeconds = end - start;

            if (elapsedSeconds.count() > questionTimeLimit) {
                cout << "Time's up for this question!" << endl;
            } else {
                if (option == correctAnswers[i] || option == toupper(correctAnswers[i])) {
                    score++;
                }
            }
        }
    } else {
        cout << "Invalid input. Please press 's' to start." << endl;
    }

    return score;  
}