/*
 Project 3 - Part 1 / 5
Video:  Chapter 2 Part 5
 User-Defined Types

 Create a branch named Part1
 
 1) write 10 user-defined types, each with a random number of member variables
    try to make the member variables have names that are related to the user-defined type.
 
 2) give the member variables relevant data types
 
 3) add a couple member functions.  
    make the function parameter list for those member functions use some of your User-Defined Types
 
 4) make 2 of the 10 user-defined types be nested class
 
 5) One of your UDTs should only use UDTs for its member variable types.   
     No primitives allowed!
 
 6) After you finish defining each type, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */

/*
 example:
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

    void startTimer( Time* time );
    void stopTimer( Time* time );
    void resetTimer( Time* time );
};

/*
 2)
 */
struct Dog
{
    char* name, breed;
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
    char* nameOfPedal;
    int numOfKnobs;
    bool isModulation;

    void setPedalType( int pedalType );
    char* getPedalName( GuitarPedal pedal );


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
