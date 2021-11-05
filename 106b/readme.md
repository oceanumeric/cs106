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

## Prime factor

```cpp
// Program to print all prime factors
# include <stdio.h>
# include <math.h>
	
// A function to print all prime factors of a given number n
void primeFactors(int n)
{
	// Print the number of 2s that divide n
	while (n%2 == 0)
	{
		printf("%d ", 2);
		n = n/2;
	}
	
	// n must be odd at this point. So we can skip
	// one element (Note i = i +2)
	for (int i = 3; i <= sqrt(n); i = i+2)
	{
		// While i divides n, print i and divide n
		while (n%i == 0)
		{
			printf("%d ", i);
			n = n/i;
		}
	}
	
	// This condition is to handle the case when n
	// is a prime number greater than 2
	if (n > 2)
		printf ("%d ", n);
}
	
/* Driver program to test above function */
int main()
{
	int n = 315;
	primeFactors(n);
	return 0;
}
```

How does this work? 

 * Steps 1 and 2 take care of composite number and step-3 takes care of prime numbers.
 To prove that the complete algorithm works, we need to prove that steps 1 and 
 2 actually take care of composite numbers. 
 
 * It’s clear that step-1 takes care of even numbers. After step-1, all
 remaining prime factor must be odd (difference of two prime
  factors must be at least 2), this explains why i is incremented by 2.

* Now the main part is, the loop runs till square root of n. To prove that 
this optimization works, let us consider the following property of composite numbers. 
Every composite number has at least one prime factor less than or 
equal to square root of itself.

* This property can be proved using counter statement. Let a and b be two 
factors of n such that a*b = n. If both are greater than √n, then a.b > √n, 
√n, which contradicts the expression “a * b = n”.

* In step-2 of the above algorithm, we run a loop and do following- 
Find the least prime factor i (must be less than √n, )
Remove all occurrences i from n by repeatedly dividing n by i.
Repeat steps a and b for divided n and i = i + 2. The steps a and b are 
repeated till n becomes either 1 or a prime number.