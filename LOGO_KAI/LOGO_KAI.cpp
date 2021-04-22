#include <gl\glut.h>
#include <stdlib.h>
#include <windows.h>
GLfloat angle_o = 0, angle_l = 0;
GLfloat step_o = 0, step_l = 0;
GLint direction = 1;
GLfloat z = 0.25;
GLint direction_object_x = 0;
GLint direction_object_y = 0;
GLint camera_x = 0;
GLint camera_y = 0;
GLint camera_z = 15;
GLint axis = 0;

void init(void)
{
	glClearColor(0.9, 0.9, 0.9, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 25);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void Keyboard(unsigned char key, int x, int y)
{
	if (key == '1')
	{
		if (step_o == 0)
		{
			step_o = 1;
			direction_object_x = 0;
			direction_object_y = 1;
			return;
		}
		if (step_o == 1)
		{
			step_o = 0;
			return;
		}
	}
	if (key == '2')
	{
		if (step_o == 0)
		{
			step_o = 1;
			direction_object_y = 0;
			direction_object_x = 1;
			return;
		}
		if (step_o == 1)
		{
			step_o = 0;
			return;
		}
	}
	if (key == 'e' || key == 'E')
	{
		if (axis == 0)
		{
			axis = 1;
			return;
		}
		if (axis == 1)
		{
			axis = 0;
			return;
		}
	}
	if (key == 'w' || key == 'W')
	{
		camera_z--;
		return;
	}
	if (key == 's' || key == 'S')
	{
		camera_z++;
		return;
	}
	if (key == 'a' || key == 'А')
	{
		camera_x--;
		return;
	}
	if (key == 'd' || key == 'D')
	{
		camera_x++;
		return;
	}
	if (key == 'x' || key == 'X')
	{
		camera_y++;
		return;
	}
	if (key == 'z' || key == 'Z')
	{
		camera_y--;
		return;
	}
	if (key == 'L' || key == 'l')
	{
		if (step_l == 0)
		{
			step_l = 3;
			return;
		}
		if (step_l == 3)
		{
			step_l = 0;
			return;
		}
	}
	if (key == 'F' || key == 'f')
	{
		glCullFace(GL_BACK);
		glEnable(GL_CULL_FACE);
	}
	if (key == 'B' || key == 'b')
	{
		glCullFace(GL_FRONT);
		glEnable(GL_CULL_FACE);
	}
}

void myDisplay()
{
	glPushMatrix(); //Сохраняем VM = 1
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	gluLookAt(camera_x, camera_y, camera_z, 0, 0, 0, 0, 1, 0); // VM=Fwe
	glPushMatrix();
	glRotatef(angle_l, 0, 1, 0);
	GLfloat myLightPosition[] = { 0, 4, 8, 1 };
	glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition);
	glEnable(GL_LIGHTING); // Включение расчета освещенности
	glEnable(GL_LIGHT0); // включаем этот конкретный источник
	glPopMatrix();

	GLfloat myAmbient[] = { 0.25, 0.25, 0.25, 1 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, myAmbient);
	GLfloat myDiffuse[] = { 0.9, 0.01, 0.01, 1 };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, myDiffuse);
	GLfloat mySpecular[] = { 0.774597, 0.774597, 0.774597, 1 };
	glMaterialfv(GL_FRONT, GL_SPECULAR, myDiffuse);
	GLfloat myShininess[] = { 50 };
	glMaterialfv(GL_FRONT, GL_SHININESS, myShininess);
#pragma region КАИ
	glPushMatrix();
	glRotatef(angle_o, direction_object_x, direction_object_y, 0);

