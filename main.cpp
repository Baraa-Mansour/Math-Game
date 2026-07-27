#include <iostream>

using namespace std;

enum enQuizLvl
{
    EASY = 1,
    MEDIUM = 2,
    HARD = 3,
    MIXLVL = 4
};
enum enOperationType
{
    ADD = 1,
    SUBTRUCT = 2,
    MULTIPLY = 3,
    DIVISION = 4,
    MIXTYPE = 5,
};
enum enResult
{
    PASS = 1,
    FAIL = 0,
};

struct stQuiz
{
    short numberOfQuestion = 0;

    enQuizLvl lvl = EASY;
    enOperationType operationType = ADD;

    short numberOfRightAnswer = 0;
    enResult result = FAIL;
};
struct stQuestion
{
    int number1 = 0;
    int number2 = 0;

    char operation = '+';

    float result = 0;
};

// HELPER
int ReadPositiveNumberInRange(string Message, int From, int To)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0 || Number < From || Number > To);

    return Number;
}
bool ReadYesNo(string Message)
{
    char answer = 'Y';

    cout << Message << endl;
    cin >> answer;

    return tolower(answer) == 'y';
}
int GenerateRandomNumberInRange(int From, int To)
{
    return rand() % (To - From + 1) + From;
}
float GetQuestionAnswer()
{
    float answer = 0;
    cin >> answer;

    return answer;
}

// Enum -> String
string GetStringQuizResult(enResult result)
{
    switch (result)
    {
    case PASS:
        return "PASS";
    case FAIL:
        return "FAIL";
    default:
        return "FAIL";
    }
}
string GetStringQuizLvl(enQuizLvl lvl)
{
    switch (lvl)
    {
    case EASY:
        return "EASY";
    case MEDIUM:
        return "MEDIUM";
    case HARD:
        return "HARD";
    case MIXLVL:
        return "MIX";
    default:
        return "EASY";
    }
}
string GetStringQuizOperatioType(enOperationType type)
{
    switch (type)
    {
    case ADD:
        return "ADD";
        
    case SUBTRUCT:
        return "SUBTRUCT";
        
    case MULTIPLY:
        return "MULTIPLY";
    case DIVISION:
        return "DIVISION";
    case MIXTYPE:
        return "MIX";
    default:
        return "ADD";
    }
}

// screen
void GetScreenColor(bool IsRightAnswer)
{
    IsRightAnswer ? system("color 2F") : system("color 4F");
}
void WrongAnswerScreen(float RightAnswer)
{
    GetScreenColor(false);
    cout << "Wrong Answer :c" << endl;
    cout << "Right Answer is: " << RightAnswer << endl;
}
void RightAnswerScreen()
{
    GetScreenColor(true);
    cout << "Right Answer! :D" << endl;
}

// QUESTION CONFIG
int GetQuestionNumber(enQuizLvl Lvl) // number want to calculate
{
    switch (Lvl)
    {
    case EASY:
        return GenerateRandomNumberInRange(1, 10);
    case MEDIUM:
        return GenerateRandomNumberInRange(11, 100);
    case HARD:
        return GenerateRandomNumberInRange(101, 1000);
    case MIXLVL:
    default:
        return GenerateRandomNumberInRange(1, 10);
        break;
    }
}
char GetRandomQuestionOperation()
{
    const char operations[4] = { '+', '-', '*', '/' };

    return operations[GenerateRandomNumberInRange(0, 3)];
}
char GetQuestionOperation(enOperationType type)
{
    switch (type)
    {
    case ADD:
        return '+';
    case SUBTRUCT:
        return '-';
    case MULTIPLY:
        return '*';
    case DIVISION:
        return '/';
    case MIXTYPE:
    default:
        return GetRandomQuestionOperation();
    }
}
// Question
float GetQuestionResult(stQuestion question)
{
    switch (question.operation)
    {
    case '+':
        return question.number1 + question.number2;
    case '-':
        return question.number1 - question.number2;
    case '*':
        return question.number1 * question.number2;
    case '/':
        return (float)question.number1 / question.number2;
    default:
        return question.number1 + question.number2;
    }
}
stQuestion GenerateQuizQuestion(stQuiz quiz)
{
    stQuestion question;

    question.number1 = GetQuestionNumber(quiz.lvl);
    question.number2 = GetQuestionNumber(quiz.lvl);

    question.operation = GetQuestionOperation(quiz.operationType);

    question.result = GetQuestionResult(question);

    return question;
}
void PrintQuestion(stQuestion question)
{
    cout << endl;
    cout << question.number1 << " " << question.operation << endl;
    cout << question.number2 << endl;
    cout << "_______________" << endl;
}
bool CheckQuestionResult(stQuestion question, float answer)
{
    return question.result == answer;
}

