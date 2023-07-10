 # Buildup (C++) Collin Edition™ 
![](Aspose.Words.f7bbb1b0-bb67-48fa-84e7-aef9368cc1e9.001.jpeg)![](Aspose.Words.f7bbb1b0-bb67-48fa-84e7-aef9368cc1e9.002.jpeg)![](Aspose.Words.f7bbb1b0-bb67-48fa-84e7-aef9368cc1e9.003.jpeg)

Real Life picture of Buildup Domino Game 

Note it’s one of the few domino games that uses 2 different colored set of dominoes 
## Build Up Domino (RULES OF THE GAME)
Build Up is a two-player dominoes game, designed by David Vander Ark.
### The Objective
The objective of this game is to score the highest after the final hand in a round.
### The Players
Two players play this game - one player will be the human user of the program, and the other player will be the program/computer. The two players will play a "tournament", consisting of one or more rounds. Each round will consist of the two players playing four hands, each hand consisting of 4-6 tiles.
### The Setup
The game uses two double-six sets. A double-six set contains 28 tiles. Each tile has two ends, each end containing 0-6 pips. The double-six set contains tiles with the following combination of pips:

0-0, 0-1, 0-2, 0-3, 0-4, 0-5, 0-6, 

1-1, 1-2, 1-3, 1-4, 1-5, 1-6,

2-2, 2-3, 2-4, 2-5, 2-6,

3-3, 3-4, 3-5, 3-6,

4-4, 4-5, 4-6,

5-5, 5-6,

6-6.
#### Two such sets are used in the game - a white set used by the computer and a black set used by the human player. The two sets are shuffled before use.
Each player draws six tiles from the player's shuffled set and places them face up to constitute two rows of six tiles. The remaining tiles in each shuffled set form the boneyard for the respective player (black for human and white for computer).
### A Round
Each round consists of four hands. Six tiles each are used in the first three hands. The remaining 4 tiles are used in the last hand. For the first hand, in addition to the tile used to determine the first player, players draw five additional tiles from their boneyards. For subsequent hands, players draw the required number of tiles from the shuffled boneyard.
### First Player
Each player draws a tile from his/her boneyard. The player whose tile has the most pips plays first. If both the players have the same number of pips, the tiles are returned to the boneyards, the boneyards are shuffled and the process is repeated.
### A Hand
In each hand, the two players alternate placing one tile each, starting with the first player as determined above. The hand ends when both the players have placed all their tiles, or when neither player can place a tile. If one player cannot place a tile on his/her turn, the player will pass, allowing the other player to continue.
### Placement of a tile
A player places a tile from her/his hand on top of one of the twelve tile stacks started during setup, subject to the following rules:
- A non-double tile may be placed on any tile as long as the total number of pips on it is greater than or equal to that of the tile on which it is placed.
- A double tile (e.g., 0-0, 1-1, 2-2) may be placed on any non-double tile, even if the non-double tile has more pips.
- A double tile may be placed on another double tile only if it has more total pips than the tile on which it is placed.
### Score
When a hand ends, each player is awarded points as follows:
The points equal the total pips on all the tiles of the player's color that are on top of the twelve stacks.
If the player has any tiles that could not be placed, the total pips of these tiles is subtracted from the points. The tiles themselves are discarded, not returned to the boneyeard.
These points are added to the current score of the player. After the scores are updated, the next hand is started.
When the final hand ends, the player with the highest score wins the round. Ifboth the players have the same number of points, the round is a draw.
### The Tournament
After each round, the human player is asked whether she/he wants to play another round.
If yes, another round is played as described above and the process is repeated.
If no, the winner of the tournament is announced and the game quits. The winner of the tournament is the player who has won the most number of rounds. If both the players have won the same number of rounds, the tournament is a draw.
Ideally, players should try to place on top of their opponent's tiles rather than their own, so that more of their tiles will end up on top of stacks. But a player may choose to place on top of his/her own tile in order to play a tile that can otherwise not be played. Another way to play a tile that can otherwise not be played is to first place a low-valued double-tile on top of a high-valued tile.

## Bug Report 

The only bug detected occurs when the domino location is listed in help mode. Sometimes this may be incorrect. 

## Program execution 

This program was made using the 2019 Microsoft Visual Studio. The main executor is Buildup_Collin_Schumacher_Edition.exe file just click on it and the game should run just as expected 

## Feature List 

- ### Missing Features 

![](Aspose.Words.f7bbb1b0-bb67-48fa-84e7-aef9368cc1e9.004.png) Help mode sometimes it doesn’t choose non double tile when it has one double 

tile left 

- ### Extra features  

![](Aspose.Words.f7bbb1b0-bb67-48fa-84e7-aef9368cc1e9.004.png) Allow for user to enter and read serialization files with white space e.g test file 

number One

![](Aspose.Words.f7bbb1b0-bb67-48fa-84e7-aef9368cc1e9.004.png) If the file cannot be found, display .txt files found in the directory

## Data Structures Used 

- A vector of strings was the primarily used data structure, and it was used for the following pieces… boneyard, hand, and stack. 
- A vector of Player pointers was used in implementing the polymorphic behavior in the game 

## Classes 

- ### Round class  

![](Aspose.Words.f7bbb1b0-bb67-48fa-84e7-aef9368cc1e9.005.png)This class is responsible for all information about a round including who won the 

round, who won the tournament, saving the game (SERIALIZATION of a 

tournament), who goes first, setting up the round, and setting up the tournament. 

![](Aspose.Words.f7bbb1b0-bb67-48fa-84e7-aef9368cc1e9.005.png) Compositions: 