#pragma region K
	// +Левая часть K
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(-3, -1, z);
	glVertex3f(-2.5, -1, z);
	glVertex3f(-2.5, 1, z);
	glVertex3f(-3, 1, z);
	glEnd();

	// +Правый верх K
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(-2.5, 0, z);
	glVertex3f(-2.1, 0, z);
	glVertex3f(-1.5, 1, z);
	glVertex3f(-2, 1, z);
	glVertex3f(-2.5, 0.25, z);
	glEnd();

	// +Правый низ K
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(-2.5, 0, z);
	glVertex3f(-2.5, -0.25, z);
	glVertex3f(-2, -1, z);
	glVertex3f(-1.5, -1, z);
	glVertex3f(-2.1, 0, z);
	glEnd();

	// -Левая часть K
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(-3, -1, -z);
	glVertex3f(-3, 1, -z);
	glVertex3f(-2.5, 1, -z);
	glVertex3f(-2.5, -1, -z);
	glEnd();

	// -Правый верх K
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(-2.5, 0, -z);
	glVertex3f(-2.5, 0.25, -z);
	glVertex3f(-2, 1, -z);
	glVertex3f(-1.5, 1, -z);
	glVertex3f(-2.1, 0, -z);
	glEnd();

	// -Правый низ K
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(-2.5, 0, -z);
	glVertex3f(-2.1, 0, -z);
	glVertex3f(-1.5, -1, -z);
	glVertex3f(-2, -1, -z);
	glVertex3f(-2.5, -0.25, -z);
	glEnd();

	// Левый бок K
	glBegin(GL_POLYGON);
	glNormal3f(-1, 0, 0);
	glVertex3f(-3, -1, -z);
	glVertex3f(-3, -1, z);
	glVertex3f(-3, 1, z);
	glVertex3f(-3, 1, -z);
	glEnd();

	// Внутренний левый верхний бок K
	glBegin(GL_POLYGON);
	glNormal3f(1, 0, 0);
	glVertex3f(-2.5, 0.25, z);
	glVertex3f(-2.5, 0.25, -z);
	glVertex3f(-2.5, 1, -z);
	glVertex3f(-2.5, 1, z);
	glEnd();

	// Внутренний левый нижний бок K
	glBegin(GL_POLYGON);
	glNormal3f(1, 0, 0);
	glVertex3f(-2.5, -0.25, z);
	glVertex3f(-2.5, -1, z);
	glVertex3f(-2.5, -1, -z);
	glVertex3f(-2.5, -0.25, -z);
	glEnd();

	// Внутренний правый верхний бок K
	glBegin(GL_POLYGON);
	glNormal3f(-3, 2, 0);
	glVertex3f(-2.5, 0.25, -z);
	glVertex3f(-2.5, 0.25, z);
	glVertex3f(-2, 1, z);
	glVertex3f(-2, 1, -z);
	glEnd();

	// Внутренний правый нижний бок K
	glBegin(GL_POLYGON);
	glNormal3f(-3, -2, 0);
	glVertex3f(-2.5, -0.25, -z);
	glVertex3f(-2, -1, -z);
	glVertex3f(-2, -1, z);
	glVertex3f(-2.5, -0.25, z);
	glEnd();

	// Внешний верхний правый бок K
	glBegin(GL_POLYGON);
	glNormal3f(10, -6, 0);
	glVertex3f(-2.1, 0, z);
	glVertex3f(-2.1, 0, -z);
	glVertex3f(-1.5, 1, -z);
	glVertex3f(-1.5, 1, z);
	glEnd();

	// Внешний нижний правый бок K
	glBegin(GL_POLYGON);
	glNormal3f(10, 6, 0);
	glVertex3f(-2.1, 0, z);
	glVertex3f(-1.5, -1, z);
	glVertex3f(-1.5, -1, -z);
	glVertex3f(-2.1, 0, -z);
	glEnd();

	// Левый верх K
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(-3, 1, z);
	glVertex3f(-2.5, 1, z);
	glVertex3f(-2.5, 1, -z);
	glVertex3f(-3, 1, -z);
	glEnd();

	// Правый верх K
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(-2, 1, z);
	glVertex3f(-1.5, 1, z);
	glVertex3f(-1.5, 1, -z);
	glVertex3f(-2, 1, -z);
	glEnd();

	// Левый низ K
	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(-3, -1, z);
	glVertex3f(-3, -1, -z);
	glVertex3f(-2.5, -1, -z);
	glVertex3f(-2.5, -1, z);
	glEnd();

	// Правый низ K
	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(-2, -1, z);
	glVertex3f(-2, -1, -z);
	glVertex3f(-1.5, -1, -z);
	glVertex3f(-1.5, -1, z);
	glEnd();
#pragma endregion

