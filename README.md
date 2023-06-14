# C++20 Fast Inverse Square Root

This is a modern, safe, C++20 implementation of Quake III Arena's brilliant fast inverse square root algorithm, [explained here](https://betterexplained.com/articles/understanding-quakes-fast-inverse-square-root/). 

While the C implementation uses dangerous pointer arithmetic and older C++ implementations take advantage of unions and type punning, this implementation uses C++20's bit_cast function to safely reinterpret numeric types.
