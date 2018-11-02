/*
* Course: CMPS 2143 - OOP
*
* Purpose: Implements a counter class to handle sfml clock and its counting
*
* @author Evan Jackson
* @version 1.0 11/2/2018
* @github https://github.com/ejackson007/2143-OOP-Jackson
*/
#include <SFML/Graphics.hpp>
#include <iostream>

// https://www.sfml-dev.org/tutorials/2.5/system-time.php

using namespace std;

class Counter{
private:
	sf::Clock clock;
	sf::Time start;
	sf::Time end;
	sf::Time elapsed;
	sf::Font font;
	sf::Text text;
	
public:
	/**
	* Creates Counter
	* @param ()
	* @return n/a
	*/
	Counter()
	{
		start = sf::seconds(0);
		end = sf::seconds(0);
	}

	/**
	* Creates Counter
	* @param (int s, int e)
	* @return n/a
	*/
	Counter(int s, int e)
	{
		start = sf::seconds(s);
		end = sf::seconds(e);
	}

	/**
	* gets the elapsed time
	* @param ()
	* @return round(elapsed)
	*/
	int getElapsed()
	{
		elapsed = clock.getElapsedTime();
		// used round function to get rid of decimals
		return round(elapsed.asSeconds());
	}

	/**
	* return the start time
	* @param ()
	* @return start of clock
	*/
	int getStart()
	{
		return start.asSeconds();
	}
	
	/**
	* set start time 
	* @param (int x)
	* @return void
	*/
	void setStart(int x)
	{
		start = sf::seconds(x);
	}

	/**
	* returns the end time
	* @param ()
	* @return end of clock
	*/
	int getEnd()
	{
		return end.asSeconds();
	}

	/**
	* set end time
	* @param (int x)
	* @return void
	*/
	void setEnd(int x)
	{
		end = sf::seconds(x);
	}
};


int main()
{
	int start, end;

	// Get values from user input, and give instructions
	cout << "Welcome to the timer. Please enter a starting time and stopping time.\n"
		<< "If the start is larger than the end, it will count down, and if the start\n"
		<< "is smaller than the end, it will count up. The window will close as it"
		<< " finishes.\n\nPlease enter START and END: ";


	
	cin >> start;
	cin >> end;

    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");

   /* sf::Clock clock; 
    sf::Time start;
    sf::Time end;
	sf::Time elapsed;
    start = sf::seconds(50);
    end = sf::seconds(50);
*/

	sf::Font font;
	// Lemon Milk sounds disgusting irl but it looks pretty cool and modern
	if (!font.loadFromFile("LemonMilk.otf"))
		std::cout << "Could not find font\n";

	sf::Text messageText;
	messageText.setFont(font);
	//messageText.setString();
	messageText.setCharacterSize(15);
	messageText.setFillColor(sf::Color::White);

	/*sf::Text messageText2;
	messageText2.setFont(font);
	messageText.setString();
	messageText2.setCharacterSize(15);
	messageText2.setPosition(0, 50);
	messageText2.setFillColor(sf::Color::White);*/
	
	Counter clockCounter(start, end);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //checks if the start is less than the end for incrimental clock

		//since it is going to cout, i use to_string function 
		// to turn the int to a string
		if (clockCounter.getStart() < clockCounter.getEnd())
			messageText.setString("Incrementing Clock: " +
			to_string(clockCounter.getStart() + clockCounter.getElapsed()));


		else if (clockCounter.getStart() > clockCounter.getEnd())
			messageText.setString("Decrementing Clock: " +
			to_string(clockCounter.getStart() - clockCounter.getElapsed()));

		// Incase the start and end input is the same
		else if (clockCounter.getStart() == clockCounter.getEnd())
		{
			cout << "CANNOT ENTER SAME VALUE\n";
			window.close();
			system("pause");
		}

        window.clear();
        window.draw(messageText);
		
		// checks to see if the time is up, used || since one or the other
		// going to be the part tested for. +1 or -1 added so that the end
		// number is counted before the window closes
        window.display();
		if ((clockCounter.getStart() + clockCounter.getElapsed()) == clockCounter.getEnd() + 1 || (clockCounter.getStart() - clockCounter.getElapsed()) == clockCounter.getEnd() - 1)
			window.close();
			
    }

    return 0;
} 