#pragma region A
	// +Левая часть А
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(-0.25, 1, z);
	glVertex3f(-1, -1, z);
	glVertex3f(-0.5, -1, z);
	glVertex3f(0, 0.25, z);
	glVertex3f(0, 1, z);
	glEnd();

	// +Правая часть А
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(0, 1, z);
	glVertex3f(0, 0.25, z);
	glVertex3f(0.5, -1, z);
	glVertex3f(1, -1, z);
	glVertex3f(0.25, 1, z);
	glEnd();

	// +Середина А
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(0.1, 0, z);
	glVertex3f(-0.1, 0, z);
	glVertex3f(-0.3, -0.5, z);
	glVertex3f(0.3, -0.5, z);
	glEnd();

	// -Левая часть А
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(-0.25, 1, -z);
	glVertex3f(0, 1, -z);
	glVertex3f(0, 0.25, -z);
	glVertex3f(-0.5, -1, -z);
	glVertex3f(-1, -1, -z);
	glEnd();

	// -Правая часть А
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(0, 1, -z);
	glVertex3f(0.25, 1, -z);
	glVertex3f(1, -1, -z);
	glVertex3f(0.5, -1, -z);
	glVertex3f(0, 0.25, -z);
	glEnd();

	// -Середина А
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(0.1, 0, -z);
	glVertex3f(0.3, -0.5, -z);
	glVertex3f(-0.3, -0.5, -z);
	glVertex3f(-0.1, 0, -z);
	glEnd();

	// Левая боковина А
	glBegin(GL_POLYGON);
	glNormal3f(-8, 3, 0);
	glVertex3f(-0.25, 1, -z);
	glVertex3f(-1, -1, -z);
	glVertex3f(-1, -1, z);
	glVertex3f(-0.25, 1, z);
	glEnd();

	// Правая боковина А
	glBegin(GL_POLYGON);
	glNormal3f(8, 3, 0);
	glVertex3f(0.25, 1, -z);
	glVertex3f(0.25, 1, z);
	glVertex3f(1, -1, z);
	glVertex3f(1, -1, -z);
	glEnd();

	// Вершина А
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(-0.25, 1, -z);
	glVertex3f(-0.25, 1, z);
	glVertex3f(0.25, 1, z);
	glVertex3f(0.25, 1, -z);
	glEnd();

	// Левый низ А
	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(-1, -1, -z);
	glVertex3f(-0.5, -1, -z);
	glVertex3f(-0.5, -1, z);
	glVertex3f(-1, -1, z);
	glEnd();

	// Правый низ А
	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(1, -1, -z);
	glVertex3f(1, -1, z);
	glVertex3f(0.5, -1, z);
	glVertex3f(0.5, -1, -z);
	glEnd();

	// Левый внутренний нижний бок А
	glBegin(GL_POLYGON);
	glNormal3f(8, -3, 0);
	glVertex3f(-0.3, -0.5, z);
	glVertex3f(-0.5, -1, z);
	glVertex3f(-0.5, -1, -z);
	glVertex3f(-0.3, -0.5, -z);
	glEnd();

	// Правый внутренний нижний бок А
	glBegin(GL_POLYGON);
	glNormal3f(-8, -3, 0);
	glVertex3f(0.3, -0.5, z);
	glVertex3f(0.3, -0.5, -z);
	glVertex3f(0.5, -1, -z);
	glVertex3f(0.5, -1, z);
	glEnd();

	// Низ середины А
	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(-0.3, -0.5, z);
	glVertex3f(-0.3, -0.5, -z);
	glVertex3f(0.3, -0.5, -z);
	glVertex3f(0.3, -0.5, z);
	glEnd();

	// Верх середины А
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(-0.1, 0, z);
	glVertex3f(0.1, 0, z);
	glVertex3f(0.1, 0, -z);
	glVertex3f(-0.1, 0, -z);
	glEnd();

	// Левый внутренний верхний бок А
	glBegin(GL_POLYGON);
	glNormal3f(8, -3, 0);
	glVertex3f(-0.1, 0, z);
	glVertex3f(-0.1, 0, -z);
	glVertex3f(0, 0.25, -z);
	glVertex3f(0, 0.25, z);
	glEnd();

	// Правый внутренний верхний бок А
	glBegin(GL_POLYGON);
	glNormal3f(-8, -3, 0);
	glVertex3f(0.1, 0, z);
	glVertex3f(0, 0.25, z);
	glVertex3f(0, 0.25, -z);
	glVertex3f(0.1, 0, -z);
	glEnd();
