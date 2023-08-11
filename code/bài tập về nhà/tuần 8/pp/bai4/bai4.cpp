#include <iostream>
#include <string>
using namespace std;

class EmailPasswordValidator {
    string email;
    string password;

public:
    EmailPasswordValidator(string email, string password) {
        this->email = email;
        this->password = password;
    }

    bool validateEmail() {
        try {
            if (email.find_first_of("+-*/") != string::npos) {
                throw "Email contains invalid characters";
            }
            if (email.find('@') == string::npos) {
                throw "Email does not contain '@'";
            }
            if (email.find('.', email.find('@')) == string::npos) {
                throw "Email does not contain '.' after '@'";
            }
        }
        catch (const char* msg) {
            cerr << msg << endl;
            return false;
        }
        return true;
    }

    bool validatePassword() {
        try {
            if (password.length() < 8) {
                throw "Password must be at least 8 characters long";
            }
            bool hasUpperCase = false;
            bool hasLowerCase = false;
            bool hasDigit = false;
            for (char c : password) {
                if (isupper(c)) {
                    hasUpperCase = true;
                }
                else if (islower(c)) {
                    hasLowerCase = true;
                }
                else if (isdigit(c)) {
                    hasDigit = true;
                }
            }
            if (!hasUpperCase || !hasLowerCase || !hasDigit) {
                throw "Password must contain at least one uppercase letter, one lowercase letter, and one digit";
            }
        }
        catch (const char* msg) {
            cerr << msg << endl;
            return false;
        }
        return true;
    }
};

int main()
{
    string email, password;

    cout << "Enter an email address: ";
    cin >> email;

    cout << "Enter a password: ";
    cin >> password;

    EmailPasswordValidator validator(email, password);

    if (validator.validateEmail() && validator.validatePassword()) {
        cout << "Email and password are valid" << endl;
    }

    return 0;
}
