/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On a new branch:

 1) Add a constructor for each User-Defined-Type.
 
 2) Instantiate 1 or 2 instances of each of your user-defined types in the main function at the bottom of that file, and call some of those member functions.
 
 3) make them print out something interesting via std::cout
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type
{
    int a; //a member variable
    UDT() { a = 0; }             //3) the constructor
    void printThing()            //1) the member function
    {
        std::cout << "UDT::printThing() " << a << std::endl;  //5) printing out something interesting
    }
};

int main()
{
    UDT foo;              //4) instantiating a UDT in main()
    foo.printThing();     //4) calling a member function of the instance that was instantiated.
    
    return 0;
}
}

//insert Example::main() into main() of user's repo.


#include <string>

/*
 1)
 */
struct Timer
{
    bool startButtonPressed = false;
    bool startButtonHeld = false;
    bool isRunning = false;

    struct Time
    {
        unsigned int seconds, minutes, hours;
        
        void increaseTime();
        void haltTime();
    };

    Time time;

    void startTimer();
    void stopTimer();
    void resetTimer();
};

void Timer::startTimer()
{
    if( !isRunning )
    {
        time.increaseTime();
        isRunning = true;
    }
}

void Timer::stopTimer()
{
    if( isRunning )
    {
        time.haltTime();
        isRunning = false;
    }
}

void Timer::Time::increaseTime()
{
    //do stuff
}

void Timer::Time::haltTime()
{
    //do stuff
}

/*
 2)
 */
struct Dog
{
    std::string name, breed;
    int numBallsFetched = 0;
    bool isGoodBoy = true;
    bool chasingTheCar = false;

    void chaseCar( CarWash::Car carToChase );

    int fetchBall();

    bool checkIfGoodBoy();
};

void Dog::chaseCar ( CarWash::Car carToChase )
{
    chasingTheCar = carToChase.isAPickupTruck;
}

int Dog::fetchBall()
{
    numBallsFetched++;
    return numBallsFetched;
}

bool Dog::checkIfGoodBoy ()
{    
    isGoodBoy = numBallsFetched > 0;

    return isGoodBoy;
}

/*
 3)
 */
struct DrinkBeer
{
    float numBeersDrank = 0;
    bool isDrunk = false;

    struct Beer
    {
        bool isStout = false;
        bool isMaltLiquor = false;
        bool isLightBeer = false;
        float alcoholPercentage = 0;
    };

    float drinkBeer( Beer beer );

    bool checkIfDrunk ( float numOfBeers );

    Beer stout, maltLiquor, lightBeer;
};

float DrinkBeer::drinkBeer ( Beer beer )
{
    if ( beer.isStout )
    {
        numBeersDrank = 1.0f;
    }
    else if ( beer.isMaltLiquor )
    {
        numBeersDrank = 2.0f;
    }
    else if ( beer.isLightBeer )
    {
        numBeersDrank = 0.5f; 
    }
    return numBeersDrank;
}

bool DrinkBeer::checkIfDrunk ( float numOfBeers )
{
    isDrunk = numOfBeers >= 6.f;
    isDrunk ? std::cout << "Yer drunk!\n" : std::cout << "Keep drinkin!\n";
    return isDrunk;
}

/*
 4)
 */
struct Tree
{
    float height = 0;
    int numBranches = 0;

    void climbTree( float howHigh );
    
}; 

void Tree::climbTree ( float howHigh )
{
    if ( howHigh > this->height )
    {
        std::cout << "can't climb that high!" << std::endl;
    }
    else
    {
        for ( int i = 0; i < howHigh; i++)
        {
            //climb the tree
        }
    }    
}

/*
 5)
 */
struct GuitarPedal
{
    std::string nameOfPedal, typeOfPedal;
    int numOfKnobs = 0;
    bool isModulation = false;

    void setPedalType( int pedalType );
    std::string getPedalName();
};

void GuitarPedal::setPedalType ( int pedalType )
{
    switch ( pedalType )
    {
        case 1: 
            typeOfPedal = "delay";
            break;
        case 2:
            typeOfPedal = "tremolo";
            break;
    }
}

std::string GuitarPedal::getPedalName ()
{
    if ( typeOfPedal == "delay" )
    {
        nameOfPedal = "Super Awesome Delay";
    }
    else if ( typeOfPedal == "tremolo" )
    {
        nameOfPedal = "Super Awesome Tremolo";
    }
    return nameOfPedal;
}

/*
 6)
 */
struct DelayPedal
{
    double delayTime = 0, mix = 0, feedback = 0, tapSpeed = 0;
    const int pedalType = 1;
    bool hasTapTempo = true;

    void setTapTempo ( int multiplier );
    void setDelayTime ( double newDelayTime );
};

void DelayPedal::setTapTempo ( int multiplier )
{
    delayTime = tapSpeed * multiplier;
}

void DelayPedal::setDelayTime ( double newDelayTime )
{
    delayTime = newDelayTime;
}

/*
 7)
 */
struct TremoloPedal
{
    double rate = 0, rhythm = 0, waveform = 0, tapSpeed = 0;
    const int pedalType = 2;
    bool hasTapTempo = true;

    void setTapTempo ( int multiplier );
    void setTremoloRate ( double newTremoloRate );
};

void TremoloPedal::setTapTempo ( int multiplier )
{
    rate = tapSpeed * multiplier;
}

void TremoloPedal::setTremoloRate ( double newTremoloRate )
{
    rate = newTremoloRate;
}

/*
 8)
 */
struct PatchCable
{
    int cableLength = 0;
    bool isRightAngle = 0;

    int getCableLength();
    int setCableColour( int colour );
};

int PatchCable::getCableLength ()
{
    return cableLength;
}

/*
 9)
 */
struct PowerSupply
{
    float voltage = 0;
    int maxCurrentOutput = 0;
    bool hasTransformer = false;

    void setPowerSupplySpecs();
};

void PowerSupply::setPowerSupplySpecs()
{
    voltage = 9.0f;
    maxCurrentOutput = 300; //mA
    hasTransformer = true;
}

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

    void setPedalOrder();

};

void PedalBoard::setPedalOrder()
{
    //would not be a very good function!
    if (pedal1.getPedalName() == "Super Awesome Delay")
    {
        //pedalPosition = last;
    }
    else if ( pedal2.getPedalName() == "Super Awesome Tremolo")
    {
        //pedalPosition = first;
    }
    //etc.
}

int main()
{
    Example::main();
    std::cout << "good to go!" << std::endl;
}
