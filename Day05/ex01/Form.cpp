#include "Form.hpp"

Form &Form::operator= (const Form &rhs) {
    this->signedIn = rhs.getSignedIn();
    return (*this);
}

Form::Form(const Form &src) :
    name(src.getName()),
    signInGrade(src.getSignInGrade()),
    excecuteGrade(src.getExcecuteGrade()),
    signedIn(src.getSignedIn()) {
    *this = src;
    return ;
}

Form::Form(std::string const name, const int signInGrade, const int excecuteGrade):
    name(name), signInGrade(signInGrade), excecuteGrade(excecuteGrade) {
  if (signInGrade < 1 || excecuteGrade < 1)
    throw Form::GradeTooHighException();
  else if (signInGrade > 150 || excecuteGrade > 150)
    throw Form::GradeTooLowException();
}

void Form::beSigned(Bureaucrat &obj) {
    if (this->signInGrade < obj.getGrade())
      throw Form::GradeTooLowException();
    else
      this->signedIn = true;
}

bool Form::getSignedIn() const {
  return this->signedIn;
}

std::ostream &operator<< (std::ostream &res, const Form &obj) {
  res << obj.getName() << " has signing grade: " << obj.getSignInGrade()
  << " and excecute grade: " << obj.getExcecuteGrade() << std::endl;
  return res;
}

std::string Form::getName() const {
  return this->name;
}

int Form::getSignInGrade() const {
  return this->signInGrade;
}

int Form::getExcecuteGrade() const {
  return this->excecuteGrade;
}

Form::~Form() {}
