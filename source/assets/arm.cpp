#include <assets/arm.h>
#include <system/macros.h>




void Arm::Init(Input* in, ModelGenerator* mg)
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
  orbits.init();
}

// ------------------------------------------------------------------------------

void Arm::update(float dt)
{
  handleInput(dt);
  orbits.update(dt);
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


  glPushMatrix();  // Remember where we are.  THE SHOULDER
    glTranslatef(0.5f, 0.25f, -1.5f);

    glRotatef(armYrotation, 0, 1, 0);
    glRotatef(armXrotation, 1, 0, 0);
    // render the SHOULDER
    //glColor3f(1.0f, 0.9f, 0.0f);
    gluSphere(gluNewQuadric(), 0.25, 12,12);

    glPushMatrix();   // Remember where we are.  THE ELBOW
      //render arm
      //glRotatef(rotation,0,0.5,0.5);    
      glRotatef(elbowYrotation, 0.0f, 1.0f, 0.0f);
      glTranslatef(0.0f, 1.0f, 0.0f);
      glScalef(0.5f, 1.6f, 0.5f);
      glColor3f(0.8f, 0.1f, 0.1f);
      drawCube();

      // render elbow
      glTranslatef(0.0f, 0.625f, 0.0f);
      glColor3f(1.0f, 1.0f, 1.0f);
      glScalef(2.0f, 0.625f, 2.0f);
      gluSphere(gluNewQuadric(), 0.25, 12,12);

      // render forearm
      glRotatef(elbowXrotation, 1.0f, 0.0f, 0.0f);
      glTranslatef(0.0f, 1.0f, 0.0f);
      glScalef(0.5f, 1.6f, 0.5f);
      glColor3f(0.8f, 0.1f, 0.1f);
      // is there glCube primitive? [like gluSphere()]
      drawCube();

      // scaling to compensate for previous scaling? Ask for more efficient method
      // render wrist
      glRotatef(wristYrotation, 0.0f, 1.0f, 0.0);
      glTranslatef(0.0f, 0.625f, 0.0f);
      glColor3f(1.0f, 1.0f, 1.0f);
      glScalef(2.0f, 0.625f, 2.0f);
      gluSphere(gluNewQuadric(), 0.25, 12,12);

        glPushMatrix();  // Remember where we are.  THE WRIST

          //Render Finger1
          glRotatef(wristOpen, 0.0f, 0.0f, 1.0f);
          drawFinger();
        glPopMatrix();  // GO BACK TO WRIST

        glPushMatrix(); // REMEMBER WHERE WE ARE
          //Render Finger2
          glRotatef(120,0,1,0);
          glRotatef(wristOpen, 0.0f, 0.0f, 1.0f);
          drawFinger();
        glPopMatrix();  // GO BACK TO WRIST

        glPushMatrix(); // REMEMBER WHERE WE ARE
          glRotatef(240.0f, 0.0f, 1.0f, 0.0f);
          glRotatef(wristOpen, 0.0f, 0.0f, 1.0f);
          drawFinger();          
        glPopMatrix();//GO BACK TO WRIST

        glPushMatrix(); // REMEMBER WHERE WE ARE
          glTranslatef(1.0f, 1.5f, 0.0f);
          //glScalef(0.75f, 0.75f, 0.75f);
          orbits.render();          
        glPopMatrix();//GO BACK TO WRIST

    glPopMatrix();//GO BACK TO ELBOW

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