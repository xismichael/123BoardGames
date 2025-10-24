Completed all functions as stated in TicTacToe.cpp, navigated through all the files to find out the parent class and what they do 

Added a function that removes AI player in Game.cpp and Game.h

Added two check box that represents p1 and p2 for using AI, and when the checkbox is checked, ai will be playing for that player. For now the AI will be simply placing at the first available square. I will update this once I have time

Moved game over variable from Class ClassGame to Class TicTacToe, to better manage what can be accessed after the game is over (to prevent more plays on the board)


Added a negamax function into TicTacToe class, on top of a check winner function specifically for any game state, that takes in a statestring as a parameter. Updated the UpdateAI function so that it now uses the negamax function. 

The NegaMax function takes a int player number and a string current state parameter, and it recursively calls itself with the next turn's player and the potential game state until either a draw, or a player has won.

The UpdateAI function takes the score received from the negamax function and find the best position to place the piece, places it, then end of turn.

Added Alpha Beta Pruning to the NegaMax function to prevent unnecesary branching, and improve efficency