#pragma endregion

#pragma region И
	// +Левая часть И
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(1.5, -1, z);
	glVertex3f(2, -1, z);
	glVertex3f(2, 1, z);
	glVertex3f(1.5, 1, z);
	glEnd();

	// +Правая часть И
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(2.5, -1, z);
	glVertex3f(3, -1, z);
	glVertex3f(3, 1, z);
	glVertex3f(2.5, 1, z);
	glEnd();

	// +Середина И
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(2, -1, z);
	glVertex3f(2.5, 0, z);
	glVertex3f(2.5, 1, z);
	glVertex3f(2, 0, z);
	glEnd();

	// -Левая часть И
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(1.5, -1, -z);
	glVertex3f(1.5, 1, -z);
	glVertex3f(2, 1, -z);
	glVertex3f(2, -1, -z);
	glEnd();

	// -Правая часть И
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(2.5, -1, -z);
	glVertex3f(2.5, 1, -z);
	glVertex3f(3, 1, -z);
	glVertex3f(3, -1, -z);
	glEnd();

	// -Середина И
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(2, -1, -z);
	glVertex3f(2, 0, -z);
	glVertex3f(2.5, 1, -z);
	glVertex3f(2.5, 0, -z);
	glEnd();

	// Левый внешний бок И
	glBegin(GL_POLYGON);
	glNormal3f(-1, 0, 0);
	glVertex3f(1.5, -1, -z);
	glVertex3f(1.5, -1, z);
	glVertex3f(1.5, 1, z);
	glVertex3f(1.5, 1, -z);
	glEnd();

	// Правый внешний бок И
	glBegin(GL_POLYGON);
	glNormal3f(1, 0, 0);
	glVertex3f(3, -1, z);
	glVertex3f(3, -1, -z);
	glVertex3f(3, 1, -z);
	glVertex3f(3, 1, z);
	glEnd();

	// Левый внутренний бок И
	glBegin(GL_POLYGON);
	glNormal3f(1, 0, 0);
	glVertex3f(2, 0, z);
	glVertex3f(2, 0, -z);
	glVertex3f(2, 1, -z);
	glVertex3f(2, 1, z);
	glEnd();

	// Правый внутренний бок И
	glBegin(GL_POLYGON);
	glNormal3f(-1, 0, 0);
	glVertex3f(2.5, 0, -z);
	glVertex3f(2.5, -1, -z);
	glVertex3f(2.5, -1, z);
	glVertex3f(2.5, 0, z);
	glEnd();

	// Верхняя середина И
	glBegin(GL_POLYGON);
	glNormal3f(-2, 1, 0);
	glVertex3f(2, 0, -z);
	glVertex3f(2, 0, z);
	glVertex3f(2.5, 1, z);
	glVertex3f(2.5, 1, -z);
	glEnd();

	// Нижняя середина И
	glBegin(GL_POLYGON);
	glNormal3f(2, -1, 0);
	glVertex3f(2.5, 0, z);
	glVertex3f(2, -1, z);
	glVertex3f(2, -1, -z);
	glVertex3f(2.5, 0, -z);
	glEnd();

	// Левый верх И
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(1.5, 1, -z);
	glVertex3f(1.5, 1, z);
	glVertex3f(2, 1, z);
	glVertex3f(2, 1, -z);
	glEnd();

	// Правый верх И
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(2.5, 1, -z);
	glVertex3f(2.5, 1, z);
	glVertex3f(3, 1, z);
	glVertex3f(3, 1, -z);
	glEnd();

	// Левый низ И
	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(1.5, -1, z);
	glVertex3f(1.5, -1, -z);
	glVertex3f(2, -1, -z);
	glVertex3f(2, -1, z);
	glEnd();

	// Правый низ И
	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(2.5, -1, z);
	glVertex3f(2.5, -1, -z);
	glVertex3f(3, -1, -z);
	glVertex3f(3, -1, z);
	glEnd();


