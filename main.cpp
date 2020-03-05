/*
 Project 3 - Part 4 / 5
 video: Chapter 2 - Part 9
 Member initialization tasks

 Create a branch named Part4
 
 1) initialize some of your member variables either in-class or in the Constructor member initializer list.

 2) make some of your member functions use those initialized member variables via std::cout statements.
 
 3) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */

#include <iostream>
namespace Example {
struct UDT  
{
    int a; //a member variable
    float b { 2.f }; //3) in-class initialization
    UDT() : a(0) { } //3) 'constructor-initializer-list' member variable initialization
    void printThing()  //the member function
    {
        std::cout << "UDT::printThing() a:" << a << " b: " << b << std::endl;  //4) printing out something interesting
    }
};

int main()
{
    UDT foo; //instantiating a Foo in main()
    foo.printThing(); //calling a member function of the instance that was instantiated.
    return 0;
}
}

//call Example::main()


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

        Time() { seconds = 0; minutes = 0; hours = 0; }
        ~Time(){}
        
        void increaseTime();
        void haltTime();
    };

    Time time;

    Timer(){ isRunning = true; }
    /*~Timer(){ std::cout << "\nThe timer has stopped. It took " << time.seconds << " seconds " << time.minutes << " minutes " << time.hours << " hours to run all those functions!" << std::endl; }
    */

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
    std::cout << "The timer is running." << std::endl;
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

    Dog();

    struct Car
    {
        bool isPickupTruck = false;
    };

    void printDogNameAndBreed();

    void chaseCar( Dog::Car carToChase );

    int fetchBall();

    bool checkIfGoodBoy();
};

Dog::Dog ()
{
    name = "Cooper";
    breed = "Golden Retriever";
}

void Dog::printDogNameAndBreed()
{
    std::cout << "The dogs name is " << name << " and he is a " << breed << std::endl;
}


void Dog::chaseCar ( Dog::Car carToChase )
{
    chasingTheCar = carToChase.isPickupTruck;
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
    float numBeersDrank;
    bool isDrunk;

    struct Beer
    {
        bool isStout = false;
        bool isMaltLiquor = false;
        bool isLightBeer = false;
        float alcoholPercentage = 0;

        Beer(){isMaltLiquor = true;}
    };

    DrinkBeer() { numBeersDrank = 0; isDrunk = false; }

    float drinkBeer( Beer beer );

    bool checkIfDrunk();

    Beer stout, maltLiquor, lightBeer;
};

float DrinkBeer::drinkBeer ( Beer beer )
{
    if ( beer.isStout )
    {
        numBeersDrank += 1.0f;
    }
    else if ( beer.isMaltLiquor )
    {
        numBeersDrank += 2.0f;
    }
    else if ( beer.isLightBeer )
    {
        numBeersDrank += 0.5f; 
    }
    return numBeersDrank;
}

bool DrinkBeer::checkIfDrunk ()
{
    isDrunk = numBeersDrank >= 6.f;
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

    Tree(int a, int b){height = a; numBranches = b;}

    void climbTree( float howHigh );
    
}; 

void Tree::climbTree ( float howHigh )
{
    for ( int i = 0; i < howHigh; i++)
    {
        i > height ? std::cout << "Can't climb any higher!" << std::endl : std::cout << "You've climbed " << i << " meters of the tree!" << std::endl;
    }
}

/*
 5)
 */
struct GuitarPedal
{
    std::string nameOfPedal, typeOfPedal;
    int numOfKnobs = 0, order = 0;
    bool isModulation = false;

    GuitarPedal( std::string type );
    void setPedalType( int pedalType );
    std::string getPedalName();
    void printPedalName();
};

void GuitarPedal::printPedalName()
{
    std::cout << "This pedal is a " << getPedalName() << std::endl;
}

GuitarPedal::GuitarPedal ( std::string type )
{
    typeOfPedal = type;
}

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
    else
    {
        nameOfPedal = "Invalid pedal name";
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

    DelayPedal ( double dt, double m, double fb ) : delayTime(dt), mix(m), feedback(fb) {}
    void setTapTempo ( int multiplier );
    void setDelayTime ( double newDelayTime );
    double getDelayTime();
};

void DelayPedal::setTapTempo ( int multiplier )
{
    delayTime = tapSpeed * multiplier;
}

void DelayPedal::setDelayTime ( double newDelayTime )
{
    delayTime = newDelayTime;
}

double DelayPedal::getDelayTime()
{
    std::cout << "The delay time is " << delayTime << std::endl;
    return delayTime;
}

