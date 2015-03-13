// Arm class
// Jiri Klic 2014

#include <assets/arm.h>
#include <gl/gl.h>
#include <gl/glu.h>

#define WRIST_MAXCLOSE -28.0
#define WRIST_MAXOPEN -60.0
#define ELBOW_MAXROTATION 70.0
#define ELBOW_MINROTATION -70.0


void Arm::Init(Input* in)
{
  input = in;

  armXrotation = 0.0f;
  armYrotation = 0.0f;
  elbowXrotation = 0.0f;
  elbowYrotation = 0.0f;
  wristYrotation = 0.0f;
  wristOpen = -60.0f;
  speed = 25.0;

  state = ARM;
}

// ------------------------------------------------------------------------------

void Arm::update(float dt)
{
  handleInput(dt);
}

// ------------------------------------------------------------------------------

void Arm::handleInput(float dt)
{

  if(input->isKeyDown('I'))                  // if A key is pressed
  {
    // change state
    if(state != ARM)
    {
      state = ARM;
    }
    //input->SetKeyUp('A');                  //force un-pressing of A key
  }


  if(input->isKeyDown('O'))                  // if E key is pressed
  {
    // change state
    if(state != ELBOW)
    {
      state = ELBOW;
    }
    //input->SetKeyUp('E');                  //force un-pressing of E key
  }


  if(input->isKeyDown('P'))                  // if W key is pressed
  {
    // change state
    if(state != WRIST)
    {
      state = WRIST;
    }
    //input->SetKeyUp('W');                  //force un-pressing of W key
  }



  if(input->isKeyDown(VK_LEFT))                  // if Left arrow key is pressed
  {
    switch(state)
    {
    case ARM:
      armYrotation -= speed*dt;
      break;

    case ELBOW:
      elbowYrotation -= speed*dt;
      break;

    case WRIST:
      wristYrotation -= 2*speed*dt;
      break;

    default:
      break;
    }
      
    //input->SetKeyUp(VK_LEFT);                  //force un-pressing of Left arrow key
  }

  if(input->isKeyDown(VK_RIGHT))                  // if Right arrow key is pressed
  {
    switch(state)
    {
    case ARM:
      armYrotation += speed*dt;
      break;

    case ELBOW:
      elbowYrotation += speed*dt;
      break;

    case WRIST:
      wristYrotation += 2*speed*dt;
      break;

    default:
      break;
    }    
          
    //input->SetKeyUp(VK_RIGHT);                  //force un-pressing of Right arrow key
  }

  if(input->isKeyDown(VK_UP))                  // if Left arrow key is pressed
  {
    switch(state)
    {
    case ARM:
      armXrotation -= speed*dt;
      break;

    case ELBOW:
      if(elbowXrotation > ELBOW_MINROTATION)
      {
        elbowXrotation -= speed*dt;
      }
      break;

    case WRIST:
      if(wristOpen > WRIST_MAXOPEN)
      {
        wristOpen -= 2*speed*dt;
      }
      break;

    default:
      break;
    }    
      
    //input->SetKeyUp(VK_UP);                  //force un-pressing of Left arrow key
  }

  if(input->isKeyDown(VK_DOWN))                  // if Right arrow key is pressed
  {
    switch(state)
    {
    case ARM:
      armXrotation += speed*dt;
      break;

    case ELBOW:
      if(elbowXrotation < ELBOW_MAXROTATION)
      {
        elbowXrotation += speed*dt;
      }      
      break;

    case WRIST:
      if(wristOpen < WRIST_MAXCLOSE)
      {
        wristOpen += 2*speed*dt;
      }
      break;

    default:
      break;
    }    
          
    //input->SetKeyUp(VK_DOWN);                  //force un-pressing of Right arrow key
  }

}

// ------------------------------------------------------------------------------

