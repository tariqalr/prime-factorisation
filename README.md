# Prime factorisation
A prime factoriser of 64-bit positive integers.

Implemented with trial division, a deterministic form of Miller-Rabin, and Pollard's rho algorithm.

Written in both C and Java.

## Test runs
C

![Test factorisation and factorisation of first 10 000 000 integers](/c/10^7%20c_1.png)
![Test factorisation and factorisation of first 10 000 000 integers](/c/10^7%20c_2.png)

![Test factorisation and factorisation of first 100 000 000 integers](/c/10^8%20c.png)

Java

![Test factorisation and factorisation of first 1 000 000 integers](/java/10^6%20java.png)

![Test factorisation and factorisation of first 10 000 000 integers](/java/10^7%20java.png)

I'm surprised Java is this much slower than C, even with the use of BigInteger. Note that, of my 32GB of RAM, C used ~97% while Java used ~40%.