#pragma endregion
#pragma region ромб
	GLfloat myDiffuse2[] = { 0, 0, 1, 1 };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, myDiffuse2);


	// фронтальная часть
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(-1.25, 0, 0.1);
	glVertex3f(0, -2, 0.1);
	glVertex3f(1.25, 0, 0.1);
	glVertex3f(0, 2, 0.1);
	glEnd();

	// задняя часть
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(-1.25, 0, -0.1);
	glVertex3f(0, 2, -0.1);
	glVertex3f(1.25, 0, -0.1);
	glVertex3f(0, -2, -0.1);
	glEnd();

	// левый верхний бок
	glBegin(GL_POLYGON);
	glNormal3f(-8, 5, 0);
	glVertex3f(-1.25, 0, -0.1);
	glVertex3f(-1.25, 0, 0.1);
	glVertex3f(0, 2, 0.1);
	glVertex3f(0, 2, -0.1);
	glEnd();

	// левый низ бок
	glBegin(GL_POLYGON);
	glNormal3f(-8, -5, 0);
	glVertex3f(-1.25, 0, -0.1);
	glVertex3f(0, -2, -0.1);
	glVertex3f(0, -2, 0.1);
	glVertex3f(-1.25, 0, 0.1);
	glEnd();

	// правый верхний бок
	glBegin(GL_POLYGON);
	glNormal3f(8, 5, 0);
	glVertex3f(1.25, 0, 0.1);
	glVertex3f(1.25, 0, -0.1);
	glVertex3f(0, 2, -0.1);
	glVertex3f(0, 2, 0.1);
	glEnd();

	// правый низ бок
	glBegin(GL_POLYGON);
	glNormal3f(8, -5, 0);
	glVertex3f(1.25, 0, -0.1);
	glVertex3f(1.25, 0, 0.1);
	glVertex3f(0, -2, 0.1);
	glVertex3f(0, -2, -0.1);
	glEnd();
#pragma endregion
#pragma region 1 крылья
	// +Левое 1 крыло
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(-4, -1.25, 0.1);
	glVertex3f(-3.5, -1.75, 0.1);
	glVertex3f(-1.5, -1.75, 0.1);
	glVertex3f(-1, -1.25, 0.1);
	glEnd();

	// -Левое 1 крыло
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(-4, -1.25, -0.1);
	glVertex3f(-1, -1.25, -0.1);
	glVertex3f(-1.5, -1.75, -0.1);
	glVertex3f(-3.5, -1.75, -0.1);
	glEnd();

	// Левый бок
	glBegin(GL_POLYGON);
	glNormal3f(-4, -4, 1);
	glVertex3f(-4, -1.25, 0.1);
	glVertex3f(-4, -1.25, -0.1);
	glVertex3f(-3.5, -1.75, -0.1);
	glVertex3f(-3.5, -1.75, 0.1);
	glEnd();

	// Правый бок
	glBegin(GL_POLYGON);
	glNormal3f(4, -4, 1);
	glVertex3f(-1.5, -1.75, -0.1);
	glVertex3f(-1, -1.25, -0.1);
	glVertex3f(-1, -1.25, 0.1);
	glVertex3f(-1.5, -1.75, 0.1);
	glEnd();

	// Верх
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(-4, -1.25, -0.1);
	glVertex3f(-4, -1.25, 0.1);
	glVertex3f(-1, -1.25, 0.1);
	glVertex3f(-1, -1.25, -0.1);
	glEnd();

	// Низ
	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(-3.5, -1.75, 0.1);
	glVertex3f(-3.5, -1.75, -0.1);
	glVertex3f(-1.5, -1.75, -0.1);
	glVertex3f(-1.5, -1.75, 0.1);
	glEnd();

	/*==================================*/

	// +Правое 1 крыло
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(4, -1.25, 0.1);
	glVertex3f(1, -1.25, 0.1);
	glVertex3f(1.5, -1.75, 0.1);
	glVertex3f(3.5, -1.75, 0.1);
	glEnd();

	// -Правое 1 крыло
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(4, -1.25, -0.1);
	glVertex3f(3.5, -1.75, -0.1);
	glVertex3f(1.5, -1.75, -0.1);
	glVertex3f(1, -1.25, -0.1);
	glEnd();

	// Левый бок
	glBegin(GL_POLYGON);
	glNormal3f(-4, -4, 1);
	glVertex3f(1.5, -1.75, -0.1);
	glVertex3f(1.5, -1.75, 0.1);
	glVertex3f(1, -1.25, 0.1);
	glVertex3f(1, -1.25, -0.1);
	glEnd();

	// Правый бок
	glBegin(GL_POLYGON);
	glNormal3f(4, -4, 1);
	glVertex3f(4, -1.25, 0.1);
	glVertex3f(3.5, -1.75, 0.1);
	glVertex3f(3.5, -1.75, -0.1);
	glVertex3f(4, -1.25, -0.1);
	glEnd();

	// Верх
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(4, -1.25, -0.1);
	glVertex3f(1, -1.25, -0.1);
	glVertex3f(1, -1.25, 0.1);
	glVertex3f(4, -1.25, 0.1);
	glEnd();

	// Низ
	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(3.5, -1.75, 0.1);
	glVertex3f(1.5, -1.75, 0.1);
	glVertex3f(1.5, -1.75, -0.1);
	glVertex3f(3.5, -1.75, -0.1);
	glEnd();
