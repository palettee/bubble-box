#include <string.h>

class MyString {
    private:
     const char* c_string_;
     const MyString& operator=(const MyString& rhs);
    
    public:
     MyString() : c_string_(NULL) {}

     MyString(const char* c_string) : c_string_(NULL) {
        Set(c_string);
     }

     MyString(const MyString& string) : c_string_(NULL) {
        Set(string.c_string_);
     }

     ~MyString() { delete[] c_string_;}

     const char* c_string() const { return c_string_; }
     size_t Length() const { return c_string_ == NULL ? 0 : strlen(c_string_); }
     void Set(const char* c_string);
};