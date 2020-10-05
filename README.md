## Concordia University
![CU-logo](https://github.com/BestBonBai/COMP348/blob/master/Concordia-logo.jpeg) ![ENCS-logo](https://github.com/BestBonBai/COMP348/blob/master/logoENCS.jpg) 
---
## COMP345 : Advanced program design with C++ 

### Team Project
* Date: Fall 2020
* Instructor: Dr. Nora Houari, houari@encs.concordia.ca
---
#### Assignment 1: 
* [Asg 1](https://github.com/BestBonBai/COMP345/tree/master/A1) : **Due Date OCT-09-2020**
* Specific design requirements
  1. All data members of user-defined class type must be of **pointer type**.
  2. All file names and the content of the files must be according to what is given in the description below.
  3. All different parts must be implemented in their own separate .cpp/.h file duo. All functions’ implementation must be provided in the .cpp file 
    (i.e. no inline functions are allowed).
  4. All classes must implement a correct copy constructor, assignment operator, and stream insertion operator.
  5. **Memory leaks must be avoided**.
  6. Code must be documented using comments (user-defined classes, methods, free functions, operators).
  7. If you use third-party libraries that are not available in the labs and require setup/installation, you may not assume to have help using them 
     and you are entirely responsible for their proper installation for grading purposes.
---
#### 5 Parts to be implemented
 **Part 1 : Map**
  Implement a group of C++ classes that implement the structure and operation of a map for the game Warzone https://www.warzone.com/.
*  **Map Class : Map.h, Map.cpp, MapDriver.cpp**                                                                            
    - The **Map class** is implemented as a **connected graph**. The graph’s nodes represents a territory (implemented as a **Territory class**). 
    - Edges between nodes represent adjacency between territories.
    - Continents are connected subgraphs. Each territory belongs to one and only one continent.                                                         
    - A **territory** is owned by a player and contain a number of armies.                                      
    - The **Map** class can be used to represent any map graph configuration.                                      
    - The Map class includes a **validate()** method that makes the following checks: 
        1 the map is a connected graph,
        2 continents are connected subgraphs and
        3 each country belongs to one and only one continent.
    - Driver that creates different Map objects and checks whether they are valid or not.
  
 **Part 2 : Map loader**
    Implement a group of C++ classes that reads and loads a map file in the .map text file format as found in the “Domination” game source files, available at: http://domination.sourceforge.net/getmaps.shtm.
* **Map loader Class: MapLoader.h/.cpp, CapLoaderDriver.cpp**    
  - Map loader can read any Domination map file.
  - Map loader creates a map object as a graph data structure (see **Part 1**).
  - Map loader should be able to read any text file (even invalid ones).
  - Driver reads many different map files, creates a graph object for the valid ones and rejects the invalid ones.

 **Part 4 : Player**
    Implement a group of C++ classes that implement a Warzone player using the following design: 
    1. A player owns a collection of territories (see **Part 1**).
    2. A player owns a hand of Cards (see **Part 5**). 
    3. A player has their own list of orders to be created and executed in the current turn (see **Part 3**).
* **Player Class: Player.h/.cpp, PlayerDriver.cpp**   
    - Player owns a collection of territories (see **Part 1**)
    - Player owns a hand of Warzone cards (see **Part 5**)
    - Player contains methods **toDefend()** and **toAttack()** that return a list of territories that are to be defended and to be attacked, respectively.
    - Player contains a **issueOrder()** method that creates an order object and adds it to the list of orders.
    - **Driver** creates players and demonstrates that the above features are available.
 
  **Part 3 : Orders list**
    Implement a group of C++ classes that implement a Warzone player orders using the following design:
 * **OrdersList Class: OrderList.h/.cpp, OrdersDriver.cpp**       
    - The **OrdersList** class contains a list of **Order** objects.
    - Each kind of order is implemented as a subclass of the **Order** class.
    - The Order class implements a stream insertion operator that outputs a string describing the order. If the order has been executed, it should also output the effect of the order.
    - Every order subclass must implement the **validate()** method that is used to validate if the order is valid.
    - Every order subclass must implement the **execute()** method that first validates the order, and executes its action if it is valid, according to the order’s meaning and the player’s state.
    - The **OrdersList** class implements a **delete()** method that deletes an order from the list.
    - The **OrdersList** class implements a **move()** method to move an order in the list of orders.
    - Driver that creates orders of every kind, places them in an **OrdersList** object, and demonstrates that the above features are available.
    
 **Part 5 : Cards deck/hand**  
  Implement a group of C++ classes that implements a **deck** and **hand** of Warzone cards.
* **Cards deck/hand Class: Cards.h/.cpp, CardsDriver.cpp**  
  - **Deck** is a finite collection of Warzone cards.
  - **Hand** is a finite collection of Warzone cards.
  - Each card has a type from: **spy, bomb, reinforcement, blockade, airlift, and diplomacy**.
  - Deck has a **draw()** method that allows a player to draw a card at random from the cards remaining in the deck and place it in their hand.
  - Each card has a **play()** method that enables a player to use it during game play by creating special orders. Once a card has been played, it is removed from the hand and put back into the deck.
  - Driver that creates a deck of cards of all different kinds, then creates a hand object that is filled by drawing cards from the deck, then calls the play method of all cards in the hand.
---
#### Tools
* **Visual Studio 2017/2019** 
  - [Visual Studio C++ Project Setup (empty project)](https://www.youtube.com/watch?v=dyjGYk2BqNE&embed=no)
* **GitHub**
---
#### Tutorial Materials
* Updating...