#pragma endregion
#pragma region 2 крылья
	// +Левое 2 крыло
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(-3.25, -1, 0.1);
	glVertex3f(-3.75, -0.5, 0.1);
	glVertex3f(-5, -0.5, 0.1);
	glVertex3f(-4.5, -1, 0.1);
	glEnd();

	// -Левое 2 крыло
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(-3.25, -1, -0.1);
	glVertex3f(-4.5, -1, -0.1);
	glVertex3f(-5, -0.5, -0.1);
	glVertex3f(-3.75, -0.5, -0.1);
	glEnd();

	// Левый бок
	glBegin(GL_POLYGON);
	glNormal3f(-4, -4, 1);
	glVertex3f(-5, -0.5, 0.1);
	glVertex3f(-5, -0.5, -0.1);
	glVertex3f(-4.5, -1, -0.1);
	glVertex3f(-4.5, -1, 0.1);
	glEnd();

	// Правый бок
	glBegin(GL_POLYGON);
	glNormal3f(4, 4, 1);
	glVertex3f(-3.25, -1, 0.1);
	glVertex3f(-3.25, -1, -0.1);
	glVertex3f(-3.75, -0.5, -0.1);
	glVertex3f(-3.75, -0.5, 0.1);
	glEnd();

	// Верх
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(-3.75, -0.5, 0.1);
	glVertex3f(-3.75, -0.5, -0.1);
	glVertex3f(-5, -0.5, -0.1);
	glVertex3f(-5, -0.5, 0.1);
	glEnd();

	// Низ
	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(-3.25, -1, -0.1);
	glVertex3f(-3.25, -1, 0.1);
	glVertex3f(-4.5, -1, 0.1);
	glVertex3f(-4.5, -1, -0.1);
	glEnd();

	/*==================================*/

	// +Правое 2 крыло
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(3.25, -1, 0.1);
	glVertex3f(4.5, -1, 0.1);
	glVertex3f(5, -0.5, 0.1);
	glVertex3f(3.75, -0.5, 0.1);
	glEnd();

	// -Правое 2 крыло
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(3.25, -1, -0.1);
	glVertex3f(3.75, -0.5, -0.1);
	glVertex3f(5, -0.5, -0.1);
	glVertex3f(4.5, -1, -0.1);
	glEnd();

	// Левый бок
	glBegin(GL_POLYGON);
	glNormal3f(-4, 4, 1);
	glVertex3f(3.25, -1, 0.1);
	glVertex3f(3.75, -0.5, 0.1);
	glVertex3f(3.75, -0.5, -0.1);
	glVertex3f(3.25, -1, -0.1);
	glEnd();

	// Правый бок
	glBegin(GL_POLYGON);
	glNormal3f(4, -4, 1);
	glVertex3f(5, -0.5, 0.1);
	glVertex3f(4.5, -1, 0.1);
	glVertex3f(4.5, -1, -0.1);
	glVertex3f(5, -0.5, -0.1);
	glEnd();

	// Верх
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(3.75, -0.5, -0.1);
	glVertex3f(3.75, -0.5, 0.1);
	glVertex3f(5, -0.5, 0.1);
	glVertex3f(5, -0.5, -0.1);
	glEnd();

	// Низ
	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(3.25, -1, 0.1);
	glVertex3f(3.25, -1, -0.1);
	glVertex3f(4.5, -1, -0.1);
	glVertex3f(4.5, -1, 0.1);
	glEnd();
