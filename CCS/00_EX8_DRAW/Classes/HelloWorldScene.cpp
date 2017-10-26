#include "HelloWorldScene.h"
//#include "SimpleAudioEngine.h"

USING_NS_CC;
#define NofC 13

int SelectedIdx = 0;
bool isTempImageCreated = 0;
Color3B SelectedColor = Color3B::RED;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

	auto wlayer = LayerColor::create(Color4B(255, 255, 255, 255));
	this->addChild(wlayer);

	/////////////////////////////

	 winSize = Director::getInstance()->getWinSize();

	TableView* tableView = TableView::create(this, Size(winSize.width - 200, 100));
	tableView->setDirection(ScrollView::Direction::HORIZONTAL);
	tableView->setPosition(Vec2(120, 0));
	tableView->setBounceable(false);
	tableView->setDelegate(this);
	tableView->setTag(200);
	tableView->setZOrder(200);
	this->addChild(tableView);
	tableView->reloadData();

	CanDrawHere = Scale9Sprite::create("Images/image02.png", Rect(0, 0, 240, 160), Rect(20, 50, 20, 10));
	CanDrawHere->setAnchorPoint(Vec2(0, 0));
	CanDrawHere->setPosition(Vec2(90, 110));
	CanDrawHere->setContentSize(Size(winSize.width - 180, winSize.height/2));
	CanDrawHere->setVisible(false);
	CanDrawHere->setZOrder(100);
	this->addChild(CanDrawHere);

	auto Frame = Scale9Sprite::create("Images/image02.png", Rect(0, 0, 240, 160), Rect(20, 50, 20, 10));
	Frame->setAnchorPoint(Vec2(0, 0));
	Frame->setPosition(Vec2(80, 100));
	Frame->setContentSize(Size(winSize.width - 160, winSize.height / 2 + 20));
	Frame->setZOrder(100);
	this->addChild(Frame);

	auto sprite2 = Sprite::create("Images/image01.png");
	sprite2->setPosition(Vec2(winSize.width / 2, winSize.height / 2 + 30));
	sprite2->setZOrder(300);
	this->addChild(sprite2);

	auto sprite3 = Sprite::create("Images/image01.png");
	sprite3->setPosition(Vec2(winSize.width / 2, winSize.height / 2 + 30));
	sprite3->setZOrder(300);
	this->addChild(sprite3);

	m_pTarget = RenderTexture::create(winSize.width, winSize.height, Texture2D::PixelFormat::RGBA8888);
	m_pTarget->retain();
	m_pTarget->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
	this->addChild(m_pTarget, 1);

	clearImage(this);

	MenuItemFont::setFontSize(16);
	auto item1 = MenuItemFont::create("Save", CC_CALLBACK_1(HelloWorld::saveImage, this));
	item1->setColor(Color3B::BLACK);
	auto item2 = MenuItemFont::create("Clear", CC_CALLBACK_1(HelloWorld::clearImage, this));
	item2->setColor(Color3B::BLACK);
	auto menu = Menu::create(item1, item2, NULL);
	menu->alignItemsVertically();
	menu->setPosition(Vec2(winSize.width - 50, 30));

	this->addChild(menu, 3);

    return true;
}
HelloWorld::~HelloWorld()
{
	m_pTarget->release();
	Director::getInstance()->getTextureCache()->removeUnusedTextures();
}

