#include "HelloWorldScene.h"
//#include "SimpleAudioEngine.h"

USING_NS_CC;

#define Xmax 12
#define Ymax 15
#define Delay 0.2
block* Board[Xmax][Ymax];
bool CanTouch = true;
bool BlockTouch;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

bool HelloWorld::init()
{
    if ( !Scene::init() )
    {
        return false;
    }
	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);

	winSize = Director::getInstance()->getWinSize();
	srand(time(NULL));

	for (int i = 0; i < Xmax * Ymax; i++)
	{
		auto newB = new block(0, i%Xmax, i/ Xmax);
		newB->setPosition(Vec2(0 + 64 * (i%Xmax), 0 + 64 * (i/ Xmax)));
		newB->setScale(2);
		this->addChild(newB);

		Board[i % Xmax][i / Xmax] = newB;
	}
	Board[3][2]->ChangeSprite(1); // block
	Board[3][3]->ChangeSprite(1); // block
	Board[3][4]->ChangeSprite(1); // block

	StartBlock = Board[1][3];
	GoalBlock = Board[5][3];

	StartBlock->ChangeSprite(3); 
	GoalBlock->ChangeSprite(2);

	Player = Sprite::create("player.png");
	Player->setPosition(StartBlock->getPosition() + Vec2(32,32));
	Player->setScale(1.25);
	this->addChild(Player,200);

	CreateMenu();
	//StartFind();

    return true;
}
void HelloWorld::CreateMenu()
{
	auto Layer = LayerColor::create(Color4B::BLACK);
	Layer->setContentSize(Size((winSize.width/5) ,winSize.height));
	Layer->setAnchorPoint(Vec2(1, 0));
	Layer->setPosition(Vec2(winSize.width - 193, 0));
	Layer->setZOrder(9999);
	this->addChild(Layer);

	auto pMenuItem = MenuItemFont::create(
		"Start!", CC_CALLBACK_0(HelloWorld::StartFind, this)
	);
	pMenuItem->setColor(Color3B::WHITE);
	pMenuItem->setAnchorPoint(Vec2(0.5, 0));;
	pMenuItem->setPosition(Vec2(Layer->getContentSize().width/2, 150));
	pMenuItem->setZOrder(999);

	auto pMenuItem2 = MenuItemFont::create(
		"Reset", CC_CALLBACK_0(HelloWorld::NodeClear, this)
	);
	pMenuItem2->setColor(Color3B::WHITE);
	pMenuItem2->setAnchorPoint(Vec2(0.5, 0));;
	pMenuItem2->setPosition(Vec2(Layer->getContentSize().width / 2, 50));
	pMenuItem2->setZOrder(999);

	///////////////////////////////////////////////////////////
	StartMenuItem = MenuItemFont::create(
		"Set Start", CC_CALLBACK_0(HelloWorld::SetStart, this)
	);
	StartMenuItem->setColor(Color3B::WHITE);
	StartMenuItem->setAnchorPoint(Vec2(0.5, 0));;
	StartMenuItem->setPosition(Vec2(Layer->getContentSize().width / 2, 450));
	StartMenuItem->setZOrder(999);


	EndMenuItem = MenuItemFont::create(
		"Set End", CC_CALLBACK_0(HelloWorld::SetEnd, this)
	);
	EndMenuItem->setColor(Color3B::WHITE);
	EndMenuItem->setAnchorPoint(Vec2(0.5, 0));;
	EndMenuItem->setPosition(Vec2(Layer->getContentSize().width / 2, 350));
	EndMenuItem->setZOrder(999);

	BlockMenuItem = MenuItemFont::create(
		"Set Wall", CC_CALLBACK_0(HelloWorld::SetBlock, this)
	);
	BlockMenuItem->setColor(Color3B::YELLOW);
	BlockMenuItem->setAnchorPoint(Vec2(0.5, 0));;
	BlockMenuItem->setPosition(Vec2(Layer->getContentSize().width / 2, 550));
	BlockMenuItem->setZOrder(999);

	auto pMenuItem3 = MenuItemFont::create(
		"Clean Wall", CC_CALLBACK_0(HelloWorld::RemoveWall, this)
	);
	pMenuItem3->setColor(Color3B::WHITE);
	pMenuItem3->setAnchorPoint(Vec2(0.5, 0));;
	pMenuItem3->setPosition(Vec2(Layer->getContentSize().width / 2, 250));
	pMenuItem3->setZOrder(999);
	///////////////////////////////////////////////////////////

	auto pMenu = Menu::create(pMenuItem, pMenuItem2, StartMenuItem, EndMenuItem, BlockMenuItem, pMenuItem3, NULL);
	pMenu->setAnchorPoint(Vec2(0.5, 0.5));
	pMenu->setPosition(0, 0);
	pMenu->setZOrder(300);
	Layer->addChild(pMenu, 21);
}

