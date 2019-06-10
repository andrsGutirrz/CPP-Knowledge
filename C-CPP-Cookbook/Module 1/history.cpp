
/*

The latest version of this topic can be found at Welcome Back to C++ (Modern C++).

C++ is one of the most widely used programming languages in the world. Well-written C++ programs are 
fast and efficient. The language is more flexible than other languages because you can use it to create a 
wide range of apps—from fun and exciting games, to high-performance scientific software, to device drivers, 
embedded programs, and Windows client apps. For more than 20 years, C++ has been used to solve problems like these 
and many others. What you might not know is that an increasing number of C++ programmers have folded up the dowdy C-style 
programming of yesterday and have donned modern C++ instead.

One of the original requirements for C++ was backward compatibility with the C language. 
Since then, C++ has evolved through several iterations—C with Classes, then the original C++ 
language specification, and then the many subsequent enhancements. Because of this heritage, 
C++ is often referred to as a multi-paradigm programming language. In C++, you can do purely procedural 
C-style programming that involves raw pointers, arrays, null-terminated character strings, custom data structures, 
and other features that may enable great performance but can also spawn bugs and complexity. Because C-style programming is 
fraught with perils like these, one of the founding goals for C++ was to make programs both type-safe and easier to write, extend, 
and maintain. Early on, C++ embraced programming paradigms such as object-oriented programming. Over the years, features 
have been added to the language, together with highly-tested standard libraries of data structures and algorithms. 
It's these additions that have made the modern C++ style possible.

Modern C++ emphasizes:

Stack-based scope instead of heap or static global scope.

Auto type inference instead of explicit type names.

Smart pointers instead of raw pointers.

std::string and std::wstring types (see <string>) instead of raw char[] arrays.

Standard template library (STL) containers like vector, list, and map instead 
of raw arrays or custom containers. See <vector>, <list>, and <map>.

STL algorithms instead of manually coded ones.

Exceptions, to report and handle error conditions.

Lock-free inter-thread communication using STL std::atomic<> (see <atomic>) instead 
of other inter-thread communication mechanisms.

Inline lambda functions instead of small functions implemented separately.

Range-based for loops to write more robust loops that work with arrays, STL containers, 
and Windows Runtime collections in the form for ( for-range-declaration : expression ). 
This is part of the Core Language support. For more information, see Range-based for Statement (C++).

was renamed to "C++" (++ being the increment operator in C)
We use C++ in sketch for Arduino

*/