void Arm::render()
{


  glPushMatrix();  // Remember where we are.  THE SHOULDER
    glRotatef(armYrotation, 0, 1, 0);
    glRotatef(armXrotation, 1, 0, 0);
    // render the SHOULDER
    //glColor3f(1.0f, 0.9f, 0.0f);
    gluSphere(gluNewQuadric(), 0.25, 12,12);

    glPushMatrix();
      //render arm
      //glRotatef(rotation,0,0.5,0.5);    
      glRotatef(elbowYrotation, 0, 1, 0);
      glTranslatef(0,1,0);
      glScalef(0.5, 1.6, 0.5);
      glColor3f(0.8f, 0.1f, 0.1f);
      drawCube();

      // render elbow
      glTranslatef(0,0.625,0);
      glColor3f(1.0f, 1.0f, 1.0f);
      glScalef(2.0f, 0.625f, 2.0f);
      gluSphere(gluNewQuadric(), 0.25, 12,12);

      // render forearm
      glRotatef(elbowXrotation, 1, 0, 0);
      glTranslatef(0,1,0);
      glScalef(0.5, 1.6, 0.5);
      glColor3f(0.8f, 0.1f, 0.1f);
      // is there glCube primitive? [like gluSphere()]
      drawCube();

      // scaling to compensate for previous scaling? Ask for more efficient method
      // render wrist
      glRotatef(wristYrotation, 0, 1, 0);
      glTranslatef(0,0.625,0);
      glColor3f(1.0f, 1.0f, 1.0f);
      glScalef(2.0f, 0.625f, 2.0f);
      gluSphere(gluNewQuadric(), 0.25, 12,12);
      glPushMatrix();  // Remember where we are.  THE WRIST

        //Render Finger1
        glRotatef(wristOpen,0,0,1);
        drawFinger();
      glPopMatrix();  // GO BACK TO WRIST
      glPushMatrix(); // REMEMBER WHERE WE ARE
        //Render Finger2
        glRotatef(120,0,1,0);
        glRotatef(wristOpen,0,0,1);
        drawFinger();
      glPopMatrix();  // GO BACK TO WRIST
      glPushMatrix(); // REMEMBER WHERE WE ARE
        glRotatef(240,0,1,0);
        glRotatef(wristOpen,0,0,1);
        drawFinger();          
  glPopMatrix();//GO BACK TO SHOULDER
}

// ------------------------------------------------------------------------------

void Arm::drawCube()
{
  glBegin(GL_QUADS);

    // front face
    glNormal3f(0.0f, 0.0f, 1.0f); 
    glVertex3f(-0.5f, 0.5f, 0.5f);

    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.5f, 0.5f, 0.5f);

    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.5f, -0.5f, 0.5f);

    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-0.5f, -0.5f, 0.5f);

    // back face
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(0.5f, 0.5f, -0.5f);

    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(-0.5f, 0.5f, -0.5f);

    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f);

    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    
    // right face
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.5f, 0.5f, 0.5f);

    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.5f, 0.5f, -0.5f);

    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, -0.5f);

    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.5f);

    // left face
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-0.5f, 0.5f, -0.5f);

    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-0.5f, 0.5f, 0.5f);

    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, 0.5f);

    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
  
    // bottom face
    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.5f);

    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, -0.5f);

    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f);

    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, 0.5f);

    // top face
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.5f, 0.5f, -0.5f);

    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.5f, 0.5f, 0.5f);

    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-0.5f, 0.5f, 0.5f);

    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    

  glEnd();

}

// ------------------------------------------------------------------------------

void Arm::drawFinger()
{
  glScalef(0.2, 0.2, 0.2);
  //render finger
        
  glTranslatef(0,2,0);
  glScalef(0.5, 1.6, 0.5);
  glColor3f(0.8f, 0.1f, 0.1f);
  drawCube();

  // render elbow
  glTranslatef(0,0.625,0);
  glColor3f(1.0f, 1.0f, 1.0f);
  glScalef(2.0f, 0.625f, 2.0f);
  gluSphere(
      gluNewQuadric(), 0.25, 40,40);

  // render forearm
  glRotatef(60, 0, 0, 1);
  glTranslatef(0,1,0);
  glScalef(0.5, 1.6, 0.5);
  glColor3f(0.8f, 0.1f, 0.1f);
  // is there glCube primitive? [like gluSphere()]
  drawCube();




}