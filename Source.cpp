#include<SFML\Graphics.hpp>
#include"Game.h"
int main()
{
	sf::err().rdbuf(NULL);
	Game game;
	game.run();

	//std::vector < long> vec( 99999999999999, 1);
	//int start = clock();

	//long sum = 0;
	////for (auto &f : vec)
	////	sum += f;
	//for (long i = 0; i < vec.size(); i++)
	//	sum += vec[i];

	//int end = clock();

	//std::cout << "TIme : " << (end - start) / double(CLOCKS_PER_SEC) << std::endl;
	//std::cout << "TIme : " << sum<< std::endl;
	
	//fj('f');
	system("pause");
	return 0;
}