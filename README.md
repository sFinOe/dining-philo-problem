
![Logo](https://i.ibb.co/gwLXGPK/Dining-Philosophers-Problem.png)


# Dining Philosophers Problem

The Dining Philosophers problem is a classic problem in computer science that illustrates the challenges of resource allocation and synchronization. It was first introduced by Edsger Dijkstra in 1965.

In this project, we present a solution to the Dining Philosophers problem using the [pthreads](https://en.wikipedia.org/wiki/POSIX_Threads) library in C.

- [The Linux Programming Interface](http://man7.org/tlpi/) by Michael Kerrisk
- [Writing Your Own Shell](https://brennan.io/2015/01/16/write-a-shell-in-c/) by Brennan D Baraban


# Problem Statement

Five philosophers are seated around a round table. There are five chopsticks placed between each pair of philosophers, and each philosopher has a plate of rice. In order to eat, a philosopher must pick up the chopsticks to their left and right. However, if a philosopher picks up a chopstick and the chopstick to their right is already being held by another philosopher, they must put down the chopstick and wait for the other philosopher to finish eating.

The goal of the problem is to devise a strategy for the philosophers to eat without getting stuck in a deadlock or a livelock.


# Solution

Our solution to the Dining Philosophers problem uses mutex locks and condition variables to synchronize the actions of the philosophers. We use a "chopstick" structure to represent each chopstick, and we use a mutex lock to protect each chopstick. Each philosopher is represented by a separate pthread, and the pthreads communicate with each other using condition variables.

# How to Run

- Clone or download the repository to your local machine.
- Navigate to the src directory.
- Build the project with make.
- Run the program with `./philo`.

# Requirements
- Linux, Macos, Windows
- Clang, GCC (C compailer)# References

- [What is Bash ? ](https://opensource.com/resources/what-bash)
- [The Dining Philosophers Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem) on Wikipedia
- [Dining Philosophers Problem](https://www.geeksforgeeks.org/dining-philosophers-problem-using-monitors-java/) on Geeks for Geeks
- [The Dining Philosophers Problem (1995)](https://www.cs.indiana.edu/~duc/csci5221/lectures/dp.pdf) by Edsger Dijkstra
# Usage/Examples

```bash
git clone git@github.com:sFinOe/dining-philo-problem.git
cd dining-philo-problem
make && ./philo [Time_To_Die, Time_To_Eat, Time_To_Sleep]
```
## Support

For support, email zakkikasmi@gmail.com or zakaria@disposkill.com.


## 🔗 Links
[![portfolio](https://img.shields.io/badge/my_portfolio-000?style=for-the-badge&logo=ko-fi&logoColor=white)](https://disposkill.com/about_me)
[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/sFinoe)
[![twitter](https://img.shields.io/badge/twitter-1DA1F2?style=for-the-badge&logo=twitter&logoColor=white)](https://twitter.com/zakie_kasmi)

