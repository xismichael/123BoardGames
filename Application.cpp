#include "Application.h"
#include "imgui/imgui.h"
#include "classes/TicTacToe.h"

namespace ClassGame {
        //
        // our global variables
        //
        TicTacToe *game = nullptr;
        int gameWinner = -1;

        //
        // game starting point
        // this is called by the main render loop in main.cpp
        //
        void GameStartUp() 
        {
            game = new TicTacToe();
            game->setUpBoard();
        }

        //
        // game render loop
        // this is called by the main render loop in main.cpp
        //
        void RenderGame() 
        {
                ImGui::DockSpaceOverViewport();

                //ImGui::ShowDemoWindow();


                if (!game) return;
                if (!game->getCurrentPlayer()) return;
                
                ImGui::Begin("Settings");
                ImGui::Text("Current Player Number: %d", game->getCurrentPlayer()->playerNumber());
                //make same line
                ImGui::SameLine();

                //add checkbox to set current player as AI

                static bool p0AI = false;
                if (ImGui::Checkbox("Player0AI", &p0AI)) {
                    if (p0AI) {
                        game->setAIPlayer(0);
                    }
                    else {
                        game->clearAIPlayer(0);
                    }
                }
                ImGui::SameLine();
                static bool p1AI = false;
                if (ImGui::Checkbox("Player1AI", &p1AI)) {
                    if (p1AI) {
                        game->setAIPlayer(1);
                    }
                    else {
                        game->clearAIPlayer(1);
                    }
                }


                ImGui::Text("Current Board State: %s", game->stateString().c_str());

    

                if (game->GameOver) {
                    ImGui::Text("Game Over!");
                    ImGui::Text("Winner: %d", gameWinner);
                    if (ImGui::Button("Reset Game")) {
                        game->stopGame();
                        game->setUpBoard();
                        gameWinner = -1;
                        p0AI = false;
                        p1AI = false;
                    }
                }
                ImGui::End();

                ImGui::Begin("GameWindow");
                game->drawFrame();
                ImGui::End();
        }

        //
        // end turn is called by the game code at the end of each turn
        // this is where we check for a winner
        //
        void EndOfTurn() 
        {
            Player *winner = game->checkForWinner();
            if (winner)
            {
                game->GameOver = true;
                gameWinner = winner->playerNumber();
            }
            if (game->checkForDraw()) {
                game->GameOver = true;
                gameWinner = -1;
            }
        }
}
