#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class Student
{
    public:
        Student()
        {
        first_name = "N/A";
        last_name = "N/A";
        gpa = 0.0;
        graduation_year = 0;
        graduation_semester = "N/A";
        enrolled_year = 0;
        enrolled_semester = "N/A";
        is_undergrad = true;
        };
        ~Student()
        {

        }
        void setFirstName(const string& first) { first_name = first; }
        void setLastName(const string& last) { last_name = last; }
        void setGPA(double gpa) { this->gpa = gpa; }
        void setGraduationYear(int year) { graduation_year = year; }
        void setGraduationSemester(const string& semester) { graduation_semester = semester; }
        void setEnrolledYear(int year) { enrolled_year = year; }
        void setEnrolledSemester(const string& semester) { enrolled_semester = semester; }
        void setIsUndergrad(bool is_undergrad) { this->is_undergrad = is_undergrad; }

        string getFirstName() const { return first_name; }
        string getLastName() const { return last_name; }
        double getGPA() const { return gpa; }
        int getGraduationYear() const { return graduation_year; }
        string getGraduationSemester() const { return graduation_semester; }
        int getEnrolledYear() const { return enrolled_year; }
        string getEnrolledSemester() const { return enrolled_semester; }
        bool isUndergrad() const { return is_undergrad; }

    protected:
        string first_name;
        string last_name;
        double gpa;
        int graduation_year;
        string graduation_semester;
        int enrolled_year;
        string enrolled_semester;
        bool is_undergrad;

};

class Art_Student : public Student
{
    public:
        Art_Student() {
            art_emphasis = "N/A";
        }

        void setArtEmphasis(const string& emphasis) { art_emphasis = emphasis; }
        string getArtEmphasis() const { return art_emphasis; }

    private:
        string art_emphasis;
};


class Physics_Student : public Student
{
    public:
        Physics_Student() 
        {
            concentration = "N/A";
        }   

        void setConcentration(const string& concentration) { this->concentration = concentration; }
        string getConcentration() const { return concentration; }

    private:
        string concentration;
};



int main()
{
    vector<Art_Student*> art_students;
    vector<Physics_Student*> physics_students;

    for (int i = 0; i < 5; ++i) {
        art_students.push_back(new Art_Student());
        art_students[i]->setFirstName("Art Student " + to_string(i + 1));
        art_students[i]->setLastName("Last Name");
        art_students[i]->setGPA(3.5 + i * 0.1);
        art_students[i]->setArtEmphasis("Art Studio");
    }

    for (int i = 0; i < 5; ++i) 
    {
        physics_students.push_back(new Physics_Student());
        physics_students[i]->setFirstName("Physics Student " + to_string(i + 1));
        physics_students[i]->setLastName("Last Name");
        physics_students[i]->setGPA(3.8 - i * 0.1);
        physics_students[i]->setConcentration("Biophysics");
    }

    ofstream outfile("student_info.txt");
    if (!outfile.is_open()) 
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    for (Art_Student* student : art_students) 
    {
        outfile << "Art Student:\n"
        << "  Name: " << student->getFirstName() << " " << student->getLastName() << endl
        << "  GPA: " << student->getGPA() << endl
        << "  Art Emphasis: " << student->getArtEmphasis() << endl;
        outfile << endl;
    }

    for (Physics_Student* student : physics_students) {
        outfile << "Physics Student:\n"
        << "  Name: " << student->getFirstName() << " " << student->getLastName() << endl
        << "  GPA: " << student->getGPA() << endl
        << "  Concentration: " << student->getConcentration() << endl;
        outfile << endl;
    }

    outfile.close();
    for (Art_Student* student : art_students) {
        delete student;
    }
    for (Physics_Student* student : physics_students) {
        delete student;
    }

    return 0;
}
