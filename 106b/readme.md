## long int v.s. short int

```cpp
int main() {
    long int n = 0;  // big difference between long int and short int
    long int reverse = 0;
    std::cout << "This program reverses the digits in an integer." << std::endl;
    std::cout << "Please enter an integer: "; 
    std::cin >> n; 
    while (n > 0) {
        int remainder = 0; 
        remainder = n % 10;  
        reverse += remainder; 
        reverse *= 10; 
        n /= 10; 
    }; 
    reverse /= 10; 
    std::cout << "The reversed integer is " << reverse << std::endl; 
    return 0;
}
```

The results become like
```
Please enter an integer: 123456789
The reversed integer is 128660861
``` 
When you run the following program 

```cpp
int main() {
    long int n = 0;  // big difference between long int and short int
    long int reverse = 0;
    std::cout << "This program reverses the digits in an integer." << std::endl;
    std::cout << "Please enter an integer: "; 
    std::cin >> n; 
    while (n > 0) {
        int remainder = 0; 
        remainder = n % 10;  
        reverse += remainder; 
        reverse *= 10; 
        n /= 10; 
    }; 
    reverse /= 10; 
    std::cout << "The reversed integer is " << reverse << std::endl; 
    return 0;
}
```