#pragma endregion
#pragma region 3 крылья
	// +Левое 3 крыло
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(-3.75, -0.25, 0.1);
	glVertex3f(-3.75, 0.25, 0.1);
	glVertex3f(-6.5, 0.25, 0.1);
	glVertex3f(-6, -0.25, 0.1);
	glEnd();

	// -Левое 3 крыло
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(-3.75, -0.25, -0.1);
	glVertex3f(-6, -0.25, -0.1);
	glVertex3f(-6.5, 0.25, -0.1);
	glVertex3f(-3.75, 0.25, -0.1);
	glEnd();

	// Левый бок
	glBegin(GL_POLYGON);
	glNormal3f(-4, -4, 1);
	glVertex3f(-6.5, 0.25, 0.1);
	glVertex3f(-6.5, 0.25, -0.1);
	glVertex3f(-6, -0.25, -0.1);
	glVertex3f(-6, -0.25, 0.1);
	glEnd();

	// Правый бок
	glBegin(GL_POLYGON);
	glNormal3f(1, 0, 0);
	glVertex3f(-3.75, -0.25, 0.1);
	glVertex3f(-3.75, -0.25, -0.1);
	glVertex3f(-3.75, 0.25, -0.1);
	glVertex3f(-3.75, 0.25, 0.1);
	glEnd();

	// Верх
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(-3.75, 0.25, 0.1);
	glVertex3f(-3.75, 0.25, -0.1);
	glVertex3f(-6.5, 0.25, -0.1);
	glVertex3f(-6.5, 0.25, 0.1);
	glEnd();

	// Низ
	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(-3.75, -0.25, -0.1);
	glVertex3f(-3.75, -0.25, 0.1);
	glVertex3f(-6, -0.25, 0.1);
	glVertex3f(-6, -0.25, -0.1);
	glEnd();

	/*==================================*/

	// +Правое 3 крыло
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(3.75, -0.25, 0.1);
	glVertex3f(6, -0.25, 0.1);
	glVertex3f(6.5, 0.25, 0.1);
	glVertex3f(3.75, 0.25, 0.1);
	glEnd();

	// -Правое 3 крыло
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(3.75, -0.25, -0.1);
	glVertex3f(3.75, 0.25, -0.1);
	glVertex3f(6.5, 0.25, -0.1);
	glVertex3f(6, -0.25, -0.1);
	glEnd();

	// Левый бок
	glBegin(GL_POLYGON);
	glNormal3f(-1, 0, 0);
	glVertex3f(3.75, -0.25, -0.1);
	glVertex3f(3.75, -0.25, 0.1);
	glVertex3f(3.75, 0.25, 0.1);
	glVertex3f(3.75, 0.25, -0.1);
	glEnd();

	// Правый бок
	glBegin(GL_POLYGON);
	glNormal3f(4, -4, 1);
	glVertex3f(6.5, 0.25, -0.1);
	glVertex3f(6.5, 0.25, 0.1);
	glVertex3f(6, -0.25, 0.1);
	glVertex3f(6, -0.25, -0.1);
	glEnd();

	// Верх
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(3.75, 0.25, -0.1);
	glVertex3f(3.75, 0.25, 0.1);
	glVertex3f(6.5, 0.25, 0.1);
	glVertex3f(6.5, 0.25, -0.1);
	glEnd();

	// Низ
	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(3.75, -0.25, 0.1);
	glVertex3f(3.75, -0.25, -0.1);
	glVertex3f(6, -0.25, -0.1);
	glVertex3f(6, -0.25, 0.1);
	glEnd();
