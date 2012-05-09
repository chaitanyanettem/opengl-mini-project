#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>

int i,j=0,k=0,l,n=0,m=0,turns=0;
int u=0,v,xc=200,yc=200,ba,bb,bc;

int a[100][4],q[12][12]={0};

void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,xc,0,yc);
	glMatrixMode(GL_MODELVIEW);
}

void nq();
void pq(int i);
GLuint texture[3]; 


void myKeyboardFunc( unsigned char key, int x, int y )
{
	if(key>=50 && key<=57)
		n=key-48;
}

/*void disp2(void)
{
top:	glClearColor(0,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin( GL_TRIANGLES );
	glColor3f( 1.0, 0.0, 0.0 );
	glVertex3f( 0.3, 1.0, 0.5 );
	glVertex3f( 2.7, 0.85, 0.0 );
	glVertex3f( 2.7, 1.15, 0.0 );
	glColor3f( 0.0, 0.0, 1.0 );
	glVertex3f(2.53, 0.71, 0.5 );
	glVertex3f(1.46, 2.86, 0.0 );
	glVertex3f(1.2, 2.71, 0.0 );

	glColor3f( 1.0, 1.0, 1.0 );
	glVertex3f(1.667, 2.79, 0.5);
	glVertex3f(0.337, 0.786, 0.0);
	glVertex3f(0.597, 0.636, 0.0);
	glColor3f(0,1,0);
	glEnd();
	char s[]="THE NQUEENS PROBLEM";
	glRasterPos2f(1.05,1.4);
	for(int i=0;i<19;i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s[i]);
	char msg[]="ENTER THE NUMBER OF QUEENS TO CONTINUE!";
	glColor3f(1,1,0);
	glRasterPos2f(0.85,0.7);
	for(int i=0;i<39;i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,msg[i]);
	char s1[]="CREATED BY: Deepak Bhagchandani & Chaitanya Nettem",g[]="UNDER THE GUIDANCE OF - Mr Kiran P";
	glColor3f(0,1,0);
	glRasterPos2f(0.05,0.2);
	for(int i=0;i<50;i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15,s1[i]);
	glRasterPos2f(0.0535,0.2);
	for(int i=0;i<50;i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15,s1[i]);
	glRasterPos2f(0.05,0.1);
	for(int i=0;i<34;i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15,g[i]);
	glRasterPos2f(0.0535,0.1);
	for(int i=0;i<34;i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15,g[i]);
	glFlush();
	if(n==0)
		goto top;
}
*/
GLuint LoadTexture( const char * filename, int width, int height )
{
    GLuint texture;
    unsigned char * data;
    FILE * file;
    file = fopen( filename, "r" );
    if ( file == NULL ) 
		{
			return 0;
			printf("error");
	}
	printf("no error");
    data = (unsigned char *)malloc( width * height * 3 );
    fread( data, width * height * 3, 1, file );
    fclose( file );
    glGenTextures( 1, &texture ); 
    glBindTexture( GL_TEXTURE_2D, texture ); 
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL ); 
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0,GL_RGB, GL_UNSIGNED_BYTE, data);
    free( data ); 
    return texture; 
}
void FreeTexture( GLuint texture )
{
  glDeleteTextures( 1, &texture );
}
void disp()
{
//	disp2();
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,0,0);
	glLoadIdentity();
    glEnable( GL_TEXTURE_2D );
	
	int r=0,w=0;
	glBegin(GL_QUADS);
	ba=xc/20;
	bb=ba*2;
	bc=ba*3;
	for(l=0;l<n;l++)
		{
			k=k%2;
			for(i=0;i<n;i+=2)
				{
					if(k==1&&i>=n-1)break;
					if(w%2==1&&r==0)
						{
							a[m][0]=ba+(bb*(i+k-1));
							a[m][1]=ba+(bb*j);
							a[m][2]=ba+(bb*(i+k));
							a[m][3]=bc+(bb*j);
							printf("%d\n%d\n%d\n%d\n\n",a[m][0],a[m][1],a[m][2],a[m][3]);
							m++;
							r++;
						}
					a[m][0]=ba+(bb*(i+k));
					a[m][1]=ba+(bb*j);
					a[m][2]=ba+(bb*(i+1+k));
					a[m][3]=bc+(bb*j);
					printf("%d\n%d\n%d\n%d\n\n",a[m][0],a[m][1],a[m][2],a[m][3]);
					m++;
					r++;
					if(r<n)
					{
					a[m][0]=ba+(bb*(i+1+k));
					a[m][1]=ba+(bb*j);
					a[m][2]=ba+(bb*(i+2+k));
					a[m][3]=bc+(bb*j);
					printf("%d\n%d\n%d\n%d\n\n",a[m][0],a[m][1],a[m][2],a[m][3]);
					m++;
					r++;
					}

					glVertex2i(ba+(bb*(i+k)),ba+(bb*j)); 		//for creating boxes of chessboard
					glVertex2i(ba+(bb*(i+k)),bc+(bb*j));
					glVertex2i(ba+(bb*(i+1+k)),bc+(bb*j));
					glVertex2i(ba+(bb*(i+1+k)),ba+(bb*j));
					
					
				}
			k++;
			j++;
			r=0;
			w++;
	}
	glEnd();
	--j;
	--k;
	glBegin(GL_LINE_LOOP); //for the outline box of the chessboard. points start at bottom left corner and go clockwise
	glVertex2i(ba,ba);
	glVertex2i(ba,bc+(bb*j));
	glVertex2i(ba+(bb*(i-1+k)),bc+(bb*j));
	glVertex2i(ba+(bb*(i-1+k)),ba);

	glEnd();
	glBegin(GL_LINE_LOOP); 		//For the finish box
	glVertex2i(bb*(i-1+k)/2-ba,yc/20-8);
	glVertex2i(bb*(i-1+k)/2-ba,yc/20-2);
	glVertex2i(bb*(i-1+k)/2-ba+bc,yc/20-2);
	glVertex2i(bb*(i-1+k)/2-ba+bc,yc/20-8);
	glEnd();		
	glRasterPos2f(bb*(i-1+k)/2-ba+4,ba/2.5);
	

	//*********************************************************************************************
	/***************************************OLD CODE***********************************************
	for(l=0;l<n;l++)
		{
			k=k%2;
			for(i=0;i<n;i+=2)
				{
					if(k==1&&i>=n-1)break;
					if(w%2==1&&r==0)
						{
							a[m][0]=50+(100*(i+k-1));
							a[m][1]=50+(100*j);
							a[m][2]=50+(100*(i+k));
							a[m][3]=150+(100*j);
							printf("%d\n%d\n%d\n%d\n\n",a[m][0],a[m][1],a[m][2],a[m][3]);
							m++;
							r++;
						}
					a[m][0]=50+(100*(i+k));
					a[m][1]=50+(100*j);
					a[m][2]=50+(100*(i+1+k));
					a[m][3]=150+(100*j);
					printf("%d\n%d\n%d\n%d\n\n",a[m][0],a[m][1],a[m][2],a[m][3]);
					m++;
					r++;
					if(r<n)
					{
					a[m][0]=50+(100*(i+1+k));
					a[m][1]=50+(100*j);
					a[m][2]=50+(100*(i+2+k));
					a[m][3]=150+(100*j);
					printf("%d\n%d\n%d\n%d\n\n",a[m][0],a[m][1],a[m][2],a[m][3]);
					m++;
					r++;
					}

					
					printf("%d,%d\n",50+(100*(i+k)),50+(100*j));
					printf("%d,%d\n",50+(100*(i+k)),150+(100*j));
					printf("%d,%d\n",50+(100*(i+1+k)),150+(100*j));
					printf("%d,%d\n",50+(100*(i+1+k)),50+(100*j));
					
					
					glVertex2i(50+(100*(i+k)),50+(100*j)); 		//for creating boxes of chessboard
					glVertex2i(50+(100*(i+k)),150+(100*j));
					glVertex2i(50+(100*(i+1+k)),150+(100*j));
					glVertex2i(50+(100*(i+1+k)),50+(100*j));
					
					
				}
			k++;
			j++;
			r=0;
			w++;
	}
	glEnd();
	--j;
	--k;
	glBegin(GL_LINE_LOOP); //for the outline box of the chessboard. points start at bottom left corner and go clockwise
	glVertex2i(50,50);
	glVertex2i(50,150+(100*j));
	glVertex2i(150+(100*(i-1+k)),150+(100*j));
	glVertex2i(50+(100*(i-1+k)),50);

	glEnd();
	glBegin(GL_LINE_LOOP); 		//For the finish box
	glVertex2i(425,10);
	glVertex2i(425,40);
	glVertex2i(575,40);
	glVertex2i(575,10);
	glEnd();		
	glRasterPos2i(460,18);
	********************************************************************************/
	//*******************************************************************************

	
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'F');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,' ');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'I');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,' ');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'N');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,' ');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'I');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,' ');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'S');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,' ');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'H');
	glFlush();
	glRasterPos2i(10000,10000);
	glReadBuffer (GL_BACK); 
	glDrawBuffer (GL_FRONT); 
	glutSwapBuffers();
}
void mouse1(int b,int s,int x,int y)
{
	if(b==GLUT_RIGHT_BUTTON && s==GLUT_DOWN)
		exit(0);
	if(b==GLUT_LEFT_BUTTON && s==GLUT_DOWN &&turns>n)
	{		
		y=yc-y;
		if((x>=bb*(i-1+k)/2-ba && x<= bb*(i-1+k)/2-ba+bc) && (y>=yc/20-8 && y<=yc/20-2))
		{			
			printf("nq called");
			nq();
		}
	}
	if(b==GLUT_LEFT_BUTTON && s==GLUT_DOWN )
	{
		
		y=yc-y;
		int i,x1,x2,y1,y2,eq;
		for(i=0;i<(n*n);i++)
		{
			if((x>=a[i][0] && x<=a[i][2]) && (y>=a[i][1] && y<=a[i][3]))
			{
				x1=a[i][0];
				x2=a[i][2];
				y1=a[i][1];
				y2=a[i][3];
				pq(i);
				break;
			}
		}
		if((x>=a[i][0] && x<=a[i][2]) && (y>=a[i][1] && y<=a[i][3]))
		{ 
			if(q[u][v]==1&&turns<=n)
			{
				texture[0] = LoadTexture( "1.bmp", 256, 256 );
				glBindTexture( GL_TEXTURE_2D, texture[0] );
				printf("tm");
				glBegin (GL_QUADS);
				glTexCoord2d(0.0,0.0); glVertex2d(4000,4000); //with our vertices we have to assign a texcoord
				glTexCoord2d(1.0,0.0); glVertex2d(4100,4000); //so that our texture has some points to draw to
				glTexCoord2d(1.0,1.0); glVertex2d(4100,4100);
				glTexCoord2d(0.0,1.0); glVertex2d(4000,4100);
				glEnd();
				glReadBuffer (GL_BACK); 
				glDrawBuffer (GL_FRONT); 
				glCopyPixels (x1,y1,100,100,GL_COLOR);
				glFlush();
				FreeTexture(texture[0]);
				if(u%2==0)
					eq=0;
				else
					eq=1;
				if(n%2==1)
					eq=0;
				if(((n*u)+v+eq)%2==0)
				{
					texture[0] = LoadTexture( "1.bmp", 256, 256 );
					glBindTexture( GL_TEXTURE_2D, texture[0] );
					printf("tm");
					glBegin (GL_QUADS);
					glTexCoord2d(0.0,0.0); glVertex2d(x1,y1); //with our vertices we have to assign a texcoord
					glTexCoord2d(1.0,0.0); glVertex2d(x2,y1); //so that our texture has some points to draw to
					glTexCoord2d(1.0,1.0); glVertex2d(x2,y2);
					glTexCoord2d(0.0,1.0); glVertex2d(x1,y2);
					glEnd();
					glReadBuffer (GL_BACK); 
					glDrawBuffer (GL_FRONT); 
					glCopyPixels (x1,y1,10,10,GL_COLOR);
					glFlush();
					FreeTexture(texture[0]);
				}
				else
				{
					texture[1] = LoadTexture( "2.bmp", 256, 256 );
					glBindTexture( GL_TEXTURE_2D, texture[1] );
					printf("tm");
					glBegin (GL_QUADS);
					glTexCoord2d(0.0,0.0); glVertex2d(x1,y1); //with our vertices we have to assign a texcoord
					glTexCoord2d(1.0,0.0); glVertex2d(x2,y1); //so that our texture has some points to draw to
					glTexCoord2d(1.0,1.0); glVertex2d(x2,y2);
					glTexCoord2d(0.0,1.0); glVertex2d(x1,y2);
					glEnd();
					glReadBuffer (GL_BACK); 
					glDrawBuffer (GL_FRONT); 
					glCopyPixels (x1,y1,100,100,GL_COLOR);
					glFlush();
					FreeTexture(texture[0]);
				}
	
			}
			else if(turns<=n)
			{
				if(u%2==0)
					eq=0;
				else
					eq=1;
				if(n%2==1)
					eq=0;
				if(((n*u)+v+eq)%2==0)
				{
					glColor3f(0,0,0);
					glBegin (GL_QUADS);
					glVertex2d(x1,y1); //with our vertices we have to assign a texcoord
					glVertex2d(x2,y1); //so that our texture has some points to draw to
					glVertex2d(x2,y2);
					glVertex2d(x1,y2);
					glEnd();
					glFlush();
				}
				else
				{
					glColor3f(1,1,1);
					glBegin (GL_QUADS);
					glVertex2d(x1,y1); //with our vertices we have to assign a texcoord
					glVertex2d(x2,y1); //so that our texture has some points to draw to
					glVertex2d(x2,y2);
					glVertex2d(x1,y2);
					glEnd();
					glColor3f(0,0,0);
					glBegin(GL_LINE_STRIP);
					glVertex2f(x1,y1);
					glVertex2f(x2,y1);
					glVertex2f(x2,y2);
					glVertex2f(x1,y2);
					glEnd();
					glFlush();
				}	
			}
		}
	}
}

