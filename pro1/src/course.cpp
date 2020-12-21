#include "course.hpp"

namespace demo{
Course::Course(std::string id, std::string name):id_(id),name_(name){
    student_list_ = new mList<Student>();
}

Course::Course(const Course &course){
    this->id_ = std::string(course.id_);
    this->name_ = std::string(course.name_);
    this->student_amount_ = course.student_amount_;
    this->student_list_ = new mList<Student>(*(course.student_list_));
}

void Course::insertStudent(const Student &student){
    student_list_->emplace_back(student);
    this->student_amount_++;
}

void Course::removeStudentById(std::string id){
    //TODO
}

void Course::removeStudentByName(std::string name){
    //TODO
}

float Course::getAverageScore(){
    int len = student_list_->length();
    int total_score = 0;
    for(int i = 0; i < len; i++){
        total_score += (*student_list_)[i].getScore();
    }
    return total_score/student_amount_;
}

Student::Student(std::string name, std::string id):name_(name),id_(id){

}

Student::Student(std::string name, std::string id, int score){
    Student(name,id);
    this->score_ = score;
}



}