- player\_list: Vector of player pointers so that players can interact in the round polymorphically 
- ### Game class 

![](Aspose.Words.f7bbb1b0-bb67-48fa-84e7-aef9368cc1e9.005.png)This class is responsible for running the entire game; everything from the 

welcome menu, playing a new game/tournament, and loading in a game from a serialization file. These are some of the key variables used within the class:

- player\_list: Vector of player pointers so that players can interact in the round polymorphically 
  - memory: Vector of strings used for reading in a SERIALIZATION file at each line and storing them.
- ### Domino class 

![](Aspose.Words.f7bbb1b0-bb67-48fa-84e7-aef9368cc1e9.005.png)This class is responsible for handling all of the domino capabilities such as stacks, 

boneyards, and hands. In addition, it handles subsequent functions like determining if the domino can be placed at a location, or determining the value of the domino e.g w34 = white 7 pip domino. It uses 4 important variables that play a HUGE role in Buildup:

- bone\_yard: Vector of strings used for holding the tiles in the boneyard
- stack: Vector of strings used for holding the tiles in the stack
- hand: Vector of strings used for holding the tiles in the hand
- selected\_bone: String is used for holding the domino that was selected 
- ### Player class  

![](Aspose.Words.f7bbb1b0-bb67-48fa-84e7-aef9368cc1e9.005.png)This class is the base class for each player. It handles all of the important player 

abilities like being able to call all of the important domino functions as well as  other functions like being able to tally score, make a move(polymorphic), and  determining the legal placement of a domino.

![](Aspose.Words.f7bbb1b0-bb67-48fa-84e7-aef9368cc1e9.005.png) Compositions:

- Table: Domino object used for the player which is able to interact with said dominoes
- ### Human class  

![](Aspose.Words.f7bbb1b0-bb67-48fa-84e7-aef9368cc1e9.005.png)This class is one of the two derived classes of the player class it provides its own 

input validation (user enters input) for selection and making a move (polymorphism). All of the functions are from the player class 

- ### Computer class  

![](Aspose.Words.f7bbb1b0-bb67-48fa-84e7-aef9368cc1e9.005.png)This class is one of the two derived classes of the player class. It provides its own 

input validation (computer generates its own input) for selection and making a move (polymorphism). Most of the functions are from the player class, but computer also has ai\_decison function used for coming up with the domino selection (POLYMORPHIC) and will always return 2 (make a move since computer will ALWAYS play to win).

## Log 

1. 1/16/2023: learned how to play Buildup, found a paper printable double 6 domino kit (located in the doc and made one of them black through editor), and attempted to play the game in real life with a family member. 
1. 1/17/2023: Created the project in 2019 Visual Studio and added in the appropriate classes and learned in greater detail how to play the game since it was the 1st day the professor went into detail of how to play buildup. 
1. 1/18/2023: Got the players’ boneyards to be created and shuffled along with defining all of the basic setup functions like setting up the boneyard and displaying it correctly.  
1. 1/19/2023: Got the first player to be declared by determining who drew the higher domino and also got the first hand to work correctly. 
5. 1/20/2023 – 1/21/2023: Took a break  
5. 1/22/2023: AS OF THIS DATE I got the make move declared and working for the human class along with the legal placement of domino is legal according to the game rules. 
5. 1/23/2023: Got make move to work for computer at random BUT LEGAL moves according to the game rules. 
5. 1/24/2023: Added some of the comment headers and added in some of the minor tweaks for better game optimization in terms of making the ascii graphics more efficient. 
5. 1/25/2022 -1/27/2023: worked on serialization and file parsing 
10. 1/28/2023-/1/31/3023: Worked on help mode and computer strategies. 
10. 2/1/2023-2/3/2023: Worked on extensive testing cleanup 
10. 2/4/2023-2/6/2023: Wrote user manual and added final touches including the ironing out of any glitches. 

## Screen shots 

1. Main Menu

![](Aspose.Words.f7bbb1b0-bb67-48fa-84e7-aef9368cc1e9.006.png)

2. Round information so far

![](Aspose.Words.f7bbb1b0-bb67-48fa-84e7-aef9368cc1e9.007.jpeg)

3. Computer player method

![](Aspose.Words.f7bbb1b0-bb67-48fa-84e7-aef9368cc1e9.008.jpeg)

4. Help mode

![](Aspose.Words.f7bbb1b0-bb67-48fa-84e7-aef9368cc1e9.010.jpeg)

5. Human input for stacking opponents stack 

![](Aspose.Words.f7bbb1b0-bb67-48fa-84e7-aef9368cc1e9.011.jpeg)

6. Human input for stacking on its own stack

![](Aspose.Words.f7bbb1b0-bb67-48fa-84e7-aef9368cc1e9.013.jpeg)

7. save game 

![](Aspose.Words.f7bbb1b0-bb67-48fa-84e7-aef9368cc1e9.014.jpeg)

8. Load game 

![](Aspose.Words.f7bbb1b0-bb67-48fa-84e7-aef9368cc1e9.015.png)

9. When human player can’t make any moves 

![](Aspose.Words.f7bbb1b0-bb67-48fa-84e7-aef9368cc1e9.016.jpeg)

10. Which player won 

![](Aspose.Words.f7bbb1b0-bb67-48fa-84e7-aef9368cc1e9.017.jpeg)

11. Which player won the tournament 

![](Aspose.Words.f7bbb1b0-bb67-48fa-84e7-aef9368cc1e9.018.jpeg)