void pq(int i)
{
	v=i;
					u=0;
					while(v>=n)
						{
							v=v-n;
							++u;
						}
					if(q[u][v]!=1)
						{
							turns++;
					        q[u][v]=1;
					}
					else
					{
						turns--;
						q[u][v]=0;
					}
					printf("%d\n%d\n%d\n",u,v,i);
				if(turns>n)
					q[u][v]=0;	
}
void nq()
{
	int u1,u2,v1,v2;
	int x1,x2,y1,y2,in,eq,lp,lp1;
	for(int u1=0;u1<n;u1++)
	{
		for(int v1=0;v1<n;v1++)
		{
			if(q[u1][v1]==1)
			{
				for(int u2=0;u2<n;u2++)
				{
					for(int v2=0;v2<n;v2++)
					{
						if(u1==u2&&v1==v2)
							continue;
						if(q[u2][v2]==1)
						{
							printf("%d\n%d\n%d\n%d\n",u1,v1,u2,v2);
							if(u1==u2 || v1==v2 ||(abs(u1-u2)==abs(v1-v2)))
							{
								if(u1<=u2&&v1==v2)
								{
									while(u1<=u2)
									{
										in=((n*u1)+v1);
										x1=a[in][0];
										x2=a[in][2];
										y1=a[in][1];
										y2=a[in][3];
										texture[2] = LoadTexture( "3.bmp", 256, 256 );
										glBindTexture( GL_TEXTURE_2D, texture[2] );
										printf("tm");
										glBegin (GL_QUADS);
										glTexCoord2d(0.0,0.0); glVertex2d(x1,y1); //with our vertices we have to assign a texcoord
										glTexCoord2d(1.0,0.0); glVertex2d(x2,y1); //so that our texture has some points to draw to
										glTexCoord2d(1.0,1.0); glVertex2d(x2,y2);
										glTexCoord2d(0.0,1.0); glVertex2d(x1,y2);
										glEnd();
										glReadBuffer (GL_BACK); 
										glDrawBuffer (GL_FRONT); 
										glCopyPixels (x1,y1,100,100,GL_COLOR);
										glFlush();
										FreeTexture(texture[2]);
										printf("%d\n%d\n%d\n%d\n",x1,y1,x2,y2);
										for(lp=0;lp<=10000;lp++)
											for(lp1=0;lp1<=10000;lp1++);
										glColor3f(0,0,1);
										glBegin (GL_QUADS);
										glVertex2d(x1,y1); //with our vertices we have to assign a texcoord
										glVertex2d(x2,y1); //so that our texture has some points to draw to
										glVertex2d(x2,y2);
										glVertex2d(x1,y2);
										glEnd();
										glColor3f(0,0,0);
										glBegin(GL_LINE_STRIP);
										glVertex2f(x1,y1);
										glVertex2f(x2,y1);
										glVertex2f(x2,y2);
										glVertex2f(x1,y2);
										glEnd();
										glFlush();
												
										u1++;
									}
								}
								else if(u1==u2&&v1<=v2)
								{
									while(v1<=v2)
									{
										in=((n*u1)+v1);
										x1=a[in][0];
										x2=a[in][2];
										y1=a[in][1];
										y2=a[in][3];
										texture[2] = LoadTexture( "3.bmp", 256, 256 );
										glBindTexture( GL_TEXTURE_2D, texture[2] );
										printf("tm");
										glBegin (GL_QUADS);
										glTexCoord2d(0.0,0.0); glVertex2d(x1,y1); //with our vertices we have to assign a texcoord
										glTexCoord2d(1.0,0.0); glVertex2d(x2,y1); //so that our texture has some points to draw to
										glTexCoord2d(1.0,1.0); glVertex2d(x2,y2);
										glTexCoord2d(0.0,1.0); glVertex2d(x1,y2);
										glEnd();
										glReadBuffer (GL_BACK); 
										glDrawBuffer (GL_FRONT); 
										glCopyPixels (x1,y1,100,100,GL_COLOR);
										glFlush();
										FreeTexture(texture[2]);
										printf("%d\n%d\n%d\n%d\n",x1,y1,x2,y2);
										for(lp=0;lp<=10000;lp++)
											for(lp1=0;lp1<=10000;lp1++);
										glColor3f(0,0,1);
										glBegin (GL_QUADS);
										glVertex2d(x1,y1); //with our vertices we have to assign a texcoord
										glVertex2d(x2,y1); //so that our texture has some points to draw to
										glVertex2d(x2,y2);
										glVertex2d(x1,y2);
										glEnd();
										glColor3f(0,0,0);
										glBegin(GL_LINE_STRIP);
										glVertex2f(x1,y1);
										glVertex2f(x2,y1);
										glVertex2f(x2,y2);
										glVertex2f(x1,y2);
										glEnd();
										glFlush();
										v1++;	
									}
								}
								else if(u1<=u2&&v1<=v2)
								{
									while(u1<=u2)
									{
										in=((n*u1)+v1);
										x1=a[in][0];
										x2=a[in][2];
										y1=a[in][1];
										y2=a[in][3];
										texture[2] = LoadTexture( "3.bmp", 256, 256 );
										glBindTexture( GL_TEXTURE_2D, texture[2] );
										printf("tm");
										glBegin (GL_QUADS);
										glTexCoord2d(0.0,0.0); glVertex2d(x1,y1); //with our vertices we have to assign a texcoord
										glTexCoord2d(1.0,0.0); glVertex2d(x2,y1); //so that our texture has some points to draw to
										glTexCoord2d(1.0,1.0); glVertex2d(x2,y2);
										glTexCoord2d(0.0,1.0); glVertex2d(x1,y2);
										glEnd();
										glReadBuffer (GL_BACK); 
										glDrawBuffer (GL_FRONT); 
										glCopyPixels (x1,y1,100,100,GL_COLOR);
										glFlush();
										FreeTexture(texture[2]);
										printf("%d\n%d\n%d\n%d\n",x1,y1,x2,y2);
										for(lp=0;lp<=10000;lp++)
											for(lp1=0;lp1<=10000;lp1++);
										glColor3f(0,0,1);
										glBegin (GL_QUADS);
										glVertex2d(x1,y1); //with our vertices we have to assign a texcoord
										glVertex2d(x2,y1); //so that our texture has some points to draw to
										glVertex2d(x2,y2);
										glVertex2d(x1,y2);
										glEnd();
										glColor3f(0,0,0);
										glBegin(GL_LINE_STRIP);
										glVertex2f(x1,y1);
										glVertex2f(x2,y1);
										glVertex2f(x2,y2);
										glVertex2f(x1,y2);
										glEnd();
										glFlush();	
										u1++;
										v1++;
									}
								}
								else if(u1<=u2&&v1>=v2)
								{
									while(u1<=u2)
									{	
										in=((n*u1)+v1);
										x1=a[in][0];
										x2=a[in][2];
										y1=a[in][1];
										y2=a[in][3];
										texture[2] = LoadTexture( "3.bmp", 256, 256 );
										glBindTexture( GL_TEXTURE_2D, texture[2] );
										printf("tm");
										glBegin (GL_QUADS);
										glTexCoord2d(0.0,0.0); glVertex2d(x1,y1); //with our vertices we have to assign a texcoord
										glTexCoord2d(1.0,0.0); glVertex2d(x2,y1); //so that our texture has some points to draw to
										glTexCoord2d(1.0,1.0); glVertex2d(x2,y2);
										glTexCoord2d(0.0,1.0); glVertex2d(x1,y2);
										glEnd();
										glReadBuffer (GL_BACK); 
										glDrawBuffer (GL_FRONT); 
										glCopyPixels (x1,y1,100,100,GL_COLOR);
										glFlush();
										FreeTexture(texture[2]);
										printf("%d\n%d\n%d\n%d\n",x1,y1,x2,y2);
										for(lp=0;lp<=10000;lp++)
											for(lp1=0;lp1<=10000;lp1++);
										glColor3f(0,0,1);
										glBegin (GL_QUADS);
										glVertex2d(x1,y1); //with our vertices we have to assign a texcoord
										glVertex2d(x2,y1); //so that our texture has some points to draw to
										glVertex2d(x2,y2);
										glVertex2d(x1,y2);
										glEnd();
										glColor3f(0,0,0);
										glBegin(GL_LINE_STRIP);
										glVertex2f(x1,y1);
										glVertex2f(x2,y1);
										glVertex2f(x2,y2);
										glVertex2f(x1,y2);
										glEnd();
										glFlush();	
										u1++;
										v1--;
									}
								}
								texture[2] = LoadTexture( "3.bmp", 256, 256 );
								glBindTexture( GL_TEXTURE_2D, texture[2] );
								printf("tm");
								glBegin (GL_QUADS);
								glTexCoord2d(0.0,0.0); glVertex2d(x1,y1); //with our vertices we have to assign a texcoord
								glTexCoord2d(1.0,0.0); glVertex2d(x2,y1); //so that our texture has some points to draw to
								glTexCoord2d(1.0,1.0); glVertex2d(x2,y2);
								glTexCoord2d(0.0,1.0); glVertex2d(x1,y2);
								glEnd();
								glReadBuffer (GL_BACK); 
								glDrawBuffer (GL_FRONT); 
								glCopyPixels (x1,y1,100,100,GL_COLOR);
								glFlush();
								FreeTexture(texture[2]);
								glColor3f(0,0,0);
								glBegin(GL_LINE_STRIP);
								glVertex2f(x1,y1);
								glVertex2f(x2,y1);
								glVertex2f(x2,y2);
								glVertex2f(x1,y2);
								glEnd();
								glFlush();
								glColor3f(1,0,0);
								glRasterPos2i(800,970);
								glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'Y');
								glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'O');
								glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'U');
								glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,' ');
								glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'L');
								glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'O');
								glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'S');
								glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'E');
								glFlush();
								return;
							}
						}
					}
				}
			}
		}
	}
	printf("reached");
	glRasterPos2i(800,970);
	glColor3f(1,0,0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'Y');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'O');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'U');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,' ');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'W');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'I');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'N');
	glFlush();
	return;
}
void main(int argc, char* argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(1000,1000);
	glutCreateWindow("1");
	myinit();
	printf("enter the dimension");
	scanf("%d",&n);
	//glutFullScreen();
	glutDisplayFunc(disp);
	glutKeyboardFunc( myKeyboardFunc );
	glutMouseFunc(mouse1);
	glutMainLoop();
}