#pragma endregion
#pragma region 4 крылья
	// +Левое 4 крыло
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(-3.75, 0.5, 0.1);
	glVertex3f(-3.25, 1, 0.1);
	glVertex3f(-7.25, 1, 0.1);
	glVertex3f(-6.75, 0.5, 0.1);
	glEnd();

	// -Левое 4 крыло
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(-3.75, 0.5, -0.1);
	glVertex3f(-6.75, 0.5, -0.1);
	glVertex3f(-7.25, 1, -0.1);
	glVertex3f(-3.25, 1, -0.1);
	glEnd();

	// Левый бок
	glBegin(GL_POLYGON);
	glNormal3f(-4, -4, 0);
	glVertex3f(-7.25, 1, 0.1);
	glVertex3f(-7.25, 1, -0.1);
	glVertex3f(-6.75, 0.5, -0.1);
	glVertex3f(-6.75, 0.5, 0.1);
	glEnd();

	// Правый бок
	glBegin(GL_POLYGON);
	glNormal3f(4, -4, 0);
	glVertex3f(-3.75, 0.5, 0.1);
	glVertex3f(-3.75, 0.5, -0.1);
	glVertex3f(-3.25, 1, -0.1);
	glVertex3f(-3.25, 1, 0.1);
	glEnd();

	// Верх
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(-3.25, 1, 0.1);
	glVertex3f(-3.25, 1, -0.1);
	glVertex3f(-7.25, 1, -0.1);
	glVertex3f(-7.25, 1, 0.1);
	glEnd();

	// Низ
	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(-3.75, 0.5, -0.1);
	glVertex3f(-3.75, 0.5, 0.1);
	glVertex3f(-6.75, 0.5, 0.1);
	glVertex3f(-6.75, 0.5, -0.1);
	glEnd();

	/*==================================*/

	// +Правое 4 крыло
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(3.75, 0.5, 0.1);
	glVertex3f(6.75, 0.5, 0.1);
	glVertex3f(7.25, 1, 0.1);
	glVertex3f(3.25, 1, 0.1);
	glEnd();

	// -Правое 4 крыло
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(3.75, 0.5, -0.1);
	glVertex3f(3.25, 1, -0.1);
	glVertex3f(7.25, 1, -0.1);
	glVertex3f(6.75, 0.5, -0.1);
	glEnd();

	// Левый бок
	glBegin(GL_POLYGON);
	glNormal3f(-4, -4, 0);
	glVertex3f(3.75, 0.5, -0.1);
	glVertex3f(3.75, 0.5, 0.1);
	glVertex3f(3.25, 1, 0.1);
	glVertex3f(3.25, 1, -0.1);
	glEnd();

	// Правый бок
	glBegin(GL_POLYGON);
	glNormal3f(4, -4, 0);
	glVertex3f(7.25, 1, -0.1);
	glVertex3f(7.25, 1, 0.1);
	glVertex3f(6.75, 0.5, 0.1);
	glVertex3f(6.75, 0.5, -0.1);
	glEnd();

	// Верх
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(3.25, 1, -0.1);
	glVertex3f(3.25, 1, 0.1);
	glVertex3f(7.25, 1, 0.1);
	glVertex3f(7.25, 1, -0.1);
	glEnd();

	// Низ
	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(3.75, 0.5, 0.1);
	glVertex3f(3.75, 0.5, -0.1);
	glVertex3f(6.75, 0.5, -0.1);
	glVertex3f(6.75, 0.5, 0.1);
	glEnd();
#pragma endregion

	glPopMatrix(); // Восстанавливаем VM=Fwe
#pragma endregion
	glDisable(GL_LIGHTING); //Выключаем освещение
	if (axis == 1)
	{
		glBegin(GL_LINES);
		glColor3f(1, 0, 0); glVertex3f(-10, 0, 0); glVertex3f(10, 0, 0); // oX
		glColor3f(0, 1, 0); glVertex3f(0, -10, 0); glVertex3f(0, 10, 0); // oY
		glColor3f(0, 0, 1); glVertex3f(0, 0, -10); glVertex3f(0, 0, 10); // oZ
		glEnd();
	}
	glPopMatrix();
	glutSwapBuffers();
}

void myReshape(int width, int height)
{
	if (height == 0)
	{
		return;
	}
	glViewport((width - height) / 2, 0, height, height);
}

void myIdle()
{
	angle_o += step_o * direction;
	if (angle_o > 360.0) angle_o = 0;
	angle_l += step_l * direction;
	if (angle_l > 360.0) angle_l = 0;
	Sleep(10);
	glutPostRedisplay();
}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(1000, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("KAI");
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	glutKeyboardFunc(Keyboard);
	glutIdleFunc(myIdle);
	init();
	glutMainLoop();
}
