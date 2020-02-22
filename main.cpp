 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */

struct CarWash            //1) a U.D.T. with a random number of member variables
{
    int numSponges = 3;
    double amountOfSoapUsedPerCar = 2.6; //2) relevant data types
    unsigned int numCarsProcessed = 0;
    
    struct Car                             //4) nested class
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        //2) relevant data types
    };
    
    void washAndWaxCar( Car car );         //3) member function with a user-defined type as the parameter.  The user-defined type parameter happens to be the nested class.
    
    Car myCar;  //5) a member variable whose type is a UDT.
};

#include <string>

/*
 1)
 */
struct Timer
{
    bool startButtonPressed = false;
    bool startButtonHeld = false;

    struct Time
    {
        unsigned int seconds, minutes, hours;
    };

    Time time;

    void startTimer();
    void stopTimer();
    void resetTimer();
};

/*
 2)
 */
struct Dog
{
    std::string name, breed;
    bool isGoodBoy = true;
    int numBallsFetched = 0;

    void chaseCar( CarWash::Car carToChase );

    int fetchBall() { return numBallsFetched; }

    bool checkIfGoodBoy( int numBallsFetched );
};

/*
 3)
 */
struct DrinkBeer
{
    unsigned int numBeersDrank;
    bool isDrunk = false;

    struct Beer
    {
        bool isLager;
        float alcoholPercentage;
    };

    unsigned int drinkBeer( Beer beer );

    bool checkIfDrunk ( unsigned int numOfBeers );

    Beer stout, maltLiquor, lightBeer;
};

/*
 4)
 */
struct Tree
{
    int numBranches;
    float height;

    void climbTree( float howHigh );
    
}; 

/*
 5)
 */
struct GuitarPedal
{
    std::string nameOfPedal;
    int numOfKnobs;
    bool isModulation;

    void setPedalType( int pedalType );
    std::string getPedalName( GuitarPedal pedal );


};

/*
 6)
 */
struct DelayPedal
{
    const int pedalType = 1;
    double delayTime, mix, feedback;
    bool hasTapTempo = true;

    void setTapTempo( int multiplier );
    void setDelaytime();
};

/*
 7)
 */
struct TremoloPedal
{
    const int pedalType = 2;
    double rate, rhythm, waveform;
    bool hasTapTempo = true;

    void setTapTempo( int multiplier );
    void setTremoloRate();
};

/*
 8)
 */
struct PatchCable
{
    int cableLength;
    bool isRightAngle;

    int getCableLength( PatchCable cable);
    int setCableColour( int colour );
};


/*
 9)
 */
struct PowerSupply
{
    float voltage;
    int maxCurrentOutput;
    bool hasTransformer = false;

    void setPowerSupplySpecs( PowerSupply powerSupply );

};


/*
 10)
 */
 struct PedalBoard
{
    GuitarPedal pedal1;
    GuitarPedal pedal2;
    GuitarPedal pedal3;
    PatchCable  patchCable;
    PowerSupply powerSupply;

    void setPedalOrder( PedalBoard pedalBoard );

};

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
