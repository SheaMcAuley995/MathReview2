#include "Manager.h"


	void Manager::MakeABaby(vec2 spawn, vec2 target)
	{

		int c = 0;
		for (; findCirclePntr[c] != nullptr && c < 255; ++c);
		if (c == 255) return;
		findCirclePntr[c] = new bubble(spawn, target);
	}

	void Manager::updateAll()
	{
		for (int i = 0; i < 256; ++i)
			if (findCirclePntr[i] != nullptr)
				findCirclePntr[i]->update();
	}
	void Manager::updateGatherAll()
	{
		for (int i = 0; i < 256; ++i)
			if (findCirclePntr[i] != nullptr)
				findCirclePntr[i]->gatherUpdate();
	}

	void Manager::updateExplodeAll()
	{
		for (int i = 0; i < 256; ++i)
			if (findCirclePntr[i] != nullptr)
				findCirclePntr[i]->explodeUpdate();
	}

	void Manager::drawAll()
	{
		for (int i = 0; i < 256; ++i)
			if (findCirclePntr[i] != nullptr)
				findCirclePntr[i]->draw();
	}
	
	