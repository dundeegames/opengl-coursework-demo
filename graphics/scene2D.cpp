#include "scene2D.h"

void Scene::Initialise(HWND *lwnd, Input *in)
{
	hwnd = lwnd;	// access to the window
	myInput = in;	// access to user input

	ticker = 0;	// used for moving object

	// configure buffers, based on window device context
	setBuffers();


	// create our sprite, passing a filename for image to load, and starting location
	mySprite.Initialise(TRANSP, "transicon2.bmp", 100, 100, &bitmapHDC, &backHDC);

	wallPaper.Initialise(NORMAL, "800x450HH.bmp",0,0, &bitmapHDC, &backHDC);



}

void Scene::setBuffers()
{
    // creates rect based on window client area
    GetClientRect(*hwnd, &screenRect); 
    
	// Initialises front buffer device context (window)
    frontHDC = GetDC(*hwnd);
    
	// sets up Back DC to be compatible with the front
    backHDC = CreateCompatibleDC(frontHDC);

	bitmapHDC = CreateCompatibleDC(backHDC);

    //creates bitmap compatible with the front buffer
    theOldFrontBitMap = CreateCompatibleBitmap(frontHDC, screenRect.right, screenRect.bottom); 
    
	// puts the bitmap onto the back buffer
    SelectObject(backHDC, theOldFrontBitMap); 
    
	// blank back buffer
    FillRect(backHDC, &screenRect, (HBRUSH)GetStockObject(0));
}

void Scene::render()
{
	if (WaitFor(5))
	{
		wallPaper.drawSprite();
		mySprite.drawSprite();
		// send sprite to drawSprite function

		//finally push to screen
		displayFrame();
	}

}

/*
void Scene::drawSprite(Sprite theSprite)
{
	HBITMAP originalBitMap;

	//remember to add the bitmapHDC to scene.h
	originalBitMap = (HBITMAP)SelectObject(bitmapHDC, theSprite.bitmap);
	
	// blt the image to the back buffer
	BitBlt(backHDC, theSprite.x, theSprite.y, theSprite.width, 	theSprite.height, bitmapHDC, 0, 0, SRCCOPY);

	SelectObject(bitmapHDC, originalBitMap); 
}
*/

void Scene::displayFrame()
{
    BitBlt(frontHDC, screenRect.left,screenRect.top, screenRect.right, screenRect.bottom, backHDC, 0, 0, SRCCOPY);

    FillRect(backHDC, &screenRect, (HBRUSH)GetStockObject(0));


	//drawSprite(wallPaper);
	//drawSprite(mySprite);
}

void Scene::shutdown()
{
    SelectObject(backHDC,theOldFrontBitMap);
    DeleteDC(backHDC);
    ReleaseDC(*hwnd,frontHDC);
}

BOOL Scene::WaitFor(unsigned long delay)
{
	static unsigned long clockStart = 0;
	unsigned long timePassed;
	unsigned long now = timeGetTime();

	timePassed = now - clockStart;
	if (timePassed >  delay)
	{
		clockStart = now;
		return TRUE;
	}
	else
		return FALSE;
}


void Scene::update()
{

	mySprite.x = myInput->getMouseX();
	mySprite.y = myInput->getMouseY();

	// move sprite
	if(mySprite.x > (screenRect.right - mySprite.width))
	{
		mySprite.x = (screenRect.right - mySprite.width);
	}
	else if(mySprite.x < screenRect.left)
	{
		mySprite.x = screenRect.left;
	}

	if(mySprite.y < screenRect.top)
	{
		mySprite.y = screenRect.top;
	}
	else if(mySprite.y > (screenRect.bottom - mySprite.height))
	{
		mySprite.y = (screenRect.bottom - mySprite.height);
	}


	Scene::render();


}