#include <iostream>
#include <unistd.h>

void start (int& h, int& m, int& s)
{
    while (1)
    {
        std::cout << h << " : " << m << " : " << s << std::endl;
        s++;
        if (s == 60)
        {
            s = 0;
            m++;
        }
        else if (m == 60)
        {
            m = 0;
            h++;
        }
        else if (h == 24)
        {
            h = m = s = 0;
        } 
        sleep(1);
        system("cls");       
    }
}

int main()
{
    int hours {};
    int mins {};
    int secs {};
    int& h = hours;
    int& m = mins;
    int& s = secs;
    int choice {};
    char user_confirmation {};

    std::cout << "Welcome! What do you want to do from the following? \n";
    std::cout << "1. Start the timer\n";
    std::cout << "2. Set time for clock\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice)
    {
        case 1:
            std::cout << "Do you want to start the timer (y or n): ";
            std::cin >> user_confirmation;

            if (user_confirmation == 'Y' || user_confirmation == 'y')
                start(h,m,s);
            else 
                std::cout << "Could not proceed. Exiting!!!\n";
            break;
        case 2:
            std::cout << "Enter the hours: ";
            std::cin >> h;
            if (!(h >= 0 && h < 23))
                h = 0;
            std::cout << "Enter the minutes: ";
            std::cin >> m;
            if (!(m >=0 && m < 61))
                m = 0;
            std::cout << "Enter the seconds: ";
            std::cin >> s;
            if (!(s >=0 && s < 61))
                s = 0;
            start (h, m, s);
            break;
        default:
            std::cout << "Invalid choice! ";
    }
}