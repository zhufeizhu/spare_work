#ifndef _COURSE_HPP_
#define _COURSE_HPP_

#include <iostream>
#include <string>

#include "list.hpp"

namespace demo{

class Student{
    public:
        Student() = delete;
        Student(std::string name, std::string id);
        Student(std::string name, std::string id, int score);
        Student(const Student &stu) = default;
        Student& operator=(const Student &rhs);
        inline int getScore(){
            return this->score_;
        }
        inline void setScore(int score){
            this->score_ = score;
        }

        inline std::string getId(){
            return this->id_;
        }
        inline void setId(std::string id){
            this->id_ = id;
        }

        inline std::string getName(){
            return this->name_;
        }
        inline void setName(std::string name){
            this->name_ = name;
        }

    private:
        std::string id_;
        std::string name_;
        int score_;
};

class Course{
    public:
        Course(std::string id, std::string name);
        Course(const Course &course);
        inline int getStudenAmount(){
            return this->student_amount_;
        }
        inline void setStudentAmount(int student_amount){
            this->student_amount_ = student_amount;
        }

        inline std::string getId(){
            return this->id_;
        }
        inline void setId(std::string id){
            this->id_ = id;
        }

        inline std::string getName(){
            return this->name_;
        }
        inline void setName(std::string name){
            this->name_ = name;
        }

        void insertStudent(const Student &student);
        void removeStudentById(std::string id);
        void removeStudentByName(std::string name);
        float getAverageScore();
    private:
        std::string id_;
        std::string name_;
        int student_amount_;
        mList<Student> *student_list_;
};

};

#endif