void HelloWorld::SetStart()
{
	StartMenuItem->setColor(Color3B::YELLOW);
	EndMenuItem->setColor(Color3B::WHITE);
	BlockMenuItem->setColor(Color3B::WHITE);

	ChangeStartSelected = true;
	ChangeEndSelected = false;
}

void HelloWorld::SetEnd()
{
	StartMenuItem->setColor(Color3B::WHITE);
	EndMenuItem->setColor(Color3B::YELLOW);
	BlockMenuItem->setColor(Color3B::WHITE);

	ChangeStartSelected = false;
	ChangeEndSelected = true;
}

void HelloWorld::SetBlock()
{
	StartMenuItem->setColor(Color3B::WHITE);
	EndMenuItem->setColor(Color3B::WHITE);
	BlockMenuItem->setColor(Color3B::YELLOW);

	ChangeStartSelected = false;
	ChangeEndSelected = false;
}

void HelloWorld::RemoveWall()
{
	for (int i = 0; i < Xmax * Ymax; i++)
	{
		if (Board[i % Xmax][i / Xmax]->_type == 1)
		{
			Board[i % Xmax][i / Xmax]->ChangeSprite(0);
		}
	}
}

void HelloWorld::onEnter()
{
	Scene::onEnter();

	srand(time(NULL));

	listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}
bool HelloWorld::onTouchBegan(Touch *touch, Event *event)
{
	if (isScheduled(schedule_selector(HelloWorld::RunAction)))
	{
		return false;
	}

	auto touchPoint = touch->getLocation();
	int temp = -1;
	for (int i = 0; i < Xmax * Ymax; i++)
	{
		if (Board[i % Xmax][i / Xmax]->getBoundingBox().containsPoint(touchPoint))
		{
			temp = i; break;
		}
	}

	if (temp != -1)
	{
		if (Board[temp % Xmax][temp / Xmax]->_type != 2 && Board[temp % Xmax][temp / Xmax]->_type != 3)
		{
			if (ChangeStartSelected)
			{
				StartBlock->ChangeSprite(0);
				Board[temp % Xmax][temp / Xmax]->ChangeSprite(3);
				StartBlock = Board[temp % Xmax][temp / Xmax];

				Player->setPosition(StartBlock->getPosition() + Vec2(32, 32));
			}
			else if (ChangeEndSelected)
			{
				GoalBlock->ChangeSprite(0);
				Board[temp % Xmax][temp / Xmax]->ChangeSprite(2);
				GoalBlock = Board[temp % Xmax][temp / Xmax];
			}
			else
			{
				Board[temp % Xmax][temp / Xmax]->ChangeSprite();
				if (Board[temp % Xmax][temp / Xmax]->_type == 0)
					BlockTouch = false;
				else
					BlockTouch = true;
			}
		}
	}

	for (int j = Nodes.size() - 1; j >= 0; j--)
	{
		if (Nodes.at(j)->_X == temp % Xmax &&
			Nodes.at(j)->_Y == temp / Xmax)
		{
			log("Node : %d %d", Nodes.at(j)->_X, Nodes.at(j)->_Y);
			log("FullDistance : %d", Nodes.at(j)->FullDistance);
			log("StackedDistance : %d", Nodes.at(j)->StackedDistance);
			log("GoalDistance : %d", Nodes.at(j)->GoalDistance);
			break;
		}
	}

	return true;
}
void HelloWorld::onTouchMoved(Touch *touch, Event *event)
{
	if (isScheduled(schedule_selector(HelloWorld::RunAction)))
	{
		return;
	}
	auto touchPoint = touch->getLocation();
	int temp = -1;
	for (int i = 0; i < Xmax * Ymax; i++)
	{
		if (Board[i % Xmax][i / Xmax]->getBoundingBox().containsPoint(touchPoint))
		{
			temp = i; break;
		}
	}

	if (temp != -1)
	{
		if (Board[temp % Xmax][temp / Xmax]->_type != 2 && Board[temp % Xmax][temp / Xmax]->_type != 3)
		{
			if (ChangeStartSelected || ChangeEndSelected)
			{
			}
			else
			{
				if (BlockTouch)
				{
					Board[temp % Xmax][temp / Xmax]->ChangeSprite(1);
				}
				else
				{
					Board[temp % Xmax][temp / Xmax]->ChangeSprite(0);
				}
			}
		}
	}
}

