#include <assets/arm.h>
#include <system/macros.h>




void Arm::Init(Input* in, ModelGenerator* mg, Planets* plts)
{
  input = in;
  modelGen = mg;

  armXrotation = 0.0f;
  armYrotation = 0.0f;
  elbowXrotation = 0.0f;
  elbowYrotation = 0.0f;
  wristYrotation = 0.0f;
  wristOpen = -60.0f;
  speed = 25.0;

  state = ARM;
  orbits = plts;
}

// ------------------------------------------------------------------------------

void Arm::update(float dt)
{
  handleInput(dt);
  orbits->update(dt);
}

// ------------------------------------------------------------------------------

void Arm::handleInput(float dt)
{

  if(input->isKeyDown('7'))                  // if A key is pressed
  {
    // change state
    if(state != ARM)
    {
      state = ARM;
    }
  }


  if(input->isKeyDown('8'))                  // if E key is pressed
  {
    // change state
    if(state != ELBOW)
    {
      state = ELBOW;
    }
  }


  if(input->isKeyDown('9'))                  // if W key is pressed
  {
    // change state
    if(state != WRIST)
    {
      state = WRIST;
    }
  }



  if(input->isKeyDown('J'))                  // if Left arrow key is pressed
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
  }

  if(input->isKeyDown('L'))                  // if Right arrow key is pressed
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
  }

  if(input->isKeyDown('I'))                  // if Left arrow key is pressed
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
  }

  if(input->isKeyDown('K'))                  // if Right arrow key is pressed
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
  }

}

// ------------------------------------------------------------------------------

void Arm::render()
{
  glPushMatrix();  // Remember - INITIAL STATE

    glTranslatef(0.5f, 0.25f, -1.5f); // world position

    glRotatef(armYrotation, 0, 1, 0);
    glRotatef(armXrotation, 1, 0, 0);
    glRotatef(elbowYrotation, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 2.0f, 0.0f);
      
    glRotatef(elbowXrotation, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, 1.0f, 0.0f);

    glRotatef(wristYrotation, 0.0f, 1.0f, 0.0);
    glTranslatef(0.0f, 2.5f, 0.0f);

    // render orbits first, because they contain lights too
    orbits->render();

  glPopMatrix();  // Back to - INITIAL STATE
  glPushMatrix();  // Remember - INITIAL STATE

    glTranslatef(0.5f, 0.25f, -1.5f); // world position
    glRotatef(armYrotation, 0, 1, 0);
    glRotatef(armXrotation, 1, 0, 0);
    // render the SHOULDER
    //glColor3f(1.0f, 0.9f, 0.0f);
    gluSphere(gluNewQuadric(), 0.25, 12,12);

    glPushMatrix();  // Remember - SHOULDER
      
      glRotatef(elbowYrotation, 0.0f, 1.0f, 0.0f);
      glTranslatef(0.0f, 1.0f, 0.0f);

      glPushMatrix();  // Remember - ARM
        glScalef(0.5f, 1.6f, 0.5f);
        //render arm
        glColor3f(0.8f, 0.1f, 0.1f);
        drawCube();
      glPopMatrix();  // Back to - ARM

      // render elbow
      glTranslatef(0.0f, 1.0f, 0.0f);
      glColor3f(1.0f, 1.0f, 1.0f);
      gluSphere(gluNewQuadric(), 0.25, 12,12);

      
      glRotatef(elbowXrotation, 1.0f, 0.0f, 0.0f);
      glTranslatef(0.0f, 1.0f, 0.0f);

      glPushMatrix();  // Remember - FOREARM
        glScalef(0.5f, 1.6f, 0.5f);
        // render forearm
        glColor3f(0.8f, 0.1f, 0.1f);
        drawCube();
      glPopMatrix();  // Back to - FOREARM

      // render wrist
      glRotatef(wristYrotation, 0.0f, 1.0f, 0.0);
      glTranslatef(0.0f, 1.0f, 0.0f);
      glColor3f(1.0f, 1.0f, 1.0f);
      gluSphere(gluNewQuadric(), 0.25, 12,12);

      glPushMatrix();  // Remember - WRIST

        //Render Finger1
        glRotatef(wristOpen, 0.0f, 0.0f, 1.0f);
        drawFinger();

      glPopMatrix();  // Back to - WRIST
      glPushMatrix();  // Remember - WRIST

        //Render Finger2
        glRotatef(120,0,1,0);
        glRotatef(wristOpen, 0.0f, 0.0f, 1.0f);
        drawFinger();

      glPopMatrix();  // Back to - WRIST
      glPushMatrix();  // Remember - WRIST

        glRotatef(240.0f, 0.0f, 1.0f, 0.0f);
        glRotatef(wristOpen, 0.0f, 0.0f, 1.0f);
        drawFinger();

      glPopMatrix();  // Back to - WRIST
      //glPushMatrix();  // Remember - WRIST

      //  glTranslatef(1.0f, 1.5f, 0.0f);
      //  orbits->render();

      //glPopMatrix();  // Back to - WRIST

    glPopMatrix();  // Back to - SHOULDER

  glPopMatrix();  // Back to - INITIAL STATE

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
  glScalef(0.2f, 0.2f, 0.2f);
  //render finger
        
  glTranslatef(0.0f, 2.0f, 0.0f);
  glScalef(0.5f, 1.6f, 0.5f);
  glColor3f(0.8f, 0.1f, 0.1f);
  drawCube();

  // render elbow
  glTranslatef(0.0f, 0.625f, 0.0f);
  glColor3f(1.0f, 1.0f, 1.0f);
  glScalef(2.0f, 0.625f, 2.0f);
  gluSphere(
      gluNewQuadric(), 0.25, 40,40);

  // render forearm
  glRotatef(60.0f, 0.0f, 0.0f, 1.0f);
  glTranslatef(0.0f, 1.0f, 0.0f);
  glScalef(0.5f, 1.6f, 0.5f);
  glColor3f(0.8f, 0.1f, 0.1f);
  // is there glCube primitive? [like gluSphere()]
  drawCube();




}