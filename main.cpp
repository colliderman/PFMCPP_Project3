 #include <iostream>

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
struct Person
{
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTravelled;

    void run( int howFast, bool startWithLeftFoot);

    struct foot
    {
        bool didStepForward;

        void stepForward()
        {
            didStepForward = true;
        }
        int stepSize()
        {
            //inches
            int footSize = 9;
            int averageHeight = 69; 
            int stepSize = (averageHeight/5) + footSize; //just making this up!

            return stepSize;
        }
        
    };

    foot leftFoot, rightFoot;
};

void Person::run( int howFast, bool startWithLeftFoot )
{
    if( startWithLeftFoot )
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    }
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }
    distanceTravelled += leftFoot.stepSize() + rightFoot.stepSize();
}
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
    int numBallsFetched;
    bool isGoodBoy = true;
    bool chasingTheCar = false;

    void chaseCar( CarWash::Car carToChase );

    int fetchBall();

    bool checkIfGoodBoy( int numBallsFetched );
};

void Dog::chaseCar ( CarWash::Car carToChase )
{
    if ( carToChase.isAPickupTruck )
    {
        this->chasingTheCar = true;
    }
    else
    {
        this->chasingTheCar = false;
    }
}

int Dog::fetchBall()
{
    numBallsFetched++;
    return numBallsFetched;
}

bool Dog::checkIfGoodBoy ( int numBallsFetched )
{
    this->numBallsFetched = numBallsFetched;
    
    if ( numBallsFetched > 0 )
    {
        this->isGoodBoy = true;
    }
    else
    {
        this->isGoodBoy = false; //just getting a feel for using 'this' keyword
    }
    return isGoodBoy;
}

/*
 3)
 */
struct DrinkBeer
{
    float numBeersDrank;
    bool isDrunk = false;

    struct Beer
    {
        bool isStout = false;
        bool isMaltLiquor = false;
        bool isLightBeer = false;
        float alcoholPercentage;
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
    if ( numOfBeers >= 6.0f )
    {
        std::cout << "Yer drunk!" << std::endl;
        isDrunk = true;
    }
    else 
    {
        std::cout << "Keep drinkin!" << std::endl;
        isDrunk = false;
    }
    return isDrunk;
}

/*
 4)
 */
struct Tree
{
    float height;
    int numBranches;

    void climbTree( float howHigh );
    
}; 

void Tree::climbTree ( float howHigh )
{
    if ( howHigh > this->height )
    {
        std::cout << "can't climb that high!" << std::endl;
        return;
    }

    for ( int i = 0; i < howHigh; i++)
    {
        //climb the tree
    }
}

/*
 5)
 */
struct GuitarPedal
{
    std::string nameOfPedal, typeOfPedal;
    int numOfKnobs;
    bool isModulation;

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
        case2:
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
    double delayTime, mix, feedback, tapSpeed;
    const int pedalType = 1;
    bool hasTapTempo = true;

    void setTapTempo ( int multiplier, double tapSpeed );
    void setDelayTime ( double newDelayTime );
};

void DelayPedal::setTapTempo ( int multiplier, double tapSpeed )
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
    double rate, rhythm, waveform, tapSpeed;
    const int pedalType = 2;
    bool hasTapTempo = true;

    void setTapTempo ( int multiplier, double tapSpeed );
    void setTremoloRate ( double newTremoloRate );
};

void TremoloPedal::setTapTempo ( int multiplier, double tapSpeed )
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
    int cableLength;
    bool isRightAngle;

    int getCableLength( PatchCable cable);
    int setCableColour( int colour );
};

int PatchCable::getCableLength ( PatchCable cable )
{
    //return cable.cableLength;
    //return this->cableLength;

    /*
    Ok, I totally understand what you were saying now in our previous slack
    conversation. That by using 'PatchCable cable' as an argument to this function is
    kind of pointless because if I want to return 'cableLength', I probably want to 
    return the cableLength of the object that called it, not the cableLength of the 
    argument to the function. This is where my C experience is kind of clouding what
    object oriented programming is all about..if that makes sense. I get it now though!
    */
}


/*
 9)
 */
struct PowerSupply
{
    float voltage;
    int maxCurrentOutput;
    bool hasTransformer = false;

    //I'm removing argument from this function now that I understand the error of my ways!
    void setPowerSupplySpecs();
};

void PowerSupply::setPowerSupplySpecs()
{
    this->voltage = 9.0f;
    this->maxCurrentOutput = 300; //mA
    this->hasTransformer = true;
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

    //removing argument here for reasons above 
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
    std::cout << "good to go!" << std::endl;
}