int HelloWorld::FindMinNodeNumb()
{
	int Min = -1;
	int MinNodeNumb = -1;

	for (int NodeNumber = 0; NodeNumber < Open.size(); NodeNumber++)
	{
		if (Min == -1)
		{
			Min = Open.at(NodeNumber)->FullDistance;
			MinNodeNumb = NodeNumber;
		}
		else
		{
			if (Open.at(NodeNumber)->FullDistance < Min)
			{
				Min = Open.at(NodeNumber)->FullDistance;
				MinNodeNumb = NodeNumber;
			}
		}
	}
	log("MinNumb : %d", Min);
	log("Node : %d %d", Open.at(MinNodeNumb)->_X, Open.at(MinNodeNumb)->_Y);

	return MinNodeNumb;
}

void HelloWorld::NodeClear()
{
	if (isScheduled(schedule_selector(HelloWorld::RunAction)))
	{
		this->unschedule(schedule_selector(HelloWorld::RunAction));
		//return;
	}
	Player->stopAllActions();
	Player->setRotation(0);


	for (int i = Nodes.size() - 1; i >= 0; i--)
	{
		if (Open.contains(Nodes.at(i)))
			Open.eraseObject(Nodes.at(i));
		if (Close.contains(Nodes.at(i)))
			Close.eraseObject(Nodes.at(i));

		this->removeChild(Nodes.at(i));
		Nodes.eraseObject(Nodes.at(i));
	}
	
	Player->setPosition(StartBlock->getPosition() + Vec2(32,32));
}

