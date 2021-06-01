#include <iostream>
#include <string>
#include <iterator> //for std::size

void message(std::string);
void changeN(int&);
void printElements(int (&arr)[4]);

struct Something
{
    int value1;
    float value2;
};

struct Other
{
    Something something;
    int othreValue;
};

Other other;

int main()
{
    message("Hello Everyone!");

    //////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////" << '\n';
    std::cout << "References to non-const values" << '\n';
    std::cout << "/////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////
    std::cout << std::endl;

    int value{ 55 }; //normal variable
    int& ref{ value };// reference to variable value
    //In this context, the ampersand does not mean “address of”, it means “reference to”.

    //////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////" << '\n';
    std::cout << "References as aliases" << '\n';
    std::cout << "/////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////
    std::cout << std::endl;
    /*
    References generally act identically to the values they’re referencing. 
    In this sense, a reference acts as an alias for the object being referenced. For example:
    (an alias means: An alias is an alternative name, such as a pseudonym.)
    */
    int x{ 7 };// normal integer
    int& y{ x };// y is a reference to x
    int& z{ y };// z is a reference to x

    /*
    Let’s take a look at references in use:
    */
    int my_value{ 77 };// normal integer
    int& my_ref{ my_value };// reference to variable value

    my_value = 78;// value is now 78
    my_ref = 79;// value is now 79

    std::cout << my_value << '\n';// prints 79
    ++my_ref;
    std::cout << my_value << '\n';// prints 80


    std::cout << &my_value << '\n';
    std::cout << &my_ref << '\n';
    //Just as you would expect if ref is acting as an alias for the value.

    //////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////" << '\n';
    std::cout << "l-values and r-values" << '\n';
    std::cout << "/////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////
    std::cout << std::endl;

    //////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////" << '\n';
    std::cout << "References must be initialized" << '\n';
    std::cout << "/////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////
    std::cout << std::endl;

    //References must be initialized when created:
    int his_value{ 7 };
    int& her_ref{ his_value };// valid reference, initialized to variable value

    //int& our_ref; // invalid, needs to reference something

    /*
    References to non-const values can only be initialized with non-const l-values. 
    They can not be initialized with const l-values or r-values.
    */
    int x_1{ 12 };
    int& x_ref{ x_1 };// okay, x_ref is an non-const l-value

    const int y_1{ 33 };
    //int& y_ref{ y_1 };// not okay, y_1 is a const l-value

    //int& z_ref{ 6 }; // not okay, 6 is an r-value

    //////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////" << '\n';
    std::cout << "References can not be reassigned" << '\n';
    std::cout << "/////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////
    std::cout << std::endl;
    /*
    Once initialized, a reference can not be changed to reference another variable. 
    Consider the following snippet:
    */
    int z_1{ 5 };
    int z_2{ 6 };

    int& z_2_ref{ z_1 };// okay, z_2_ref is now an alias for z_1
    // z_2_ref = z_2;// assigns 6 (the value of z_2) to z_1 -- does NOT change the reference!

    //////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////" << '\n';
    std::cout << "References as function parameters" << '\n';
    std::cout << "/////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////
    std::cout << std::endl; 

    int n{ 5 };

    std::cout << n << '\n';

    changeN(n);// note that this argument does not need to be a reference

    std::cout << n << '\n';

    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Using references to pass C-style arrays to functions" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    std::cout << std::endl;

    int arr[]{ 99, 20, 14, 80 };

    printElements(arr);

    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "References as shortcuts" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    std::cout << std::endl;
    
    // ref_3 can now be used in place of other.something.value1
    int& ref_3{ other.something.value1 };
    float& ref_4{ other.something.value2 };

    //The following two statements are thus identical:
    other.something.value2 = 5;
    ref_4 = 5;

    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "References vs pointers" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    std::cout << std::endl;

    int f_value{ 34 };
    int* const f_ptr{ &f_value };
    int& f_ref{ f_value };

    std::cout << f_value << ' ' << *f_ptr << ' ' << f_ref << '\n';
    /*
    Pointers should only be used in situations where references are not sufficient 
    (such as dynamically allocating memory).
    */

    /////////////////////////////////////////////////////////////////////////////
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    std::cout << "Summary" << '\n';
    std::cout << "/////////////////////////////////////////////////////" << '\n';
    /////////////////////////////////////////////////////////////////////////////
    std::cout << std::endl;

    



    return 0;
}

void message(std::string s)
{
    std::cout << s << '\n';
}

// ref is a reference to the argument passed in, not a copy.
void changeN(int& ref)
{
    ref = 7;
}

// Note: You need to specify the array size in the function declaration.
void printElements(int (&arr)[4])
{
    int length{ static_cast<int>(sizeof(arr) / sizeof(arr[0])) };// we can now do this since the array won't decay

    for(int count{ 0 }; count < length; ++count)
    {
        std::cout << arr[count] << '\n';
    }
}