/*
 7)
 */
struct TremoloPedal
{
    double m_rate = 0, m_tapSpeed = 0;
    int m_rhythm = 0, m_waveform;
    const int pedalType = 2;
    bool hasTapTempo = true;

    TremoloPedal ( double rate, int rhythm, int waveform ) : m_rate(rate), m_rhythm(rhythm), m_waveform(waveform) {}
    void setTapTempo ( int multiplier );
    void setTremoloRate ( double newTremoloRate );
    double getTremoloRate();
};

double TremoloPedal::getTremoloRate()
{
    std::cout << "The tremolo rate is " << m_rate << std::endl;
    return m_rate;
}

void TremoloPedal::setTapTempo ( int multiplier )
{
    m_rate = m_tapSpeed * multiplier;
}

void TremoloPedal::setTremoloRate ( double newTremoloRate )
{
    m_rate = newTremoloRate;
}

/*
 8)
 */
struct PatchCable
{
    int cableLength = 0;
    bool isRightAngle = 0;

    PatchCable ( int length, bool rightAngle ) : cableLength(length), isRightAngle(rightAngle) {}
    int getCableLength();
    int setCableColour( int colour );
};

int PatchCable::getCableLength ()
{   
    std::cout << "The length of the cable is " << cableLength << std::endl;
    return cableLength;
}

/*
 9)
 */
struct PowerSupply
{
    float voltage = 0;
    int maxCurrentOutput = 0;
    bool DC = false;

    PowerSupply(){}
    PowerSupply ( float volts, int current, bool dc ) : voltage(volts), maxCurrentOutput(current), DC(dc) {}
    void setPowerSupplySpecs( float v, int i, bool dc );
};

void PowerSupply::setPowerSupplySpecs ( float v, int i, bool dc )
{
    voltage = v;
    maxCurrentOutput = i; //mA
    DC = dc;
    std::cout << "The power supply specs are: " << voltage << "V " << (DC ? "DC" : "AC") << " " << maxCurrentOutput << "mA" << std::endl;
}

/*
 10)
 */
 struct PedalBoard
{
    GuitarPedal pedal1;
    GuitarPedal pedal2;
    PatchCable  patchCable;
    PowerSupply powerSupply;

    PedalBoard();
    void setPedalOrder();

};

PedalBoard::PedalBoard()
: pedal1 ( "delay" ), pedal2 ( "tremolo" ), patchCable ( 2, true ), powerSupply ( 12.0f, 500, true )
{
}

void PedalBoard::setPedalOrder()
{
    if (pedal1.getPedalName() == "Super Awesome Delay")
    {
        pedal1.order = 1;
    }
    if ( pedal2.getPedalName() == "Super Awesome Tremolo")
    {
        pedal2.order = 0;
    }
    std::cout << "The pedal order is " << pedal1.nameOfPedal << (pedal1.order == 0 ? " first " : " last ") << pedal2.nameOfPedal << (pedal2.order == 0 ? " first" : " last") << std::endl;
}

void printFunctionNumber ( int number )
{
    std::cout << "\n" << number << ")\n";
}

int main()
{
    Example::main();

    printFunctionNumber(1);
    Timer t;
    t.time.increaseTime();

    printFunctionNumber(2);
    Dog dog;
    dog.printDogNameAndBreed();

    printFunctionNumber(3);
    DrinkBeer db;
    DrinkBeer::Beer maltLiquor;
    while (!db.isDrunk){
        db.drinkBeer(maltLiquor);
        db.checkIfDrunk();
    }

    printFunctionNumber(4);
    Tree tree(5, 20);
    tree.climbTree(7);

    printFunctionNumber(5);
    GuitarPedal delayPedal ( "delay" );
    GuitarPedal tremoloPedal ( "tremolo" );
    delayPedal.printPedalName();
    tremoloPedal.printPedalName();

    printFunctionNumber(6);
    DelayPedal delay (0.2, 0.15, 0.3);
    delay.getDelayTime();

    printFunctionNumber(7);
    TremoloPedal tremolo (0.75, 1, 3);
    tremolo.getTremoloRate();

    printFunctionNumber(8);
    PatchCable cable1 ( 3, true );
    PatchCable cable2 ( 6, false );
    cable1.getCableLength();
    cable2.getCableLength();

    printFunctionNumber(9);
    PowerSupply ps;
    ps.setPowerSupplySpecs(9.0f, 300, true);

    printFunctionNumber(10);
    PedalBoard pb;
    pb.setPedalOrder();

    std::cout << "good to go!" << std::endl;
}