void HelloWorld::StartFind()
{
	if (isScheduled(schedule_selector(HelloWorld::RunAction)))
	{
		return;
	}

	NodeClear();
	//
	block * start = StartBlock;
	block * end = GoalBlock;

	AstarNode *StartNode = new AstarNode(start->_X, start->_Y);
	StartNode->setPosition(Vec2(start->_X * 64 + 32, start->_Y * 64 + 32));
	StartNode->_ParentNode = NULL;

	Nodes.pushBack(StartNode);
	Open.pushBack(StartNode);

	while (Open.size() != 0)
	{
		int CenterNodeNumber = FindMinNodeNumb();

		int AroundX = Open.at(CenterNodeNumber)->_X - 1;
		int AroundY = Open.at(CenterNodeNumber)->_Y - 1;

		for (int i = 0; i < 9; i++)
		{
			int temp = -1;

			//if (AroundX + i % 3 == Open.at(CenterNodeNumber)->_X &&
			//	AroundX + i / 3 == Open.at(CenterNodeNumber)->_Y)
			//{
			//	//log("continue : Center");
			//	continue;
			//}	//자신인 경우 뛰어넘음

			if (AroundX + i % 3 < 0 || AroundX + i % 3 >= Xmax ||
				AroundY + i / 3 < 0 || AroundY + i / 3 >= Ymax)
			{
				//log("continue : outRange");
				continue;
			}	//보드 너머인 경우 뛰어넘음

			if (Board[AroundX + i%3][AroundY+i/3]->_type == 1)
			{
				//log("continue : blocked");
				continue;
			}	//장애물인 경우 뛰어넘음

			if ((i % 2) == 0)
			{
				int tep = 0;
				for (int DiagonalCheckN = -3; DiagonalCheckN <= 3; DiagonalCheckN+=2)
				{
					int DiagonalCheckPoint = i + DiagonalCheckN;
					if (DiagonalCheckPoint >= 0 && DiagonalCheckPoint <= 8)
					{
						//log("Around : %d %d", AroundX, AroundY);
						//log("DCP : %d", DiagonalCheckPoint);

						if (i == 2 && DiagonalCheckPoint == 3)
						{
							continue;
						}
						else if (i == 6 && DiagonalCheckPoint == 5)
						{
							continue;
						}

						if (AroundX + (DiagonalCheckPoint % 3) >= 0 && AroundX + (DiagonalCheckPoint % 3) < Xmax &&
							AroundY + (DiagonalCheckPoint / 3) >= 0 && AroundY + (DiagonalCheckPoint / 3) < Ymax)
						{
							if (Board[AroundX + (DiagonalCheckPoint % 3)][AroundY + (DiagonalCheckPoint / 3)]->_type == 1)
							{
								//log("continue : no Diagonal");
								tep = 1;
							}
						}
					}
				}

				if (tep == 1) continue;
			}	//장애물에 걸치는 경우 뛰어넘음

			for (int j = Nodes.size() - 1; j >= 0; j--)
			{
				//log("Node : %d %d", Nodes.at(j)->_X, Nodes.at(j)->_Y);
				//log("Target : %d %d", AroundX + i % 3, AroundY + i / 3);
				if (Nodes.at(j)->_X == AroundX + i % 3 &&
					Nodes.at(j)->_Y == AroundY + i / 3)
				{
					temp = 0;
					break;
				}
			}	//이미 체크된 노드면 뛰어넘음

			if (temp == -1)
			{
				AstarNode *NewNode = new AstarNode(AroundX + i % 3, AroundY + i / 3);
				if ((i % 2) == 0)
				{
					NewNode->StackedDistance = Open.at(CenterNodeNumber)->StackedDistance + 14;
				}
				else
				{
					NewNode->StackedDistance = Open.at(CenterNodeNumber)->StackedDistance + 10;
				}

				NewNode->GoalDistance += abs(NewNode->_X - end->_X) * 10;
				NewNode->GoalDistance += abs(NewNode->_Y - end->_Y) * 10;

				NewNode->FullDistance = NewNode->StackedDistance + NewNode->GoalDistance;

				NewNode->_ParentNode = Open.at(CenterNodeNumber);

				//////
				Nodes.pushBack(NewNode);
				Open.pushBack(NewNode);

				NewNode->setPosition(Vec2(NewNode->_X * 64 + 32, NewNode->_Y * 64 + 32));
				//log("New %d %d", AroundX + i % 3, AroundY + i / 3);
				NewNode->setAnchorPoint(Vec2(0.5, 0.5));
				NewNode->setTexture("t.png");
				NewNode->setZOrder(20);
				this->addChild(NewNode);

				NewNode->ShowLabel();

				if (Board[NewNode->_X][NewNode->_Y]->_type == 2)
				{
					log("!!!");
					StartMove(Open.at(CenterNodeNumber));
					return;
				}
			}
		}

		Close.pushBack(Open.at(CenterNodeNumber));
		Open.eraseObject(Open.at(CenterNodeNumber));
	}

	log("NO PATH");
}

void HelloWorld::StartMove(AstarNode *End)
{
	if (End->_ParentNode != NULL)
	{
		StartMove(End->_ParentNode);
	}
	else
	{
		this->schedule(schedule_selector(HelloWorld::RunAction), 0.4);
	}

	End->setColor(Color3B::BLUE);
	auto Act = MoveTo::create(0.3, End->getPosition());
	MoveVec.pushBack(Act);
}

void HelloWorld::RunAction(float f)
{
	if (MoveVec.size() > 0)
	{
		Player->runAction(MoveVec.at(0));
		MoveVec.eraseObject(MoveVec.at(0));
	}
	else
	{
		auto Act = Sequence::create(
			DelayTime::create(0.3),
			MoveTo::create(0.3, GoalBlock->getPosition() + Vec2(32,32)),
			DelayTime::create(0.3),
			Spawn::create(RotateBy::create(5, 360 * 5), JumpBy::create(5, Point(0, 0), 100, 5)),
			NULL);
		Player->runAction(Act);

		this->unschedule(schedule_selector(HelloWorld::RunAction));
	}
}