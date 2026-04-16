#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

void clear_cin_stream(void)
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void get_grade(int& input_number, const std::string& prompt)
{
    int temp = 0;
    bool valid_input = false;

    std::cout << prompt;

    while (!valid_input)
    {
        if (!(std::cin >> temp))
        {
            std::cout << "Error: Input is not an integer. Try Again.\n";
            std::cin.clear();
            clear_cin_stream();
            continue;
        }
        if (temp > 100 || temp < 0)
        {
            std::cout << "Error: Input is not in range. Try Again.\n";
            clear_cin_stream();
        }
        else
        {
            valid_input = true;
        }
    }

    input_number = temp;
}

// Asks for the student's informations
void readStudentData(std::string& name,
    int& homework,
    int& midterm,
    int& finalExam)
{
    std::cout << "\nName: ";
    std::getline(std::cin, name);

    get_grade(homework, "\nHomework Grade: ");
    get_grade(midterm, "\Midterm Grade: ");
    get_grade(finalExam, "\Final Exam Grade: ");
}

void calculateGrade(const int homework,
    const int midterm,
    const int finalExam,
    float& finalGrade,
    std::string& letterGrade)
{
    finalGrade = (
        0.4 * static_cast<float>(homework)
        + 0.25 * static_cast<float>(midterm)
        + 0.35 * static_cast<float>(finalExam)
        );
    
    std::string grade_array[] = {"F", "F", "F", "F", "F", "E", "D", "C", "B", "A", "A"};

    int index = static_cast<int>(finalGrade) / 10;
    letterGrade = grade_array[index];
}

void printReport(const std::string name,
    const int homework,
    const int midterm,
    const int finalExam,
    const float finalGrade,
    const std::string letterGrade)
{
    // Determine passing status
    std::string passing_status;
    if (letterGrade == "F")
    {
        passing_status = "Failed";
    }
    else if (letterGrade == "D" || letterGrade == "E")
    {
        passing_status = "Passed conditionally";
    }
    else
    {
        passing_status = "Passed";
    }

    // Output the report
    std::cout << "----------------------------------------\n";
    std::cout << "        - Student report card -         \n";
    std::cout << "Name:" << std::right << std::setw(35) << name << std::endl;
    std::cout << "----------------------------------------\n\n";

    std::cout << "Score overview\n";
    std::cout << "----------------------------------------\n";
    std::cout << std::left << std::setw(20) << "Homework grade:" << std::right << std::setw(20) << homework << std::endl;
    std::cout << std::left << std::setw(20) << "Midterm grade:" << std::right << std::setw(20) << midterm << std::endl;
    std::cout << std::left << std::setw(20) << "Final exam grade:" << std::right << std::setw(20) << finalExam << std::endl << std::endl;

    std::cout << std::left << std::setw(20) << "Final grade:" << std::right << std::setw(20) << std::setprecision(2) << std::fixed << finalGrade << std::endl;
    std::cout << std::left << std::setw(20) << "Letter grade:" << std::right << std::setw(20) << letterGrade << std::endl;
    std::cout << std::left << std::setw(20) << "Status:" << std::right << std::setw(20) << passing_status << std::endl;
    std::cout << "----------------------------------------\n";
}

int main()
{
    std::string student_name;
    std::string letter_grade;
    int homework_grade, midterm_grade, finalExam_grade = 0;
    float final_grade = 0.0;

    readStudentData(student_name, homework_grade, midterm_grade, finalExam_grade);
    calculateGrade(homework_grade, midterm_grade, finalExam_grade, final_grade, letter_grade);
    printReport(student_name, homework_grade, midterm_grade, finalExam_grade, final_grade, letter_grade);
}