// QUIZ
enQuizLvl ReadQuizLvl()
{
    short quizLvl = ReadPositiveNumberInRange("Enter quiz lvl: [1]EASY [2]Med [3]Hard [4]Mix", 1, 4);

    return (enQuizLvl)quizLvl;
}
enOperationType ReadOperationType()
{
    short operationType = ReadPositiveNumberInRange("Enter operation type: [1]ADD [2]SUB [3]MULTI [4]DIV [5]MIX", 1, 5);

    return (enOperationType)operationType;
}
stQuiz ConfigQuiz()
{
    stQuiz quiz;

    quiz.numberOfQuestion = ReadPositiveNumberInRange("Enter number of quistion", 1, 100);
    quiz.lvl = ReadQuizLvl();
    quiz.operationType = ReadOperationType();

    return quiz;
}
enResult CheckQuizResult(stQuiz quiz)
{
    int halfOfQuestionNumber = ceil((float)quiz.numberOfQuestion / 2);
    return quiz.numberOfRightAnswer >= halfOfQuestionNumber ? PASS : FAIL;
}
void PrintQuizResult(stQuiz quiz)
{
    cout << endl;
    cout << "Total questiion :" << quiz.numberOfQuestion << endl;
    cout << "LVL: " << GetStringQuizLvl(quiz.lvl) << endl;
    cout << "Operation Type: " << GetStringQuizOperatioType(quiz.operationType) << endl;
    cout << "Number of RIGHT answer: " << quiz.numberOfRightAnswer << endl;
    cout << "Number of WRONG answer: " << quiz.numberOfQuestion - quiz.numberOfRightAnswer << endl;
    cout << "__________________________________________" << endl;
}
void StartQuiz(stQuiz& quiz)
{
    for (int i = 1; i <= quiz.numberOfQuestion; i++)
    {
        cout << endl;
        cout << "Question number [" << i << "/" << quiz.numberOfQuestion << "]" << endl;

        stQuestion question = GenerateQuizQuestion(quiz);

        PrintQuestion(question);

        float answer = GetQuestionAnswer();

        if (CheckQuestionResult(question, answer))
        {
            RightAnswerScreen();
            quiz.numberOfRightAnswer++;
        }
        else
        {
            WrongAnswerScreen(question.result);
        }
    }

    quiz.result = CheckQuizResult(quiz);
}

string GetFace(bool IsPass)
{
    return IsPass ? ":D" : ":c";
}
void FinalResultScreen(stQuiz quiz)
{
    bool isPass = CheckQuizResult(quiz) == PASS;
    GetScreenColor(isPass);

    cout << "__________________________________________" << endl;
    cout << " Final Result Is " << GetStringQuizResult(quiz.result) << GetFace(isPass) << endl;
    cout << "__________________________________________" << endl;

    PrintQuizResult(quiz);
}
void ResetScreen()
{
    // Windows-specific console commands
    system("cls");
    system("color 0F");
}

int main()
{
    srand((unsigned)time(NULL));

    bool choice = false;
    do
    {
        ResetScreen();

        stQuiz quiz = ConfigQuiz();

        StartQuiz(quiz);

        FinalResultScreen(quiz);

        choice = ReadYesNo("Play Again? Y Or N?");

    } while (choice);
}
