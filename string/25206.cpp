#include <iostream>
#include <string>
using namespace std;

int main() {
    string subject, grade;
    float credit;
    float credit_sum = 0.0;
    float score = 0.0;
    for(int i = 0; i < 20; i++){
        cin >> subject;
        cin >> credit;
        cin >> grade;
        if(grade == "A+") score += (4.5 * credit);
        if(grade == "A0") score += (4.0 * credit);
        if(grade == "B+") score += (3.5 * credit);
        if(grade == "B0") score += (3.0 * credit);
        if(grade == "C+") score += (2.5 * credit);
        if(grade == "C0") score += (2.0 * credit);
        if(grade == "D+") score += (1.5 * credit);
        if(grade == "D0") score += (1.0 * credit);
        if(grade == "F") score += (0.0 * credit);
        if(grade == "P"){
            continue;
        }
        credit_sum += credit;
    }
    score = score / credit_sum;
    cout << fixed;
    cout.precision(6);
    cout << score;

    return 0;
}