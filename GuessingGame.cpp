
#include <iostream>

class Guessing
{
    public:
        static int computerGuess(int lowval,int highval,int randnum,int count){
            if(highval>=lowval){
                int guess=lowval+(highval-lowval)/2;
                if(guess == randnum){
                    return count;
                }
                else if(guess>randnum){
                    count++;
                    return(computerGuess(lowval,guess-1,randnum,count));
                }else{
                    count++;
                    return(computerGuess(guess+1,highval,randnum,count));
                }
            }else{
                return -1;
            }
        }
}; // end class

int main()
{
    // generate a random number between 1 and 100
    // randnum = random.randint(1,101);
    // no object instance needed.
    int guess=-100;
    int count=0;

    srand(time(0));//change seed for random numbers based on current date of app start
    int randnum = rand() % 100 + 1;

    while(guess!=randnum){
        std::cout<<"Enter a number between  1 and 100"<<std::endl;
        std::cin>>guess;
        count+=1;
        if(guess<randnum){
            std::cout<<"higher!"<<std::endl;
        } else if(guess>randnum){
            std::cout<<"less!"<<std::endl;
        }else{
            std::cout<<"You guessed it!"<<std::endl;
        }
    }
    std::cout<<"You took "<<count<<" times to guess it"<<std::endl;
    std::cout<<"The computer took "<<Guessing::computerGuess(0,100,randnum,0)<<" times to guess it"<<std::endl;
} // end main
