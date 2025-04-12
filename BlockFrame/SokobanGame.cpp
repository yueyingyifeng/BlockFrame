//#include <iostream>
//#include <vector>
//#include <conio.h>  // For _getch()
//#include "DoubleBufferdCanvas.h"
//
//using namespace BlockFrame;
//
//const Block WALL('#');
//const Block TARGET('.');
//const Block PLAYER('@', Color::LightBlue);
//const Block BOX('$', Color::Cyan);
//const Block EMPTY(' ');
//// Game map
//const std::vector<std::string> map = {
//	"##########",
//	"#        #",
//	"#  $@    #",
//	"#        #",
//	"#   .    #",
//	"##########"
//};
//
//class SokobanGame {
//private:
//	DoubleBufferedCanvas canvas;
//	std::vector<std::string> currentMap;
//	int playerX, playerY;
//
//public:
//	SokobanGame(int width, int height)
//		: canvas(width, height, { 0, 0 }), currentMap(map) {
//		// Find the player's initial position
//		canvas.readFromStrings(currentMap);
//		for (int i = 0; i < currentMap.size(); i++) {
//			for (int j = 0; j < currentMap[i].size(); j++) {
//				if (currentMap[i][j] == PLAYER.c) {
//					playerX = j;
//					playerY = i;
//				}
//			}
//		}
//	}
//
//	void draw() {
//		canvas.update([this](Painting* p) {
//			for (int y = 0; y < currentMap.size(); y++) {
//				for (int x = 0; x < currentMap[y].size(); x++) {
//					char c = currentMap[y][x];
//					p->pixel(Vector2D(x, y), c);
//				}
//			}
//			});
//	}
//
//	void movePlayer(int dx, int dy) {
//		int newX = playerX + dx;
//		int newY = playerY + dy;
//
//		if (currentMap[newY][newX] == WALL()) {
//			return; // Can't move into a wall
//		}
//
//		// If there's a box
//		if (currentMap[newY][newX] == BOX()) {
//			int boxNewX = newX + dx;
//			int boxNewY = newY + dy;
//
//			if (currentMap[boxNewY][boxNewX] == WALL() || currentMap[boxNewY][boxNewX] == BOX()) {
//				return; // Can't push the box
//			}
//
//			// Move the box
//			currentMap[boxNewY][boxNewX] = BOX();
//			currentMap[newY][newX] = PLAYER();
//			currentMap[playerY][playerX] = EMPTY();
//			playerX = newX;
//			playerY = newY;
//		}
//		else if (currentMap[newY][newX] == EMPTY()) {
//			// Just move the player
//			currentMap[newY][newX] = PLAYER();
//			currentMap[playerY][playerX] = EMPTY;
//			playerX = newX;
//			playerY = newY;
//		}
//	}
//
//	void run() {
//		char input;
//		while (true) {
//			draw();
//
//			// Get user input
//			input = _getch(); // Wait for a key press
//			switch (input) {
//			case 'w': movePlayer(0, -1); break; // Up
//			case 's': movePlayer(0, 1); break; // Down
//			case 'a': movePlayer(-1, 0); break; // Left
//			case 'd': movePlayer(1, 0); break; // Right
//			case 'q': return; // Quit the game
//			}
//		}
//	}
//};
//
//int main() {
//	system("cls");
//	SokobanGame game(20, 20);
//	game.run();
//	return 0;
//}