void HelloWorld::onEnter()
{
	Scene::onEnter();

	listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchesMoved = CC_CALLBACK_2(HelloWorld::onTouchesMoved, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void HelloWorld::onExit()
{
	_eventDispatcher->removeEventListener(listener);
	Scene::onExit();
}

void HelloWorld::onTouchesMoved(const std::vector<Touch*>& touches, Event* event)
{
	auto touch = touches[0];
	Vec2 start = touch->getLocation();
	Vec2 end = touch->getPreviousLocation();

	m_pTarget->begin();

	float distance = start.getDistance(end);
	if (distance > 1)
	{
		int d = (int)distance;
		m_pBrush.clear();
		for (int i = 0; i < d; i++)
		{
			Sprite* sprite = Sprite::create("Images/brush2.png");
			sprite->setColor(SelectedColor);
			m_pBrush.pushBack(sprite);
		}
		for (int i = 0; i < d; i++)
		{
			float difx = end.x - start.x;
			float dify = end.y - start.y;
			float delta = (float)i / distance;
			if (CanDrawHere->getBoundingBox().containsPoint
				(Vec2(start.x + (difx * delta), start.y + (dify * delta))) == true)
			{
				m_pBrush.at(i)->setPosition(Vec2(start.x + (difx * delta), start.y + (dify * delta)));
				m_pBrush.at(i)->setRotation(rand() % 360);
				float r = (float)(rand() % 50 / 50.0f) + 0.25f;
				m_pBrush.at(i)->setScale(r);

				m_pBrush.at(i)->visit();
			}
		}
	}

	m_pTarget->end();
}

void HelloWorld::saveImage(Ref* sender)
{
	if (isTempImageCreated == 0)
	{
		isTempImageCreated = 1;

		m_pTarget->begin();
		Sprite* sprite2 = Sprite::create("Images/image01.png");
		sprite2->setPosition(Vec2(winSize.width / 2, winSize.height / 2 + 30));
		sprite2->visit();

		Sprite* sprite3 = Sprite::create("Images/image01.png");
		sprite3->setPosition(Vec2(winSize.width / 2, winSize.height / 2 + 30));
		sprite3->visit();
		m_pTarget->end();
	}

	char png[20];
	static int counter;
	sprintf(png, "image%d.png", counter);

	auto Seq = Sequence::create(
		DelayTime::create(0.01),
		CallFunc::create(CC_CALLBACK_0(HelloWorld::SmallImage, this, png))
		, NULL);
	this->runAction(Seq);

	Director::getInstance()->getRenderer()->render();
	std::string fullpath = FileUtils::getInstance()->getWritablePath() + png;
	log("Image saved %s", fullpath.c_str());
}

void HelloWorld::SmallImage(char *png)
{
	static int counter;
	sprintf(png, "image%d.png", counter);
	m_pTarget->saveToFile(png, Image::Format::PNG, true, nullptr);

	auto image = m_pTarget->newImage();
	auto text = Director::getInstance()->getTextureCache()->addImage(image, png);

	CC_SAFE_DELETE(image);

	auto sprite = Sprite::createWithTexture(text);

	sprite->setScale(0.3f);
	sprite->setPosition(Vec2(40, 40));
	sprite->setZOrder(450);
	addChild(sprite);

	counter++;
}

void HelloWorld::clearImage(Ref *sender)
{
	m_pTarget->clear(255, 255, 255, 255);
	isTempImageCreated = 0;
}

void HelloWorld::tableCellTouched(TableView* table, TableViewCell* cell)
{
	if (table->cellAtIndex(SelectedIdx))
	{
		table->cellAtIndex(SelectedIdx)->getChildByTag(SelectedIdx)->setPosition(Vec2(0, -10));
	}

	SelectedIdx = cell->getIdx();
	cell->getChildByTag(cell->getIdx())->setPosition(Vec2(0, 0));

	switch (cell->getIdx())
	{
	case 0:
		SelectedColor = Color3B::RED;
		break;
	case 1:
		SelectedColor = Color3B::ORANGE;
		break;
	case 2:
		SelectedColor = Color3B::YELLOW;
		break;
	case 3:
		SelectedColor = Color3B::GREEN;
		break;
	case 4:
		SelectedColor = Color3B::BLUE;
		break;
	case 5:
		SelectedColor = Color3B(255,101,222);
		break;
	case 6:
		SelectedColor = Color3B::MAGENTA;
		break;
	case 7:
		SelectedColor = Color3B::WHITE;
		break;
	case 8:
		SelectedColor = Color3B::BLACK;
		break;
	case 9:
		SelectedColor = Color3B::GRAY;
		break;
	case 10:
		SelectedColor = Color3B(115,65,0);
		break;
	case 11:
		SelectedColor = Color3B(255, 207, 156);
		break;
	case 12:
		SelectedColor = Color3B(255, 231, 214);
		break;
	}
}

Size HelloWorld::tableCellSizeForIndex(TableView *table, ssize_t idx)
{
	return Size(45, 83);
}

TableViewCell* HelloWorld::tableCellAtIndex(TableView *table, ssize_t idx)
{
	log("%ld", idx + 1);
	auto string = StringUtils::format("%ld", static_cast<long>(idx + 1));
	TableViewCell *cell = table->dequeueCell();

	if (!cell) {
		cell = new (std::nothrow) CustomTableViewCell();
		cell->setTag(idx);
		cell->autorelease();

		char _addr[100];
		sprintf(_addr, "Images/crayon_%02d.png", idx + 1);
		log("%s", _addr);
		auto sprite = Sprite::create(_addr);
		sprite->setAnchorPoint(Vec2::ZERO);
		sprite->setPosition(Vec2(0, -10));
		sprite->setZOrder(102);
		sprite->setScale(0.5f);
		sprite->setTag(idx);

		if (idx == SelectedIdx)
		{
			sprite->setPosition(Vec2(0, 0));
		}

		cell->addChild(sprite);
		
		auto label = Label::createWithSystemFont(string, "Helvetica", 20.0);
		label->setPosition(Vec2(5,0));
		label->setZOrder(103);
		label->setScale(1.0f);
		label->setColor(Color3B::BLACK);
		label->setAnchorPoint(Vec2::ZERO);
		cell->addChild(label);
	}
	else
	{
		cell = new (std::nothrow) CustomTableViewCell();
		cell->setTag(idx);
		cell->autorelease();

		char _addr[100];
		sprintf(_addr, "Images/crayon_%02d.png", idx + 1);
		log("%s", _addr);
		auto sprite = Sprite::create(_addr);
		sprite->setAnchorPoint(Vec2::ZERO);
		sprite->setPosition(Vec2(0, -10));
		sprite->setZOrder(102);
		sprite->setScale(0.5f);
		sprite->setTag(idx);

		if (idx == SelectedIdx)
		{
			sprite->setPosition(Vec2(0, 0));
		}

		cell->addChild(sprite);


		auto label = Label::createWithSystemFont(string, "Helvetica", 20.0);
		label->setPosition(Vec2(5,0));
		label->setZOrder(103);
		label->setScale(1.0f);
		label->setColor(Color3B::BLACK);
		label->setAnchorPoint(Vec2::ZERO);
		label->setTag(idx + 1);
		cell->addChild(label);
	}

	return cell;
}

ssize_t HelloWorld::numberOfCellsInTableView(TableView *table)
{
	return NofC;
}
